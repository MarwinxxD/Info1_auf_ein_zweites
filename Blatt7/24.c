#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 10

void caesar_encrypt(char text[], int shift, int n_chars);

int main(int argc, char *argv[]) {

        if(argc < 2) {
                printf("Fehler: Es muss mindestens ein Eingabeparameter eingegeben werden!");
                return 1;
        }

        char combined_text[MAX_LENGTH + 1];
        int shift, i;
        int current_length, word_length, space_needed, remaining_space;

        srand(time(NULL));
        shift = (rand() % 25) +1 ;
        printf("der zufaellige Shift für die Verschlüsselung ist: %d\n", shift);

        for (int i = 1; i < argc; i++) {
                word_length = strlen(argv[i]);
                space_needed = current_length > 0 ? 1 : 0;

                if (current_length + space_needed + word_length > MAX_LENGTH) {         //Fall wenn naechstes Wort zu lang ist
                        remaining_space = MAX_LENGTH - current_length - space_needed;   //verbleibende Platz wird ermittelt
                        //wenn nur noch 1 Platz frei ist wird wegen dem '- space_needed' die if false und es wird auch ein Leerzeichen hinzugefuegt
                        if (remaining_space > 0) {                                      
                                strncat(combined_text, " ", 1);
                                strncat(combined_text, argv[i], remaining_space);
                        }
                        break;
                }

                if (space_needed == 1) {                //Leerzeichen hinzufuegen, wenn es nicht das erste Wort ist
                        strcat(combined_text, " ");
                }
                strcat(combined_text, argv[i]);
                current_length = strlen(combined_text); //aktuelle Laenge updaten
        }

        caesar_encrypt(combined_text, shift, MAX_LENGTH);

        printf("Verschlüsselte Zeichenkette: %s\n", combined_text);

        return 0;
}

void caesar_encrypt(char text[], int shift, int n_chars) {

        int i;
        for(i = 0; (i < n_chars) || (text != '\0'); i++) {
                if(isalpha(text[i])) {
                        char base = islower(text[i]) ? 'a' : 'A';
                        text[i] = (text[i] - base + shift) % 26 + base;
                }
        }

}