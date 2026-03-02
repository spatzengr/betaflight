// mock_gyro.c
// Mock implementation for gyro.c symbols used in unit tests
#include "sensors/gyro.h"
#include <stdbool.h>
#include <stdint.h>

// Mock global variables
FAST_DATA_ZERO_INIT gyro_t gyro = {0};
bool overflowDetected = false;
bool gyroCalibDone = false;
bool firstArmingCalibrationWasStarted = false;

// Mock functions
bool gyroIsCalibrationComplete(void) { return gyroCalibDone; }
void gyroStartCalibration(bool dummy) { gyroCalibDone = false; }
void gyroUpdate(void) {}
int16_t gyroGetTemperature(void) { return 0; }

// Mock for gyroConfig and gyroConfigMutable
static gyroConfig_t mockGyroConfig = {0};
gyroConfig_t* gyroConfig(void) { return &mockGyroConfig; }
gyroConfig_t* gyroConfigMutable(void) { return &mockGyroConfig; }
