#include <stdio.h>
#include <string.h>

int main(void)
{
        char v[] = {"Tomate"};
        char w[10];
        printf("v hat gespeichert: %s\n", v);
        strcpy(w, v);
        printf("w hat gespeichert: %s\n", w);
        printf("Das Zeichen an der 2. Stelle von w: %c\n", w[1]);
        printf("Der ASCII-Code vom diesem Zeichen: %i\n", w[1]);
        w[4] = 'i';
        printf("w hat gespeichert: %s\n", w);
        w[3] = '\0';
        printf("w hat gespeichert: %s\n", w);

        return 0;
}