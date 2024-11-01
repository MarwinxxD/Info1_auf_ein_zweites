#include <stdio.h>

void string_tolower(char v[]);

int main(void)
{
    char s[] = "SchOkoLaDE";
    char t[] = "SCHOKOLADE";
    char u[] = "schokolade";
    char v[] = "";
    char w[] = "Ch0c0!@#LATE";

    string_tolower(s);
    printf("Test 1: %s (schokolade)\n", s);

    string_tolower(t);
    printf("Test 2: %s (schokolade)\n", t);

    string_tolower(u);
    printf("Test 3: %s (schokolade)\n", u);

    string_tolower(v);
    printf("Test 4: \"%s\" (\"\")\n", v);

    string_tolower(w);
    printf("Test 5: %s (ch0c0!@#late)\n", w);

    return 0;
}

void string_tolower(char v[]){
	 
}