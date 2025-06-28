#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "barometer.h"
#include "cli.h"
#include "logger.h"

int main() {
    printf("🚀 Virtual Altitude Monitor starting up...\n");
    cli_init();
    logger_init("logs/log.csv");

    float last_altitude = 0.0;
    bool first_reading = true;

    while (1) {
        float altitude = get_virtual_altitude();

        bool fault = false;
        if (!first_reading) {
            float delta = last_altitude - altitude;
            if (delta > 100.0f) {
                fault = true;
                printf("⚠️  FAULT DETECTED: Rapid descent of %.2f ft!\n", delta);
            }
        }
        last_altitude = altitude;
        first_reading = false;

        // Tell CLI about fault status
        cli_set_fault(fault);

        if (is_logging_enabled()) {
            logger_log(altitude, fault);
        }

        if (cli_process(altitude)) {
            break;
        }

        sleep(1);
    }

    logger_close();
    printf("🛑 System shutting down.\n");
    return 0;
}
