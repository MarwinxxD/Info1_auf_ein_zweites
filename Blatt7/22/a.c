#include<stdio.h>

int string_compare(char v[] ,char w[]){
    int i = 0;
    while(v[i] != 0 || w[i] != 0){
        if(v[i] != w[i]) return v[i] - w[i];
        i++;
    }
    return 0;
}

int main(void){
    char a[] = {'a','b','c'};
    char b[] = {'a','a','a',};
    char c[] = "";
    char d[] = {'i'};

    printf("\na mit a vergleich(gleiche Zeichenkette): %i", string_compare(a, a));
    printf("\na mit d vergleich(verschiedene länge): %i", string_compare(a, d));
    printf("\na mit c vergleich(mit leer): %i", string_compare(a, c));
    printf("\na mit b vergleich(ungleich): %i", string_compare(a, b));
    return 0;
}