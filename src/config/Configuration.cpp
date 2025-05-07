#include "Configuration.h"

float Configuration::convertToTempUnit(float CelsiusTemp)
{
    if (temperatureUnit != TemperatureUnit::Celsius)
    {
        return CelsiusTemp * 9.0f / 5.0f + 32.0f;
    }
    return CelsiusTemp;
}
