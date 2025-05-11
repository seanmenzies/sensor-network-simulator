#pragma once
#include <iostream>

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
    static std::string convertToTempUnit(std::string s_CelsiusTemp);

    static short getDecimalPlaces() {return decimalPlaces;};
    static void setDecimalPlaces(short newPlaces) {decimalPlaces = newPlaces;};

private:
    static TemperatureUnit temperatureUnit;
    static short decimalPlaces;
};