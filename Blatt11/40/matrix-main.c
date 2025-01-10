#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

#define ERR_MSG(ERR) (ERR) == MATRIX_DIM_ERR ? printf("Dimensionen inkompatibel\n") : printf("Null-Referenz\n")

int is_valid_number(const char *str) {
    while (*str) {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

int main(void) {
    int i, j, k, sum;
    int **A = NULL, **B = NULL, **C = NULL;
    srand(time(NULL));

    printf("Testing matrix_free:\n");
    matrix_free(NULL, 3);
    printf("matrix_free:\t\t\tHandled NULL-pointer correctly\n");
    printf("matrix_free:\t\t\tPassed!\n\n\n");
    printf("Testing matrix_randomize:\n");
    if (matrix_randomize(1, 2, NULL) != MATRIX_MEM_ERR) {
        printf("matrix_randomize:\t\tCheck handling of NULL in matrix_randomize\n");
        return 1;
    }
    printf("matrix_randomize:\t\tNULL-check passed!\n");
    A = matrix_allocate(3, 4);
    if (A == NULL) {
        printf("Memory error, exiting\n");
        return -1;
    }
    if (matrix_randomize(3, 4, A) != MATRIX_VALID) {
        printf("matrix_randomize:\t\tCheck return value in successful run\n");
        matrix_free(A, 3);
        return 1;
    }
    printf("matrix_randomize:\t\treturn value on successful run passed!\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (A[i][j] < 0 || A[i][j] > 9) {
                printf("matrix_randomize:\t\tCheck your randomization boundaries\n");
                matrix_free(A, 3);
                return 1;
            }
        }
    }
    printf("matrix_randomize:\t\tImplementation passed!\n");
    printf("matrix_randomize:\t\tPassed\n\n\n");

    printf("Testing matrix_print:\n");
    if (matrix_print(3, 4, NULL) != MATRIX_MEM_ERR) {
        printf("matrix_print:\t\t\tCheck NULL-handling");
        matrix_free(A, 3);
        return 1;
    }
    printf("matrix_print:\t\t\tNULL-check passed!\n");
    printf("This should be a randomized 3x4 matrix:\n");
    matrix_print(3, 4, A);
    printf("matrix_print:\t\t\tPassed\n");

    printf("Testing matrix_add:\n");
    B = matrix_allocate(4, 4);
    if (B == NULL) {
        printf("Memory error, exiting\n");
        matrix_free(A, 3);
        return -1;
    }
    C = matrix_allocate(4, 4);
    if (C == NULL) {
        printf("Memory error, exiting\n");
        matrix_free(A, 3);
        matrix_free(B, 4);
        return -1;
    }
    matrix_randomize(4, 4, B);
    if (matrix_add(3,4, NULL, 3, 4, B, C) != MATRIX_MEM_ERR || \
        matrix_add(3,4, A, 3, 4, NULL, C) != MATRIX_MEM_ERR || \
        matrix_add(3,4, A, 3, 4, B, NULL) != MATRIX_MEM_ERR) {
        printf("matrix_add:\t\t\tCheck NULL-handling\n");
        matrix_free(A, 3);
        matrix_free(B, 4);
        matrix_free(C, 4);
        return 1;
    }
    printf("matrix_add:\t\t\tNULL-check passed!\n");
    if (matrix_add(3, 4, A, 3, 5, B, C) != MATRIX_DIM_ERR) {
        printf("matrix_add:\t\t\tCheck your dimension checks\n");
        matrix_free(A, 3);
        matrix_free(B, 4);
        matrix_free(C, 4);
        return 1;
    }
    printf("matrix_add:\t\t\tDimension-check passed!\n");
    if (matrix_add(3, 4, A, 3, 4, B, C) != MATRIX_VALID) {
        printf("matrix_add:\t\t\tCheck return value in successful run\n");
        matrix_free(A, 3);
        matrix_free(B, 4);
        matrix_free(C, 4);
        return 1;
    }
    printf("matrix_add:\t\t\tReturn value on successful run passed!\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (C[i][j] != A[i][j] + B[i][j]) {
                printf("matrix_add:\t\t\tCheck implementation, C contains wrong values\n");
                matrix_free(A, 3);
                matrix_free(B, 4);
                matrix_free(C, 4);
                return 1;
            }
        }
    }
    printf("matrix_add:\t\t\tImplementation-check passed!\n");
    printf("matrix_add:\t\t\tPassed!\n\n\n");

    printf("Testing matrix_transpose\n");
    if (matrix_transpose(3, 4, NULL, C) != MATRIX_MEM_ERR ||
        matrix_transpose(3, 4, C, NULL) != MATRIX_MEM_ERR) {
            printf("matrix_transpose:\t\tCheck NULL-Handling\n");
            matrix_free(A, 3);
            matrix_free(B, 4);
            matrix_free(C, 4);
            return 1;
    }
    printf("matrix_transpose:\t\tNULL-check passed!\n");
    if (matrix_transpose(3, 4, A, C) != MATRIX_VALID) {
        printf("matrix_transpose:\t\tCheck return value in successful run\n");
        matrix_free(A, 3);
        matrix_free(B, 4);
        matrix_free(C, 4);
        return 1;
    }
    printf("matrix_transpose:\t\tReturn value on succesful run passed!\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (A[i][j] != C[j][i]) {
                printf("matrix_transpose:\t\tCheck implementation, transposed matrix contains wrong values.\n");
                matrix_free(A, 3);
                matrix_free(B, 4);
                matrix_free(C, 4);
                return 1;
            }
        }
    }
    printf("matrix_transpose:\t\tImplementation-check passed!\n");
    printf("matrix_transpose:\t\tPassed!\n\n\n");

    printf("Testing matrix_multiply:\n");
    if (matrix_multiply(3, 4, NULL, 4, 3, B, C) != MATRIX_MEM_ERR || \
    matrix_multiply(3, 4, A, 4, 3, NULL, C) != MATRIX_MEM_ERR || \
    matrix_multiply(3, 4, A, 4, 3, B, NULL) != MATRIX_MEM_ERR) {
        printf("matrix_multiply:\t\tCheck NULL-handling\n");
        matrix_free(A, 3);
        matrix_free(B, 4);
        matrix_free(C, 4);
        return 1;
    }
    printf("matrix_multiply:\t\tNULL-check passed!\n");
    if (matrix_multiply(3, 4, A, 3, 4, B, C) != MATRIX_DIM_ERR) {
        printf("matrix_multiply:\t\tCheck handling of incompatible dimensions\n");
        matrix_free(A, 3);
        matrix_free(B, 4);
        matrix_free(C, 4);
        return 1;
    }
    printf("matrix_multiply:\t\tDimension-check passed!\n");
    if (matrix_multiply(3, 4, A, 4, 3, B, C) != MATRIX_VALID) {
        printf("matrix_multiply:\t\tCheck return value of successful run\n");
        matrix_free(A, 3);
        matrix_free(B, 4);
        matrix_free(C, 4);
        return 1;
    }
    printf("matrix_multiply:\t\tReturn value on succesful run passed!\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sum = 0;
            for (k = 0; k < 4; k++) {
                sum += A[i][k] * B[k][j];
            }
            if (sum != C[i][j]) {
                printf("matrix_multiply:\t\tCheck implementation, result contains wrong values\n");
                matrix_free(A, 3);
                matrix_free(B, 4);
                matrix_free(C, 4);
                return 1;
            }
        }
    }
    printf("matrix_multiply:\t\tImplementation-check passed!\n");
    printf("matrix_multiply:\t\tPassed!\n\n\n");

    printf("Your implementation seems complete, good job.\n");
    matrix_free(A, 3);
    matrix_free(B, 4);
    matrix_free(C, 4);
    return 0;
}
