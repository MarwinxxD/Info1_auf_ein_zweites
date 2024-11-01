#include<stdio.h>

int main (void){
    char v[] = {'T','o', 'm', 'a', 't', 'e'};
    char w[10];
    int i = 0;

    printf("hier ist v: %s", v);
    
    for(i = 0; i < 6; i++){
        w[i] = v[i];
    }

    printf("\nw wird wiedergegeben%s", w);

    printf("\ndas zweite zeichen von w ist:%c", w[1]);
    
    printf("\nder ascii code von dem: %i", w[1]);

    w[3] = 'i';

    printf("\nhier ist w wieder %s", w);

    w[3] = 0;

    printf("\nhier ist w wieder %s", w);
    
    return 0;
}

