#include "Configuration.h"
#include <sstream>

TemperatureUnit Configuration::temperatureUnit = TemperatureUnit::Celsius;
short Configuration::decimalPlaces = 2;

float Configuration::convertToTempUnit(float CelsiusTemp)
{
    if (temperatureUnit != TemperatureUnit::Celsius)
    {
        return CelsiusTemp * 9.0f / 5.0f + 32.0f;
    }
    return CelsiusTemp;
}

std::string Configuration::convertToTempUnit(std::string s_CelsiusTemp)
{
    if (Configuration::getTemperatureUnit() == TemperatureUnit::Celsius) return s_CelsiusTemp;
    float f_Temp = Configuration::convertToTempUnit(std::stof(s_CelsiusTemp));
    // use string stream to return stringified value to user-defined decimal places
    std::ostringstream ss;
    ss.precision(Configuration::getDecimalPlaces());
    // without std:::fixed, precision uses *total* digits, not just those after the decimal place
    ss << std::fixed << f_Temp;
    return ss.str();
}
