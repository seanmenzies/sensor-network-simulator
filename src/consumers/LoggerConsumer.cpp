#include "LoggerConsumer.h"
#include "../common/NetworkUtils.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

/** consumers receive and handle incoming messages from sensors 
  they take data and: log to a file, monitor for alerts etc. 
  The logger consumer is only responsible for logging incoming
  data then parsing it and sending it to the message bus where other
  consumers may **/

void LoggerConsumer::handleMessage(const std::string &message)
{
    // parse message then handle the actual logging on a dedicated thread 
    // saved by sensor id (one log per sensor). Ideally we'd handle the parsing
    // on another thread too but we need the id, but data can only be passed as 
    // raw strings. logQueues is written and read by two threads with an id specific 
    // mutex used to avoid race conditions on logQueues
    if (auto parsed = parseSensorMessage(message)) {
        std::string id = (*parsed)["sensor_id"];
        // ensure logs for sensor hasn't been disabled
        if (std::find(loggingConfig.disabledSensors.begin(), loggingConfig.disabledSensors.end(), 
        loggingConfig.disabledSensors) != loggingConfig.disabledSensors.end()) return;

        {
            // isolated scope so the mutex is locked for the minimal amount of time
            // (prevent deadlocks). Fact of the day: if the thread is locked out, it gets in
            // a queue and is let in by the OS thread scheduler, not by C++
            std::lock_guard<std::mutex> lock(queueMutexes[id]);
            logQueues[id].push(message);
        }

        if (workerThreads.find(id) == workerThreads.end()) {
            running = true;
            workerThreads[id] = std::thread([this, id]() {
                while (running) {
                    std::string msg;
                    {
                        std::lock_guard<std::mutex> lock(queueMutexes[id]);
                        if (!logQueues[id].empty()) {
                            msg = logQueues[id].front();
                            logQueues[id].pop();
                        }
                    }

                    if (!msg.empty()) {
                        // write to file
                        auto parsed = parseSensorMessage(msg);
                        std::string filename = LOG_DIR + (*parsed)["sensor_id"].get<std::string>() + ".log";
                        // compare file size to config
                        std::uintmax_t sizeInBytes = fs::file_size(filename);
                        float sizeInMB = static_cast<float>(sizeInBytes) / (1024 * 1024);
                        if (sizeInMB >= loggingConfig.maxFileSize)
                        {
                            // check for log rotation settings
                            if (!loggingConfig.rotateDaily) 
                            {
                                // throw error and disable sensor if log rotation false
                                std::cerr << "[Logger] Max log size reached. Enable log rotation to recycle logs." << std::endl;
                                loggingConfig.disabledSensors.push_back(id);
                                return;
                            }
                            // archive old files if max log days > 0
                        }
                        std::ofstream outFile(filename, std::ios::app);
                        outFile << parsed->dump() << "\n";
                    } else {
                        std::this_thread::sleep_for(std::chrono::milliseconds(loggingConfig.logFrequency));
                    }
                }
            });
        }
    }
}

std::optional<nlohmann::json> LoggerConsumer::parseSensorMessage(const std::string &raw)
{
    try {
        auto j = nlohmann::json::parse(raw);
        return j;
    } catch (const std::exception& e) {
        std::cerr << "[Logger] Parse failed: " << e.what() << std::endl;
        return std::nullopt;
    }

    return std::nullopt;
}

void LoggerConsumer::onConfigChanged()
{
    std::ifstream file("../config/loggingConfig.json");
    if (!file) {
        std::cerr << "[LoggingConsumer] Failed to open: config file" << std::endl;
        return;
    }

    std::lock_guard<std::mutex> lock(configMutex);
    nlohmann::json parsed;
    parsed << file;
    loggingConfig = fLoggingConfig(parsed);
}

LoggerConsumer::~LoggerConsumer()
{
    running = false;
    for (auto& [id, thread] : workerThreads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

