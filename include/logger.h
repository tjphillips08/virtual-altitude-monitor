// include/logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <stdbool.h>

void logger_init(const char *filename);
void logger_log(float altitude, bool fault);
void logger_close();

#endif
