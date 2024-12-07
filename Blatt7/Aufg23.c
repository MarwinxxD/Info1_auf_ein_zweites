#include<stdio.h>
#include<stdlib.h>

int i;

int kleinBuch(char *a[]){
    int i = 0;
    while(a[i] != 0){
        if(*a[i] >= 123 || *a[i] <= 60) return i;
        i++;
    }
    return 0;
}

void buchZahlen(char *a[], int letters[]){
    while(a[i] != 0){
        letters[ *a[i] - 60] += 1;
    }
}

int main(int argc, char * argv[]){
    int abc[26];
    if(argc== 0){
        printf("Ohaaaa Brudi nächstes mal gönnst du aber schon einen String, sonst hörst du das hier nochmal");
    }
    if(!kleinBuch(argv)){
        printf("%s", argv[kleinBuch(argv)]);
        exit(0);
    }
    buchZahlen(argv, abc);
    for(i = 0; i == 25; i++){
        printf("\n%c:%i", i+60, abc[i]);
    }
    return 0;
}