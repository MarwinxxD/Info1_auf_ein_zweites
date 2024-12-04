#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	srand(time(NULL));

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
}

int evaluate_guess(const int code[], const int guess[], int results[]) {
    	int i;
	int code_count[10] = {0};
    	int guess_count[10] = {0};

    	for (i = 0; i < CODE_LENGTH; i++) {
        	if (code[i] == guess[i]) {
            		result[0]++;
        	} else {
         		code_count[code[i]]++;
            		guess_count[guess[i]]++;
        	}
    	}

    	for (i = 0; i < 10; i++) {
        	results[1] += (code_count[i] < guess_count[i] ? code_count[i] : guess_count[i]);
    	}
	return 0;
}