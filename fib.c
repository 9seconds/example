#include <stdio.h>
#include <stdlib.h>


int
fibonacci (int number) {
    int* cache = (int*) malloc(number+1);
    return calculate_fibonacci(number, cache);
}


static int
calculate_fibonacci (int number, int* cache) {
    if ( cache[number] != -1 ) {
        return cache[number];
    } else {
        cache[number] = calculate_fibonacci(number-1, cache) + calculate_fibonacci(number-2, cache);
        return cache[number];
    }
}


int
main (int argc, char *argv[]) {
    if ( argc != 2 ) {
        printf("Usage: fib <integer positive number>");
        return 1;
    }

    printf("%d\n", fibonacci(atoi(argv[1])));

    return 0;
}
