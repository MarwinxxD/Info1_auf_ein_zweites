#include<stdio.h>
#include<string.h>

#define MAX_STRING 10
#define ERFOLG 1
#define NICHT_ERFOLG 0

void flush(){
    while(getchar() != '\n'){}
}

int read_string(char in[]){
        int status;
       
        status = scanf(" %9[^\n]", in);
        if(status == 0 || getchar() != '\n'){
                flush();
                return NICHT_ERFOLG;
        }
        return ERFOLG;
}

int count_words(char s[]){
        int i = 0;
        int words = 0;

        if(strlen(s) == 0) return 0;
        while(s[i] != '\0'){
                if(s[i] == ' '){
                        words++;
                }
                i++;
        }
        return words + 1;
}



int main(void){
        char in[MAX_STRING];
        int e;
        
        printf("\nMaster-sama gib mir pwweeees eine Zeichenkette\n mit maximal %i Zeichen, damit ich Worterzahlen uben kann m(_ _)m: ", MAX_STRING);
        
        e = read_string(in);
       
        if(e == NICHT_ERFOLG){
                printf("\nBAKAAA-sama du hast mir zu viele Zeichen ubergeben grrrrrr");
        }
        else printf("\nDu hast %i Worter geschrieben, CHUUUUUUU", count_words(in));
        
        return 0;
}