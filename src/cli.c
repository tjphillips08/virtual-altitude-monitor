// src/cli.c
#include "cli.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int logging_enabled = 0;
static int fault_active = 0;

void cli_init() {
    printf("📟 CLI Interface Ready. Commands: STATUS, LOG ON, LOG OFF, FAULT, EXIT\n");
}

void to_upper(char *str) {
    for (; *str; ++str) {
        *str = toupper((unsigned char)*str);
    }
}

void cli_set_fault(int fault) {
    fault_active = fault;
}

int cli_get_fault() {
    return fault_active;
}

int cli_process(float current_altitude) {
    char input[100];

    printf(">> ");
    if (!fgets(input, sizeof(input), stdin)) {
        return 1; // exit on EOF or error
    }

    to_upper(input);

    if (strstr(input, "STATUS")) {
        printf("📡 Altitude: %.2f ft\n", current_altitude);
    } else if (strstr(input, "LOG ON")) {
        logging_enabled = 1;
        printf("✅ Logging enabled.\n");
    } else if (strstr(input, "LOG OFF")) {
        logging_enabled = 0;
        printf("⛔ Logging disabled.\n");
    } else if (strstr(input, "FAULT")) {
        if (fault_active) {
            printf("⚠️ Rapid descent fault currently active!\n");
        } else {
            printf("✅ No faults detected.\n");
        }
    } else if (strstr(input, "EXIT")) {
        return 1;
    } else {
        printf("❓ Unknown command. Try: STATUS, LOG ON, LOG OFF, FAULT, EXIT\n");
    }

    return 0;
}

int is_logging_enabled() {
    return logging_enabled;
}
