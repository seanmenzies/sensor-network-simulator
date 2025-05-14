#pragma once
#include "ConsumerBase.h"
#include "../sensors/SensorNodeBase.h"
#include <fstream>
#include <string>
#include <optional>
#include <atomic>
#include <thread>
#include <queue>
#include <mutex>
#include <algorithm>

struct fLoggingConfig
{
    std::string logPath = std::string("");
    int logFrequency;
    int maxLogDays;
    int maxFileSize;
    bool rotateDaily;
    std::string fileFormat;
    std::vector<std::string> disabledSensors;
    bool compressOldLogs;
    bool asyncWrite;

    fLoggingConfig()
    {
        std::string logPath = std::string("");
        int logFrequency = 0;
        int maxLogDays = 0;
        int maxFileSize = 0;
        bool rotateDaily = false;
        std::string fileFormat = ".json";
        std::vector<std::string> disabledSensors = {};
        bool compressOldLogs = false;
        bool asyncWrite = false;
    };

    fLoggingConfig(std::optional<nlohmann::json> INConfigData)
    {
        if (INConfigData)
        {
            nlohmann::json j(*INConfigData);
            logPath = j["log_path"];
            logFrequency = j["log_frequency"];
            maxLogDays = j["max_log_days"];
            maxFileSize = j["max_log_size_per_file_MB"];
            rotateDaily = j["rotate_daily"] == 0 ? false : true;
            fileFormat = j["file_format"];
            disabledSensors.empty();
            std::stringstream ss(j["disabled_sensors"].get<std::string>());
            std::string item;
            while (std::getline(ss, item, ',')) {
                // trim whitespace
                trim(item);
                disabledSensors.push_back(item);
            }         
            compressOldLogs = j["compress_old_logs"] == 0 ? false : true;
            asyncWrite = j["async_write"] == 0 ? false : true;
        }
    }

    inline void trim(std::string& s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
        }));
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }
};

class LoggerConsumer : public ConsumerBase {
public:
    LoggerConsumer() { onConfigChanged(); }
    ~LoggerConsumer();
    void handleMessage(const std::string& message) override;
    std::optional<nlohmann::json> parseSensorMessage(const std::string& raw) override;
    void setLogRoot(std::string INPath) {LOG_DIR = INPath;};
    void onConfigChanged();

private:
    fLoggingConfig loggingConfig;
    std::mutex configMutex;
    std::unordered_map<std::string, std::queue<std::string>> logQueues;
    std::unordered_map<std::string, std::thread> workerThreads;
    std::unordered_map<std::string, std::mutex> queueMutexes;
    std::atomic<bool> running = true;
    std::string LOG_DIR;
};