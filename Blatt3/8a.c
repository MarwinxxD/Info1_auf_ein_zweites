#include <stdio.h>

void string_tolower(char v[]);

int main(void)
{

        return 0;
}

void string_tolower(char v[])
{
        int i;
        while (v[i] != '\0') {
                if (v[i] >= 'A' && v[i] <= 'Z') { 
                        v[i] = v[i] + ('a' - 'A');
                }
                i++;
        }
}