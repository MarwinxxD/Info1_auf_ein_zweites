#include <stdio.h>

int string_index_of_sequence(char v[], char find[]);

int main(void)
{

        return 0;
}

int string_index_of_sequence(char v[], char find[])
{
        int i, j;
        int len_v = strlen(v);
        int len_find = strlen(find);

        if (len_find > len_v) {
                return -1;
        }

        for (int i = 0; i <= len_v - len_find; i++) {
                for (j = 0; j < len_find; j++) {
                        if (v[i + j] != find[j]) {
                        break;
                        }
                }
        
                if (j == len_find) {
                return i;
                }
        }
        return -1;
}