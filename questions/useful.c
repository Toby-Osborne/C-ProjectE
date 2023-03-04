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


void prime_list(uint32_t primes[], uint32_t length) {
    primes[0] = 2;

    uint32_t number = 2;

    uint32_t counter = 1;

    uint64_t prime_sum = 2;

    while (counter < length){
        uint32_t prime = 1;
        for (uint32_t primes_index = 0;primes_index<counter;primes_index++){
            if (!(number%primes[primes_index])) {
                prime = 0;
                break;
            }
            if (primes[primes_index] > (uint64_t)sqrt(number)+1) {
                break;
            }
        }
        if (prime) {
            counter++;
            prime_sum += number;
            primes[counter-1] = number;
        }
        number++;
    }
}
uint32_t factorial_lookup[20] = {1,2,6,24,120,720,5040,40320,362880,3628800};

uint32_t factorial(uint32_t n) {
    if (n<11) return factorial_lookup[n-1];
    uint32_t factorial_number = 3628800;
    for (uint32_t i = 11;i<(n+1);i++) {
        factorial_number*=i;
    }
    return factorial_number;
}

// Should return the number of prime factors
uint32_t prime_factorization(uint64_t number, uint32_t factors[], uint32_t factors_repeats[], uint32_t factors_length, uint32_t primes[], uint32_t primes_length) {
    uint32_t factors_number = 0;
    uint32_t prime_counter = 0; //index in primes list
    uint32_t factors_counter = 0;
    uint32_t last_evaluated_prime = 0;
    while (number > 1) {
        if (!(number%(uint64_t)primes[prime_counter])) {
            number /= (uint64_t)primes[prime_counter];
            if (last_evaluated_prime!=primes[prime_counter]) factors_counter++;
            factors[factors_counter-1] = primes[prime_counter];
            factors_repeats[factors_counter-1]++;
            last_evaluated_prime=primes[prime_counter];
            // printf("%" PRIu32 ", %" PRIu32 ", %" PRIu32 "\n",factors[factors_counter-1],factors_repeats[factors_counter-1], factors_counter-1);
        } else {
            prime_counter++;
        }
    }
    return factors_counter;
}

// This is equivalent of expanding brackets
uint32_t num_factors_from_primes(uint32_t powers[], uint32_t length) {
    uint32_t num_factors=1;
    for (uint32_t i = 0;i<length;i++){
        num_factors*=(powers[i]+1);
        // printf("%" PRIu32 "\n",powers[i]);
    }
    return num_factors;
}

uint32_t collatz(uint64_t n) {
    uint32_t counter = 1;
    while (n!=1){
        if (!(n%2)) {
            n/=2;
        } else {
            n*=3;
            n+=1;
        }
        counter++;
    }
    return counter;
}