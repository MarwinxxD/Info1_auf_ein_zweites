#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define CODE_LENGHT 4
#define MAX_ATTEMPS 10

int i;

void flush(){
    while(getchar() != '\n'){}
}

void generate_code(int code[]){
    for(i = 0; i < CODE_LENGHT; i++){
        code[i] = rand() % 10;
    }
}

int read_guess(char guess[]){
    int true = 1;
    int false = 0;
    printf("Master-sama UwU, gwib mir bitte vier Ziffer (^з^)-☆Chu!!");
    for(i = 0; i < CODE_LENGHT; i++){
        guess[i] = getchar();
    }
    for(i = 0; i < CODE_LENGHT; i++){
        if(!isdigit(guess[i])){
            printf("BAAKAAA-sama du hast mir keine 4Ziffern übergeben ༼ ༎ຶ ෴ ༎ຶ༽");
            flush();
            return false;
        }
    }
    return true;
}

int main(void){
    char guess[4];
    read_guess(guess);
    printf("guess:%s", guess);
    return 0;
}

