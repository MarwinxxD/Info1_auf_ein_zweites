#include <stdio.h>

int main(void) {

        char str1[] = "info";
        char str2[] = "info";
        char str3[] = "informatik";
        char str4[] = "infm";
        char str5[] = "";
        
        printf("Vergleiche von:");
        //identisch
        printf("'%s' und '%s': %d\n", str1, str2, string_compare(str1, str2)); // 0
        //unterschiedliche Länge
        printf("'%s' und '%s': %d\n", str1, str3, string_compare(str1, str3)); // < 0
        printf("'%s' und '%s': %d\n", str3, str1, string_compare(str3, str1)); // > 0
        //gleiche Länge aber unterschiedliches Zeichen am Ende
        printf("'%s' und '%s': %d\n", str1, str4, string_compare(str1, str4)); // < 0
        printf("'%s' und '%s': %d\n", str4, str1, string_compare(str4, str1)); // > 0
        //mit Leerer Zeichenkette
        printf("'%s' und '%s': %d\n", str5, str1, string_compare(str5, str1)); // < 0
        printf("'%s' und '%s': %d\n", str5, str5, string_compare(str5, str5)); // 0

        return 0;
}

int string_compare(char v[], char w[]) {
        int i;
        while((v[i] != '\0') && (w[i]) != '\0') {
                if(v[i] != w[i]) {
                        return v[i] - w[i];     //genaue Funktionsweise wie strcmp
                                                //Rückgabewert ist differenz der ASCII-Codes der
                                                //vergleichten Zeichen bei gleichlangen Arrays
                }
                i++;
        }
        return v[i] - w[i];     //wenn v und w gleich sind kommt ihr 0 raus sonst
                                //kommt die ASCII-Differenz der letzten zeichen
}