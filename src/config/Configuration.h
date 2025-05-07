#pragma once

enum class TemperatureUnit {
    Celsius,
    Fahrenheit
};

class Configuration {
public:
    // the codebase uses celcius as a base unit, and converts from there
    static void setTemperatureUnit(TemperatureUnit unit);
    static TemperatureUnit getTemperatureUnit() {return temperatureUnit;};
    static float convertToTempUnit(float CelsiusTemp);

private:
    static TemperatureUnit temperatureUnit;
};