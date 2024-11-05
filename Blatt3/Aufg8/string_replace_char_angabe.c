#include <stdio.h>

void string_replace_char(char v[], char find, char replace);


int main(void)
{
    char s[] = "Schxkxlade";
    char t[] = "Schokolade";
    char u[] = "xSchokoladex";
    char w[] = "Choc@LATE";
    char x[] = "";
    char y[] = "x";

    string_replace_char(s, 'x', 'o');
    printf("Test 1: %s (Schokolade)\n", s);

    string_replace_char(t, 'x', 'o');
    printf("Test 2: %s (Schokolade)\n", t);

    string_replace_char(u, 'x', 'y');
    printf("Test 3: %s (ySchokoladey)\n", u);

    string_replace_char(w, '@', 'o');
    printf("Test 4: %s (ChocoLATE)\n", w);

    string_replace_char(x, 'x', 'y');
    printf("Test 5: \"%s\" (\"\")\n", x);

    string_replace_char(y, 'x', 'y');
    printf("Test 6: %s (y)\n", y);

    return 0;
}

void string_replace_char(char v[], char find, char replace)
{
    int i = 0;

	while(v[i]){
        if(v[i] == find){
            v[i] = replace;
        }
        i++;
    }
}

