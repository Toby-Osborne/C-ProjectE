#include <useful.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>


uint64_t euclidean_algorithm(uint64_t num_1, uint64_t num_2) {
    if (num_1 < num_2) {
        uint64_t temp = num_1;
        num_1 = num_2;
        num_2 = temp;
    }

    while ((num_1>0)&&(num_2>0)) {
        uint64_t remainder = num_1 % num_2;
        num_1 = num_2;
        num_2 = remainder;
    }
    return num_1;
}

uint64_t g(uint64_t x, uint64_t c, uint64_t n) {
    return ((uint128_t)x*(uint128_t)x + (uint128_t)c) % (uint128_t)n;
}

uint64_t pollard_rho(uint64_t num) {
    uint64_t x = (rand()%(num-2))+2;
    uint64_t y = x;
    uint64_t c = (rand()%(num-1))+1;
    uint64_t d = 1;

    while (d == 1) {
        x = g(x,c,num);
        y = g(g(y,c,num),c,num);
        d = euclidean_algorithm((x > y ? x - y : y - x),num);
        if(d==num) return pollard_rho(num);
    }
    return d;
}

uint32_t prime_checker(uint64_t num) {
    if (!(num%2)) return 0;
    for (uint32_t i = 3;i<(uint32_t) sqrt((double)num);i+=2) {
        if (!(num%i)) return 0;
    }
    return 1;
}