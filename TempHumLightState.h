#ifndef TempHumLightState_h
#define TempHumLightState_h

#include <avr/pgmspace.h>
#include <LowPower.h>

struct SensorData {
    float temp;
    float hum;
    bool soil;
    bool lightLevel;
};

typedef enum {
  READ_SERIAL,
  GOTO_SLEEP,
  READ_SENSORS,
} State;

#endif
