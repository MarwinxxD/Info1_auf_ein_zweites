#include<stdio.h>

int main(void){
        int i = 0;
        for(i = 1; i < 50; i++){
                if(50 % i == 0){
                        printf("%i \n", i);
                }
        }
        return 0;
}