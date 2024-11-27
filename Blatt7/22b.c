#include <stdio.h>

int main(void) {

        char str1[] = "Informatik";
        char str2[] = "Info";
        char str3[] = "Inform";
        char str4[] = "Informatik";
        char str5[] = "";
        char str6[] = "Informatiker";
        char str7[] = "In";
        //kurzes Präfix
        printf("'%s' ist Praefix von '%s': %d\n", str2, str1, string_prefix(str1, str2)); // 1
        //langes Präfix
        printf("'%s' ist Praefix von '%s': %d\n", str3, str1, string_prefix(str1, str3)); // 1
        //gleichlanges Präfix 
        printf("'%s' ist Praefix von '%s': %d\n", str4, str1, string_prefix(str1, str4)); // 1
        //leere Zeichenkette als Präfix
        printf("'%s' ist Praefix von '%s': %d\n", str5, str1, string_prefix(str1, str5)); // 1
        //v kürzer als Präfix
        printf("'%s' ist Praefix von '%s': %d\n", str6, str1, string_prefix(str1, str6)); // 0

        return 0;
}

int string_prefix(char v[], char w[]) {
        int i;

        while(w[i] != '\0') {
                if ((v[i] == '\0') || (w[i] != v[i])) return 0;
                i++;
        }

        return 1;
}