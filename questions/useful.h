#include <stdint.h>

typedef unsigned __int128 uint128_t;

uint64_t euclidean_algorithm(uint64_t num_1, uint64_t num_2);

uint64_t pollard_rho(uint64_t num);

uint32_t prime_checker(uint64_t num);

void prime_list(uint32_t primes[], uint32_t length);

uint32_t factorial(uint32_t n);

uint32_t num_factors_from_primes(uint32_t powers[], uint32_t length);

uint32_t prime_factorization(uint64_t number, uint32_t factors[], uint32_t factors_repeats[], uint32_t factors_length, uint32_t primes[], uint32_t primes_length);

uint32_t collatz(uint64_t n);