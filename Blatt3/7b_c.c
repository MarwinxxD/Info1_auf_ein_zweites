#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void random_string(char v[], int len);

int main(void)
{
        char v[12], u[12], w[12];
        int lengh = 12;
        srand(time(NULL));

        random_string(u,lengh);
        printf("random String u: %s\n", u);
        strcpy(v, u);
        printf("random String u kopiert nach v: %s\n", v);
        strncpy(w, u, 5);
        w[5] = '\0';
        printf("die Ersten 5 Zeichen von u kopiert nach w:%s\n", w);

        printf("u und v verglichen:%d\n", strcmp(u, v));
        printf("u und w verglichen:%d\n", strcmp(u, w));
        printf("w und u verglichen:%d\n", strcmp(w, u));

        printf("\nDer Vergleich von den ersten 5 Zeichen\n");
        printf("u und v verglichen:%d\n", strncmp(u, v, 5));
        printf("u und w verglichen:%d\n", strncmp(u, w, 5));
        printf("w und u verglichen:%d\n", strncmp(w, u, 5));

        strncat(w, w, 5);
        printf("w an sich selbst rangehangen: %s\n", w);

        return 0;
}

void random_string(char v[], int len)
{
        int i;
        for(i = 0; i < len - 1; i++) {
                if (rand() % 2 == 0) {
                        v[i] = 'A' + rand() % 26;
                } else {
                        v[i] = 'a' + rand() % 26;
                }
        }
    v[len - 1] = '\0';
}