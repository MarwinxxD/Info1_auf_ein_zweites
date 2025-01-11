#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

double string_to_double(const char *s, char **endp){
        int i = 0, x = 0;
        double a = 0;
        
        while(s[i] == '\0'){
                if(isDigit(s[i])){
                        a = a  + s[i] * pow(10,x);
                        x--;
                }
        }
}