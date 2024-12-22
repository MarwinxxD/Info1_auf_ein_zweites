#include<stdio.h>

int increment_if_zero(int *x, int *y){
        printf("\nx und y for funktion: %i, %i", *x, *y);
        if(*y == 0){
                ++(*x);
                printf("\nx nach funktion: %i", *x);
                return 1;
        }
        printf("\nx nach funktion: %i", *x);
        return 0;
}

int main(void){
        int a = -1;
        int b = 0;
        int c = 5;
        
        increment_if_zero(&a, &b);
        increment_if_zero(&a, &c);
        increment_if_zero(&b, &c);
        increment_if_zero(&b, &a);
        increment_if_zero(&c, &a);
        increment_if_zero(&c, &b);

        return 0;       
}