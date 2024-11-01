#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

    char u[12];
    char v[12];
    char w[12];
    int i = 0;
    
void random_string(char v[], int len){
    for(i = 0; i < len; i++){
        int r = rand() % 2;
        if(r > 0){
            v[i] = rand() % 26 + 65;
            
        }
        else v[i] = rand() % 26 + 97;
        
    } 
}

int main (void){
    srand(time(NULL));
    
    random_string(u ,12);

    for(i = 0; i < 12; i++){
        v[i] = u[i];
    }
    printf("\ndas ist v %s", v);

    for(i = 0; i < 5; i++){
        w[i] = u[i];
    }
    printf("\ndasist w %s", w);

    printf("\nvergleich u und v ergibt: %d", strcmp(u, v));
    printf("\nvergleich u und w ergibt: %d", strcmp(u, w));
    printf("\nvergleich w und v ergibt: %d", strcmp(w, v));

    printf("\nu und v erste 5zeichen vergleich %i", strncmp(u, v, 5));
    printf("\nu und w erste 5zeichen vergleich %i", strncmp(u, w, 5));
    printf("\nw und v erste 5zeichen vergleich %i", strncmp(w, v, 5));
    return 0;
}