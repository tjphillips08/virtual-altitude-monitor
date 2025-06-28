// src/logger.c
#include "logger.h"
#include <stdio.h>
#include <time.h>

static FILE *log_file = NULL;

void logger_init(const char *filename) {
    log_file = fopen(filename, "w");
    if (log_file) {
        fprintf(log_file, "timestamp,altitude,fault\n");
    }
}

void logger_log(float altitude, bool fault) {
    if (!log_file) return;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    fprintf(log_file, "%04d-%02d-%02d %02d:%02d:%02d,%.2f,%s\n",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec,
            altitude, fault ? "FAULT" : "OK");

    fflush(log_file); // Ensure data is written immediately
}

void logger_close() {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}
