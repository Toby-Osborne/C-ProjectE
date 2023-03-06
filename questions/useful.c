#include <useful.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include <string.h>


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

void prime_sieve(uint16_t primes[], uint32_t length) {
    memset(primes,0,sizeof(uint16_t)*2);
    for (uint32_t i = 2;i<length;i++) primes[i] = 1;
    for (uint32_t i = 2;i<(uint32_t)sqrt(length);i++){
        if (primes[i]) {
            uint32_t value = 2*i;
            while(value<length){
                primes[value]=0;
                value+=i;
            }
        }
    }
}

uint64_t factorial(uint16_t n) {
    uint64_t factorial_number = 1;
    for (uint64_t i = 1;i<(n+1);i++) {
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


uint64_t permutations = 0;

void grid_step(uint16_t a,uint16_t b, uint16_t size) {
    
    if ((a==size)&&(b==size)) {
        permutations++;
        // printf("a = %"PRIu16"b = %"PRIu16"\n",a,b);
        // printf("Permutations++: %"PRIu32"\n",permutations);
    } else {
        if (a<size) {
            grid_step(a+1,b,size);
        }
        if (b<size) {
            grid_step(a,b+1,size);
        }
    }
    return;
}

uint64_t get_permutations() {
    return permutations;
}

uint16_t factors_from_primes(uint32_t primes[],uint32_t prime_repeats[],uint16_t prime_length,uint32_t all_factors[]){
    for (int i = 0;i<prime_repeats[0]+1;i++){
        all_factors[i]=(uint16_t)pow(primes[0],i);
    }
    //Index should at any time give the number of elements in the list
    uint16_t index = prime_repeats[0]+1;
    for (int i = 1;i<prime_length;i++) {    //for every prime
        for (int j = 1;j<prime_repeats[i]+1;j++) {  //for every non-zero power of that prime
            for (int k = 0;k<index;k++){                    //for every element in the list previously
                all_factors[index*j+k]=(uint16_t)pow(primes[i],j)*all_factors[k];
            }
        }
        index=((index)*(prime_repeats[i]+1));
    }
    return index;
}

// Only defined once for speed
uint32_t prime_factors[10000];
uint32_t prime_factors_repeats[10000];

uint32_t sum_factors(uint32_t num,uint32_t primes[],uint32_t primes_length) {
    memset(prime_factors,0,sizeof(uint32_t)*10000);
    memset(prime_factors_repeats,0,sizeof(uint32_t)*10000);

    uint16_t num_prime_factors = prime_factorization(num,prime_factors,prime_factors_repeats,10000,primes,primes_length);
    uint16_t num_factors = num_factors_from_primes(prime_factors_repeats,num_prime_factors);
    uint32_t all_factors[num_factors];
    memset(all_factors,0,sizeof(uint16_t)*num_factors);
    factors_from_primes(prime_factors,prime_factors_repeats,num_prime_factors,all_factors);
    uint32_t sum = 0;
    for (int j = 0;j<num_factors;j++){
        sum+=all_factors[j];
    }
    return sum;
}