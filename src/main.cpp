#include <Arduino.h>

#include <DataLogger.h>
#include <FileManager.h>

#define PIN_5V_EN 16

DataLogger temperatureLogger("temperature");
FileManager fileManager;

void setup()
{
  Serial.begin(921600);

  // init peripherals
  pinMode(PIN_5V_EN, OUTPUT);
  digitalWrite(PIN_5V_EN, HIGH);

  delay(50);

  Serial.print("File manager init ");
  if (fileManager.init())
  {
    Serial.println("ok");
  }
  else
  {
    Serial.println("ERROR");
  }

  Serial.print("temperature logger init ");
  if (temperatureLogger.init())
  {
    Serial.println("ok");
  }
  else
  {
    Serial.println("ERROR");
  }
}

void loop()
{
  static int licznik = 0;
  temperatureLogger.logData(licznik);
  delay(1000);

  licznik++;
}
