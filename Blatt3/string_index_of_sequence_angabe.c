#include <stdio.h>
#include <string.h>

int string_index_of_sequence(char v[], char find[]);

int main(void)
{   
    char s[] = "Schokolade";
    char t[] = "oko";
    char u[] = "Sch";
    char v[] = "ade";
    char w[] = "x@z";
    char x[] = "";
    char y[] = "k";
    char z[] = "o";

    int index = string_index_of_sequence(s, t);
    printf("Test 1: Start index of %s in Schokolade: %i (Loesung: 3)\n", t, index);

    index = string_index_of_sequence(s, u);
    printf("Test 2: Start index of %s in Schokolade: %i (Loesung: 0)\n", u, index);
    
    index = string_index_of_sequence(s, v);
    printf("Test 3: Start index of %s in Schokolade: %i (Loesung: 7)\n", v, index);

    index = string_index_of_sequence(s, w);
    printf("Test 4: Start index of %s in Schokolade: %i (Loesung: -1)\n", w, index);

    index = string_index_of_sequence(s, x);
    printf("Test 5: Start index of %s in Schokolade: %i (Loesung: -1)\n", x, index);

    index = string_index_of_sequence(s, y);
    printf("Test 6: Start index of %s in Schokolade: %i (Loesung: 4)\n", y, index);

    index = string_index_of_sequence(s, z);
    printf("Test 7: Start index of %s in Schokolade: %i (Loesung: 3)\n", z, index);
    
    return 0;
}

int string_index_of_sequence(char v[], char find[]){
	/*Fügen Sie hier den Code ein.*/
}
