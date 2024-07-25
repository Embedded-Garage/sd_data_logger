#include "DataLogger.h"
#include <TimeLib.h>

DataLogger::DataLogger(String &&sensorName, String &&path) : sensorName(sensorName), path(path)
{
}

bool DataLogger::init()
{
    
}

void DataLogger::logData(const double value)
{
    String line = String(now()) + ";" + String(value, 4);
    saveData(line);
}

void DataLogger::logData(const int value)
{
    String line = String(now()) + ";" + String(value);
    saveData(line);
}

void DataLogger::saveData(String &data)
{
    // save data to file
    Serial.print(data + "\r\n");
}
