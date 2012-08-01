#include <stdio.h>
#include <stdlib.h>


int
fibonacci (int number) {
    return 0;
}


int
main (int argc, char *argv[]) {
    if ( argc != 2 ) {
        printf("Usage: fib <integer positive number>");
        return 1;
    }

    printf("%d", fibonacci(atoi(number)));

    return 0;
}
