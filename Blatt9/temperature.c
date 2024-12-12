#include "temperature.h"

void print_temp_in_fahrenheit(double *temperatures, int  size) {
   	int i;
	for (i = 0; i < size; i++) {
        	printf("Temperatur %f°C zu: %.2f°F\n", temperatures[i], CELSIUS_TO_FAHRENHEIT(temperatures[i]));
   	}
}

int input_temperature(double *temperatures, int *size, int max_size) {
	double input;

	if (*size >= max_size) {
        	printf("Fehler: Maximale Kapazitaet des Arrays erreicht.\n");
        	return ERROR;
    	}

    	printf("Geben Sie eine Temperatur in Grad Celsius ein (%d bis %.2f): ", MIN_CELSIUS, MAX_CELSIUS);

    	if (scanf("%lf", &input) != 1 || input < MIN_CELSIUS || input > MAX_CELSIUS) {
        	printf("Ungueltige Eingabe! Bitte eine gueltige Temperatur eingeben.\n");
        	return ERROR;
    	}

    	temperatures[*size] = input;
    	(*size)++;
    	return SUCCESS;
}
int connect_temperature_arrays(double *temps1, int *temps1_size, int max_size, double *temps2, int temps2_size) {
	int i;

	if (*temps1_size + temps2_size > max_size) {
        	printf("Fehler: Ziel-Array hat nicht genuegend Kapazitaet.\n");
        	return ERROR;
    	}

    	for (i = 0; i < temps2_size; i++) {
        	temps1[*temps1_size + i] = temps2[i];
    	}

    	*temps1_size += temps2_size;
    	return SUCCESS;
}

