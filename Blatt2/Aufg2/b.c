#include<stdio.h>
#include<ctype.h>

int main(void){
        char a[] = {'A', 'b', '3'};
        int i = 0;
        for(i = 0; i < 3; i++){
                if(!isdigit(a[i])){
                        printf("%c is keine Ziffer\n", a[i]);
                }
                if(isupper(a[i])){
                        printf("%c %c\n", a[i],tolower(a[i]));
                }
                if(isxdigit(a[i])){
                        printf("%c\n", a[i]);
                }
        }
        return 0;

}