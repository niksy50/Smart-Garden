#ifndef Sensors_h
#define Sensors_h
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <BH1750.h>
#define DHTPIN 3
#define DHTPIN_VCC 4
#define SOILPIN 8
#define DHTTYPE DHT11

class SENSORS {
public:
        SENSORS();
        ~SENSORS();
        void DHT_init();
        void BH1750_init();
        void Soil_init();
        float readTemp();
        float readHum();
        bool readSoil();
        bool readLight();
        bool read_light();
        void printTemp(float );
        void printHum(float );
        void printSoil(bool );
};

#endif
