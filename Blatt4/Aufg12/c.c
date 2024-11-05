int main(void){
    int s1; //wird nicht im code deklariert
    int d2 = 1; //nicht im stack
    int d1 = 2; //ist nicht im stack gespeichert
    int s2;
    int s3;
    s3 += d2;
    while(s1 != 0){
        s1--;
        s2 += s3;
        s3 += d1;
    }
    return s2;
}