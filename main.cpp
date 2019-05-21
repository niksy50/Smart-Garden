#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include "TempHumLightState.h"
#include "Sensors.h"

SENSORS sensor;
SensorData sensorData;

void setup() {
  Serial.begin(9600);
  sensor.DHT_init();
  sensor.Soil_init();
  sensor.BH1750_init();

  delay(100); 
}

void loop() {
  State state = READ_SENSORS;
    
   for(;;) {
    switch(state) {
      case READ_SERIAL:
        delay(500);
        state = GOTO_SLEEP;
        break;
      case GOTO_SLEEP:
        Serial.println(F("Going to sleep"));
        delay(100);
        LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
        delay(100); // give him some time to wake up from sleep
        state = READ_SENSORS;
        break;
      case READ_SENSORS:
        sensorData.temp = sensor.readTemp();
        sensorData.hum = sensor.readHum();
        sensorData.soil = sensor.readSoil();
        sensorData.lightLevel = sensor.readLight();
        Serial.print(sensorData.hum);
        Serial.print(" % - humidityy\n");
        Serial.print(sensorData.temp);
        Serial.print(" °C - temperaturee\n");
        if(sensorData.soil==0 & sensorData.lightLevel==0 ){   
            Serial.print("Water is needed!!\n"); 
        }
        else { 
            Serial.print("No water needed..\n"); 
        }
        delay(100); 
        state = READ_SERIAL;
        break;
    }
  }
}
