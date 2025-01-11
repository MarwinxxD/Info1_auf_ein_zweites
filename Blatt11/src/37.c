#include<stdio.h>
#include<float.h>

double *max_value(double *v, int v_len){
    int i;
    double *mv = v;
    if(v == NULL) return NULL;
    for(i = 1; i < v_len; i++){
        if(*mv < v[i]) mv = &v[i];
    }

    return mv;
}

double *min_value(double *v, int v_len){
    int i;
    double *minV = v;
    if(v == NULL) return NULL;
    for(i = 1; i < v_len; i++){
        if(*minV > v[i]) minV = &v[i];
    }
    return minV;
}

int normalize_array(double *v, int v_len){
    double *min = min_value(v, v_len);
    double *max = max_value(v, v_len);
    double mm = *max - *min;
    int i;
    
    if(v == NULL) return -1;
    if(*max - *min <= DBL_EPSILON){
        for(i = 0; i < v_len; i++){
        v[i] = 1;
        }
    }

    for(i = 0; i < v_len; i++){
        v[i] = v[i] - *min;
        v[i] = v[i] / mm;
    }
    return 1;
}

void print_array(double *v, int v_len){
    int i;
    printf("\n");
    for(i = 0; i < v_len; i++){
        printf("%f ", v[i]);
    }
}

int main(void){
    double deez[5][5] = {{0.0, 1.0, 2.0, 3.0, 4.0}, {3.0, 2.5, 2.2, 2.7, 2.0}, {1.2, 4.5, 3.7, -0.5, 4.2}, {2.1352, -1.0541, 4.5423, 0.231, -3.2441}, {1.0, 1.0 + 0.25 * DBL_EPSILON, 1.0 + 0.5 * DBL_EPSILON, 1.0 + 0.75 * DBL_EPSILON, 1.0 + DBL_EPSILON}};
    int len = 5;
    print_array(deez[0], len);
    normalize_array(deez[0], len);
    print_array(deez[0], len);
    printf("\n");
    print_array(deez[1], len);
    normalize_array(deez[1], len);
    print_array(deez[1], len);
    printf("\n");
    print_array(deez[2], len);
    normalize_array(deez[2], len);
    print_array(deez[2], len);
    printf("\n");
    print_array(deez[3], len);
    normalize_array(deez[3], len);
    print_array(deez[3], len);
    printf("\n");
    print_array(deez[4], len);
    normalize_array(deez[4], len);
    print_array(deez[4], len);
    return 0;
}