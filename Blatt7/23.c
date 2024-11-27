#include <stdio.h>

#define VALID 0
#define INVALID 1

int check_lower(const char str[]);
void count_letters(const char str[], int letters[26]);

int main(int argc, char *argv[]) {
        int letters[26] = {0};
        int i;


        if (argc < 2) {
                printf("Das Programm zaehlt die Vorkommen der Kleinbuchstaben in den angegebenen Parameterm.\n");
                printf("Fehler: keine Parameter wurden angegeben. BITTE geben sie Parameter mit Kleinbuchstaben an!");
                return 0;
        }

        for (int i = 1; i < argc; i++) {
                if (check_lowercase(argv[i]) == INVALID) {
                        printf("Fehler: Der Parameter '%s' enthaelt Zeichen, die keine Kleinbuchstaben sind.\n", argv[i]);
                        return 1;
                }
                count_letters(argv[i], letters);
        }

        printf("Buchstabenhäufigkeit:\n");
        for (int i = 0; i < 26; i++) {
                if (letters[i] > 0) {
                        printf("%c: %d\n", 'a' + i, letters[i]);
                }
        }
        return 0;
}

int check_lower(const char str[]) {
        int i = 0;

        while (str[i] != '\0') {
                if (str[i] < 'a' || str[i] > 'z') return INVALID;
                i++;
        }

        return VALID;
}

void count_letters(const char str[], int letters[26]) {
        int i = 0;

        while (str[i] != '\0') {
                if (str[i] >= 'a' && str[i] <= 'z') {
                        letters[str[i] - 'a']++;
                } 
                i++;
        }
}