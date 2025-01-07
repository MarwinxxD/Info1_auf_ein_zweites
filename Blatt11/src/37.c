#include<stdio.h>

double *max_value(double *v, int v_len){
    int i;
    double *mv = &v[0];
    for(i = 0; i <= v_len; i++){
        if(*mv < v[i]) *mv = v[i];
    }

    return mv;
}