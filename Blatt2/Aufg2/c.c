#include<stdio.h>

int main(void){
        int i = 0;

        for(i = 1; i <= 8; i++){
                if(i == 8){
                        printf("%i!", i*i);
                }
                else printf("%i,", i * i);
        }
        return 0;
}