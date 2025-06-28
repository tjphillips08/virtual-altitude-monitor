// src/barometer.c
#include "barometer.h"
#include <math.h>

float get_virtual_altitude() {
    static float t = 0.0f;
    t += 0.1f;
    return 1000.0f + 50.0f * sinf(t);  // Simulate altitude fluctuation
}
