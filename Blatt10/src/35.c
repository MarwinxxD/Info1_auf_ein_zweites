#include<stdio.h>
#include<stdlib.h>

int *array_d_filter_even(int *a, int size, int *filterd_size){
        int i; 
        int *even = malloc(0);
        filterd_size = 0;
        for(i = 0; i <= size; i++){
                if(a[i] % 2 == 0){
                        filterd_size++;
                        even  = realloc(even, (sizeof(even) + 1) * sizeof(int));
                        even[*filterd_size] = a[i];
                }
        }
        if(even == NULL) return NULL;
        return even;
}

int *array_d_intersection(int *a, int size_a, int *b, int size_b, int *intersected_size){
        int i, n;
        int *intersection = malloc(sizeof(int));
        for( i = 0; i <= size_a; i++){
                for(n = 0; n <= size_b; n++){
                        
                        if(a[i] == b[n]){
                                
                                intersection = realloc(intersection, (sizeof(intersection) + 1) * sizeof(int));
                                intersection[*intersected_size] = a[i];
                                printf("hello");                /*ausgabe funktioniert ab dieser zeile nicht, kp warum*/
                                intersected_size++;
                                
                        }
                }
        }
        
        if(intersection == NULL) return NULL;
        return intersection;
}

int main(void){
     
        int aa[] = {2,4,5,6};
        int ba[] = {1,2,5,6};
        int *a = aa;
        int *b = ba;
        int size_a = 4;
        int size_b = 4;
        int *p = 0; 
        int *x = array_d_intersection(a, size_a, b, size_b, p);
        printf("hihi");
        printf("\ndie schnittmenge von a und b ist: %n", x);

        free(x);
        return 0;
}

