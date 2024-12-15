#include <stdio.h>

unsigned long int fibonacci();
unsigned long int next(void);
void start(unsigned long int seed);

static unsigned long int current = 0;

int fibstop = 0;

int main () {
    static unsigned long int loops = 0;

    unsigned long int seed;
    int loopthreenplus1 = 0;

    static unsigned long int v1;
    static unsigned long int v2;
    static unsigned long int v3;

    fibstop = 50;

    fibonacci();

    printf("ab 48 unsigned long int limit reached. fib(48), fib(49) und fib(50) stimmen also nicht \n\n");

    for (seed = 1; seed <= 10; seed++) {
        printf("3n+1-Folge fuer: %i \n", seed);
        start(seed);

        v1 = 0;
        v2 = 0;
        v3 = 0;

        while (1) {
            if (loops == 0) {
                printf("%lu \n", current);
            } else {
                printf("%lu \n", next());

                if (loopthreenplus1 % 3 == 0) {
                    v1 = current;
                    loopthreenplus1++;
                } else if (loopthreenplus1  % 3 == 1) {
                    v2 = current;
                    loopthreenplus1++;
                } else {
                    v3 = current;
                    loopthreenplus1 = 0;
                }
            }
            
            if ((v1 == 4 && v2 == 2 && v3 == 1) || (v1 == 1 && v2 == 4 && v3 == 2) || (v1 == 2 && v2 == 1 && v3 == 4)) {
                printf("4,2,1 loop reached \n\n");
                break;
            }

            loops++;
        }
        loops = 0;
    }
    return 0;
}

unsigned long int fibonacci(void) {
    static unsigned long int last = 0, current = 0;
    int n = 0, temp = 0;
    while(n >= 0) {
        if (n == fibstop + 1) {
            return current;
        } else if (n == 0) {
            
        } else if (n == 1) {
            current++;
        } else {
            temp = current;
            current = last + current;
            last = temp;
        }
        printf(" %i = %lu \n", n, current);
        n++;
    }
    return current;
}

void start(unsigned long int seed) {
    current = seed;
}

unsigned long int next(void) {
    if (current % 2 == 0) {
            current = current / 2;
    } else {
        current = 3 * current + 1;
    }
    return current;
}