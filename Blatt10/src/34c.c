#include<stdio.h>

int flushBuff(void){
        int c;
        while((c = getchar()) != '\n' && c != EOF){}
        return c != EOF;
}

int read_percent(int *percentage){
        printf("UwU Master-sama bitte übergib mir eine zahl zwischen 0 und 100^^\n");
        scanf("%i", percentage);
        if(*percentage < 0 || *percentage > 100){
                printf("BAAAKAAAA-sama deine Eingabe ist scheisse grrrr");
                flushBuff();
                return 0;
        }
        return 1;
}


int main(void){
        int pe;
        if(read_percent(&pe)) printf("Hier Master-sama deine Eingabe^^\n%i", pe);
        return 0;
}