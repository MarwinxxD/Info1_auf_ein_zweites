#include<stdio.h>                               /*UNFERTIG!!!!!!!!!!!!!!!!!!!!!!!!!*/
#include<string.h>

int uThere(char x, const char *p){
        int i;
        for(i = 0; i <= (int)strlen(p); i++){
                if(x == p[i]) return 1;         /*Char ist im String vorhanden*/
        }
        return 0;                               /*Char ist nicht im String*/
}

int find_longest_substring(const char *source, const char *allowed_characters, const char **start){
        int i;
        int t = 0, len = 0, c = 0;
        const char *h = source;

        if(start == NULL) return -1;

        for(i = 0; i < (int) strlen(source); i++){
                if(c == t){                             /*wenn t 2mal das selbe ist gab es eine unterbrechung im substring*/
                        t = 0;
                        h = &source[i];
                }                          
                c = t;                                      
                if(uThere(source[i], allowed_characters)) t++;
                if(t > len){
                        len = t;
                        *start = h;
                }
        }
        
        return len;
}

void printN(const char *p, int n){
        int i;
        printf("\n");
        for(i = 0; i < n; i++){
                if(p[i] == '\0') break;
                printf("%c", p[i]);
        }
        printf("\n");
}

int main(void){
        const char *start = "";

        printN(start, find_longest_substring("Das12ist1235alles1", "123456798",&start));
        return 0;
}