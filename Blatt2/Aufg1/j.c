#include<stdio.h>
int main(void){
        int n;
        char c;
        n = rand();
        c = n % 128;
        printf("%c \n %i", c, c);
        if(c<=122 && c >= 91){
                return 1;
        }
        if(c <= 57 && c >= 48){
                return 2;
        }
        if(c <= 57 && c >= 48 || 65 <= c && 70 >= c){
                return 3;
        }
        if(65 <= c && 90 >= c){
                return 4;
        }
}
