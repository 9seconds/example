#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define POSITION(number)     ( (number)-2 )
#define UNKNOWN              ( -1 )
#define CACHE_SIZE(elements) ( sizeof(int)*( (elements)-1 ) )


static int
calculate_fibonacci (int number, int* cache);


static int calculate_fibonacci (int number, int* cache);


int
fibonacci (int number) {
    int* cache;
    int  result;

    if ( number < 2 )
        return number;

    cache = memset(
        (int*) malloc(CACHE_SIZE(number)),
        UNKNOWN,
        CACHE_SIZE(number)
    );

    result = calculate_fibonacci(number, cache);

    if ( cache != NULL ) {
        free(cache);
        cache = NULL;
    }
    return result;
}


static int
calculate_fibonacci (int number, int* cache) {
    if ( number < 2 )
        return number;

    if ( cache[POSITION(number)] == UNKNOWN )
        cache[POSITION(number)] = calculate_fibonacci(number-1, cache) + calculate_fibonacci(number-2, cache);

    return cache[POSITION(number)];
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
