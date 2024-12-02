#include<math.h>

int eins(double a){           //1.
     int n = floor(a);
     return n;
}

int zwei(int x){             //2.
    if((x & 7) == 0){
        return 1;
    }
    return 0;
}

int drei(int a,int b,int c){ //3.
    if(a < b){
        if(a > c){
            return 1;
        }
        return 0;
    }
    if(a > b){
        if(a < c){
            return 1;
        }
        return 0;
    }
    return 0;
}

int main (void){
    return 0;    
}