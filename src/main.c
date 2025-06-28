// src/main.c
#include <stdio.h>
#include <unistd.h>     // for sleep
#include "barometer.h"

int main() {
    printf("🚀 Virtual Altitude Monitor starting up...\n");

    while (1) {
        float altitude = get_virtual_altitude();
        printf("📡 Current Altitude: %.2f ft\n", altitude);
        sleep(1); // wait for 1 second
    }

    return 0;
}

