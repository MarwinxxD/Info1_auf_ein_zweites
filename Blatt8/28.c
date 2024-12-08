#include <math.h>
#include <stdio.h>
#define DIM 3
#define x 30 /*so viele Stellen kann die Dezimalzahl innerhalb des Vektors haben*/

int read_vector(double p[]);
void add_vectors(double p1[], double p2[]);
double vector_length(double p[]);
void own_flush();

int main() {
    double p1[DIM], p2[DIM];
    int i = 0;

    if (read_vector(p1) != 0) {
        return 1;
    }
    if (read_vector(p2) != 0) {
        return 1;
    }

    while(i < DIM) {
        printf("%f ", p1[i]);
        i++;
    }
    printf("\n");
    i = 0;
    while(i < DIM) {
        printf("%f ", p2[i]);
        i++;
    }
    printf("\n");
    i = 0;

    add_vectors(p1, p2);

    while(i < DIM) {
        printf("%f ", p1[i]);
        i++;
    }
    printf("\n");

    printf("%f", vector_length(p1));

    return 0;
}

int read_vector(double p[]) {
    /*+1 für die ';' dazwischen*/
    char input[DIM * x + 1];
    int i = 0, n = 0, temp = 0;

    printf("Type three numbers separated by ';': \n");
    scanf("%s", input);

    while(input[i] != '\0') {
        if (n > DIM - 1) {
            printf("Warum gibst du mehr als drei Werte ein, du Dulli \n");
            own_flush();
            return 1;
        } else if (input[i] == ';') {
            p[n++] = temp;
            temp = 0;
        } else {
            temp = (temp * 10) + input[i] - '0';
        }

        i++;
    }
    /* weil man mit der while-Bedingung den letzen value nicht mehr einließt*/
    p[n] = temp;

    own_flush();
    if (n != DIM - 1) {
        printf("Warum gibst du weniger als drei Werte ein, du Dulli \n");
        return 1;
    }
    return 0;
}

void add_vectors(double p1[], double p2[]) {
    int i = 0;

    while(i < DIM) {
        p1[i] = p1[i] + p2[i];
        i++;
    }
}

double vector_length(double p[]) {
    double underoot = 0;
    int i = 0;

    while (i < DIM - 1) {
        underoot += (p[i] * p[i]);
        i++;
    }

    return sqrt(underoot);
}

void own_flush() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}