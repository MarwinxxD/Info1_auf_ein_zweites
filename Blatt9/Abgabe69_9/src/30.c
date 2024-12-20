#include "30.h"
#include<stdio.h>


int prim(int a){
    int i;
    for(i = 2; i * i <= a; i++){
        if(a % i  == 0){
            return 0;            /*flase*/
        }
    }
    return 1;                    /*true*/
}

int quad(int a){
    int i;
    for(i = 0; i < a; i++){
        if((i * i) == a){
            return 1;             /*true*/
        }
    }
    return 0;                     /*false*/
}

int main(void){
    int a, b, n;
    n = 0;

    for(a = 1000; a <= 1100; a++){
        if(prim(a)){
             ISPRIME(a);

            if(n > 0){
            printf("\nabstand zwischen %i und %i ist: %i", n, a, ABSTANT(a, n));
            }
        n = a;
        }
        
    }

    for(b = 1000; b <= 2000; b++){
        if(quad(b)){
            printf("\nBoa %i ist übelst die Quadrahtzahl", b);
        }
        
    }
    return 0;
}