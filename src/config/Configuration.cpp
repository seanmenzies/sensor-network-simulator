#include "Configuration.h"
#include <sstream>

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
    if (getTemperatureUnit() == TemperatureUnit::Celsius) return s_CelsiusTemp;
    float f_Temp = convertToTempUnit(std::stof(s_CelsiusTemp));
    // use string stream to return stringified value to user-defined decimal places
    std::ostringstream ss;
    ss.precision(Configuration::getDecimalPlaces());
    // without std:::fixed, precision uses *total* digits, not just those after the decimal place
    ss << std::fixed << std::to_string(f_Temp);
    return ss.str();
}
