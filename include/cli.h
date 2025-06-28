#ifndef CLI_H
#define CLI_H

void cli_init();
int cli_process(float current_altitude);
int is_logging_enabled();

void cli_set_fault(int fault);  // <-- This declaration is required
int cli_get_fault();

#endif
