#include <stdio.h>

void string_replace_char(char v[], char find, char replace);

int main(void)
{

        return 0;
}

void string_replace_char(char v[], char find, char replace)
{
        int i;
        while(v != '\0') {
                if (v[i] == find) {
                        v[i] = replace;
                }
                i++;
        }
}