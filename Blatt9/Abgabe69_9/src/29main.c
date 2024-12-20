#include "temperature.h"

int main(void) {
	int max_size = 10;
    	double temperatures[10];
   	int *size = 0;

	double second_temperatures[] = {25.5, -100.0};
	int second_size = 2;

    	if (input_temperature(temperatures, size, max_size) == SUCCESS) {
        	printf("Temperatur erfolgreich hinzugefuegt.\n");
    	}

    	printf("Alle Temperaturen in Fahrenheit:\n");
    	print_temp_in_fahrenheit(temperatures, *size);

    	if (connect_temperature_arrays(temperatures, size, max_size, second_temperatures, second_size) == SUCCESS) {
        	printf("Arrays erfolgreich zusammengeführt.\n");
    	} else {
		printf("Das 2. Array ist zu lang um es an das 1. Array anzufuegen!");
	}

    	printf("Aktualisierte Temperaturen in Fahrenheit:\n");
    	print_temp_in_fahrenheit(temperatures, *size);

	return 0;
}