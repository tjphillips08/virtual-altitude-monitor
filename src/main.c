// src/main.c
#include <stdio.h>
#include <unistd.h>
#include "barometer.h"
#include "cli.h"

int main() {
    printf("🚀 Virtual Altitude Monitor starting up...\n");
    cli_init();

    while (1) {
        float altitude = get_virtual_altitude();

        // Check user commands (blocking)
        if (cli_process(altitude)) {
            break;
        }

        sleep(1);
    }

    printf("🛑 System shutting down.\n");
    return 0;
}
