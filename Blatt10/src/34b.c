#include<stdio.h>

int multiples_of_x(int n, int x, int *lower, int *greater){
        int i;
        if(lower == NULL || greater == NULL) return 0;
        for(i = n; i >= 1; i--){
                if(i % x == 0){
                        *lower = i;
                        break;
                }
        }
        i = n;
        while(*greater == 0){
                if(i % x == 0){
                        *greater = i;
                }
                i++;
        }
        return 1;
}

int main(void){
        int x = 7;
        int n = 20;
        int lower = 0;
        int greater = 0;
        multiples_of_x(n, x, &lower, &greater);
        printf("\nx = %i", x);
        printf("\nn = %i", n);
        printf("\nlower = %i", lower);
        printf("\ngreater = %i",greater);

        return 0;
}