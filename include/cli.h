// include/cli.h
#ifndef CLI_H
#define CLI_H

// Initialize CLI (print intro)
void cli_init();

// Process a single command from user input
// Returns 0 to continue, 1 to exit
int cli_process(float current_altitude);

#endif
