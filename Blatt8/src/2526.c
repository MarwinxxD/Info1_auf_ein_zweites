#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define CODE_LENGTH 4
#define MAX_ATTEMPTS 10

#define VALID_INPUT 0
#define INPUT_CHAR 1
#define INVALID_LENGTH 2

void generate_code(int code[]);
int read_guess(char guess[]);
void flush();
int evaluate_guess(const int code[], const int guess[], int result[]);

int main(void) {
	int code[CODE_LENGTH];
	char input_str[CODE_LENGTH + 5];
	int input[CODE_LENGTH];
	int result[2];
	int try, input_valid, i;

	srand(time(NULL));

	generate_code(code);

	printf("Errate den geheimen Code\n");
	printf("Sie haben 10 Versuche\n");
	printf("------------------------\n\n");

	for(try = 0; try < MAX_ATTEMPTS; try++) {
		printf("Dein %d. Versuch:\nBitte geben Sie eine 4 stellige Zahl ein:\n\n", (try + 1));
		input_valid = read_guess(input_str);

		if(input_valid == INPUT_CHAR) {
			printf("Ungueltige Eingabe! Bitte nur Zahlen eingeben\n");
			continue;
		} else if(input_valid == INVALID_LENGTH) {
			printf("Ungueltige Eingabe! Bitte geben sie genau 4 Zahlen ein.\n");
			continue;
		}

		for(i = 0; i < CODE_LENGTH; i++) {
			input[i] = input_str[i] - '0';
		}

		if(evaluate_guess(code, input, result)) {
			printf("Herzlichen Glueckwunsch!! Sie haben den Code erraten\n");
			break;
		} else {
			printf("Anzahl der korrekten Zahlen an der richtigen Position: %d\n", result[0]);
			printf("Anzahl der korrekten Zahlen an der falschen Position %d\n", result[1]);
		}
	}

	if(try == MAX_ATTEMPTS) {
		printf("\nLeider haben sie den Code nicht erraten. Der Code war: ");
		for(i = 0; i < CODE_LENGTH; i++) {
			printf("%d", code[i]);
		}
	}

	printf("\nDanke fürs spielen!\n");
	return 0;
}

void flush() {
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

void generate_code(int code[]) {
	int i;
	for(i = 0; i < CODE_LENGTH; i++) {
		code[i] = rand() % 10;
	}
}

int read_guess(char guess[]) {
	int i;
	char c;
	
	while((c = getchar()) != '\n' && c != EOF) {
		if(!isdigit(c)) {
			flush();
			return INPUT_CHAR;
		}
		guess[i] = c;
		i ++;
	}
	if(strlen(guess) != 4) {
		flush();
		return INVALID_LENGTH;
	}
	return VALID_INPUT;
}

int evaluate_guess(const int code[], const int guess[], int results[]) {
    	int i;
	int code_count[10] = {0};
    	int guess_count[10] = {0};

    	for (i = 0; i < CODE_LENGTH; i++) {
        	if (code[i] == guess[i]) {
            		results[0]++;
        	} else {
         		code_count[code[i]]++;
            		guess_count[guess[i]]++;
        	}
    	}

    	for (i = 0; i < 10; i++) {
        	results[1] += (code_count[i] < guess_count[i] ? code_count[i] : guess_count[i]);
    	}
	return results[0] == CODE_LENGTH;
}