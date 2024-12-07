#include<stdio.h>
int string_prefix(char v[], char w[]){
    int i = 0, n = 0;
    int size = 0;
    int control = 0;
    while(w[size] != 0) size++;
    printf("\nsize: %i", size);
    while(v[i] != 0){
        for(n = 0; n == size; n++){
            if(v[i + n] == w[n]) control++;
            else{
                printf("\nv[i + n]: %i", v[i + n]);
                break;
            }
        }                                                  //geht noch nicht bitte nicht verwenden
        if(control == size) return 1;
        else{
            printf("\ncontrol:%i", control);
            i++;
            control = 0;
        }
    }
    return 0;
}

int main(void){
    printf("%i", string_prefix("Informatik", "Info"));
    return 0;
}