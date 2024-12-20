#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_CELSIUS -273.15
#define MIN_CELSIUS 100
#define SUCCESS 0
#define ERROR -1

#define CELSIUS_TO_FAHRENHEIT(celsius) ((celsius) *1.8 + 32)

void print_temp_in_fahrenheit(double *temperatures, int size);
int input_temperature(double *temperatures, int *size, int max_size);
int connect_temperature_arrays(double *temps1, int *temps1_size, int max_size, double *temps2, int temps2_size);

#endif