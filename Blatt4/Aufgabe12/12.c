#include <stdio.h>

int equalsNull(int s1, int s2);
int square_of(int s1);
int sum_n_ung_zahlen(int s1);

int main(void)
{

        return 0;
}

int equalsNull(int s1, int s2) 
{
        //aber mit komischen Befehlen. Macht so keinen Sinn.
        if(s1 == 0) {
                s1 += s1;
                return s1;
        } else {
                return s2;
                }
        
}

int square_of(int s1)
{
        int s2 = 0;
        int zähler = s1; //zähler ist S3
        while(zähler != 0) {
                zähler -= 1;
                s2 += s1;
        }
        return s2;

}

int sum_n_ung_zahlen(int n)
{

        int s2, addierer; //addierer ist s3
        addierer = 1; 
        while(n != 0)
        {
                n -= 1;
                s2 += addierer;
                addierer += 2;
        }
        return s2;
}