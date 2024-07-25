#pragma once

#include <Arduino.h>

class DataLogger
{
public:
    DataLogger(String &&sensorName, String &&path = "/pomiary/");

public:
    bool init();
    void logData(const double value);
    void logData(const int value);

private:
    void saveData(String &data);

private:
    String sensorName = "";
    String path = "";
};