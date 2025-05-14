#pragma once
#include "../sensors/SensorNodeBase.h"
#include <map>
#include <string>
#include <memory>

class SensorManager {
public:
    // publicly available and no explit init/shut down operation. May not scale? 
    static SensorManager* get() {
        static SensorManager instance;
        return &instance;
    }

    void addNewSensor(std::shared_ptr<SensorNodeBase> INSensor) {
        if (!INSensor.get()) return;
        connectedSensors.emplace(INSensor->getID(), INSensor);
    };
private:
    std::map<std::string, std::shared_ptr<SensorNodeBase>> connectedSensors;
};