#include<stdio.h>
#include<stdlib.h>

int main(void){
        int n;
        double x;
        int r = rand();
        n = r;
        x = (double) n / RAND_MAX;
        printf("%i /n %d", n, x);
        return 0;
}