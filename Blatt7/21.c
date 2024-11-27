
//Aufgabe b:
//1.
double a;
floor(a);

//2.
(x & 7) == 0

//3.
(a >= b && a <= c) || (a >= c && a <= b)

//Aufgabe c:
//1.
if( i == 4) {
        x = pow(x,2);
} else if( i == 8) {
        x = pow(x,4);
} else return x;

//2.
int count = 0;
while (count < 5) {
        printf("Count in %d\n", count + 1);
        count++;
}

//3.
int i = -1;
int sum = 0;
while (i < n) {
        sum += i * i;
        i++;
}

//4.
for(j = 0; j < size; j++) {
        if((arr[j] % 2) != 0) {
                total += arr[j];
        }
}