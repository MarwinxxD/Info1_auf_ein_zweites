#include<math.h>

int i(int i, int x){
    if(i== 4)  x = pow(x, 2);
    else if(i == 8) x = pow(x, 4);
    return x; 
}

void ii(){
    int count = 0;
    while(count < 5){
        printf("count is %d\n", count +1);
        count++;
    }
}

void iii(int n){
    int i = 0;
    int sum = 0;
    while(i < n){
        sum += i * i;
        i++;
    }
}

void iv(int arr[], int size){
    int j;
    int total = 0;

    for(j = 0; j < size; j++){
        if(arr[j] % 2 == 1){
            total += arr[j];
        }
    }
}