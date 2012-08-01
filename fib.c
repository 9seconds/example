#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define POSITION(number)      ( (number)-2 )
#define UNKNOWN               ( -1 )
#define CACHE_SIZE(elements)  ( sizeof(int)*( (elements)-1 ) )
#define EVEN(number)          ( !((number) % 2) )
#define TRIVIAL_CHECK(number) { if ( (number) < 3 ) return (number); }




#ifdef FIBCACHED



static int
calculate_fibonacci (int number, int* cache) {
    TRIVIAL_CHECK(number)

    if ( cache[POSITION(number)] == UNKNOWN )
        cache[POSITION(number)] = calculate_fibonacci(number-1, cache) + calculate_fibonacci(number-2, cache);

    return cache[POSITION(number)];
}


int
fibonacci (int number) {
    int* cache;
    int  result;

    TRIVIAL_CHECK(number)

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



#elif FIBALG



static int
calculate_fibonacci (int a, int b, int p, int q, int count) {
    if ( !count )
        return b;
    else
        return ( EVEN(count) )
            ? calculate_fibonacci(a, b, p*p+q*q, q*(2*p+q), count/2)
            : calculate_fibonacci(q*(b+a)+a*p, b*p+a*q, p, q, count-1);
}


int
fibonacci (int number) {
    TRIVIAL_CHECK(number)

    return calculate_fibonacci(1, 0, 0, 1, number);
}



#elif FIBITER


int
fibonacci (int number) {
    int left, right, i, tmp;

    TRIVIAL_CHECK(number)

    left  = 2;
    right = 1;
    for ( i=3; i<number; ++i ) {
        tmp   = left + right;
        right = left;
        left  = tmp;
    }

    return left + right;
}



#else



int
fibonacci (int number) {
    TRIVIAL_CHECK(number)

    return fibonacci(number-1) + fibonacci(number-2);
}



#endif



int
main (int argc, char *argv[]) {
    if ( argc != 2 ) {
        printf("Usage: fib <integer positive number>");
        return 1;
    }

    printf("%d\n", fibonacci(atoi(argv[1])));

    return 0;
}
