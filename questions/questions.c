#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#include <stdlib.h>
#include <time.h>

#include <questions.h>
#include <useful.h>

void Question1() {
    int sum = 0;
    for (uint32_t i = 0;i<1000;i++){
        if (!(i%5)||!(i%3)) sum += i;
    }
    printf("Q1: %d\n",sum);
}

void Question2() {
    uint64_t sum = 0;
    uint32_t fib_previous = 0;
    uint32_t fib_current = 1;
    uint32_t temp;
    while(fib_current<4000000){
        temp = fib_current;
        fib_current += fib_previous;
        fib_previous = temp;
        if(!(fib_current%2)) sum += fib_current;
    }
    printf("Q2: %" PRIu64 "\n",sum);
}

void Question3() {
    srand(time(NULL));   // Initialization, should only be called once.
    uint64_t number = 600851475143;
    uint32_t largest_divisor = 0;
    // I understand that this is stupid
    while (!prime_checker(number)) {
        uint32_t divisor = pollard_rho(number);
        number = number / divisor;
        if (divisor > largest_divisor) largest_divisor = divisor;
    }
    if (number > largest_divisor) largest_divisor = number;
    
    printf("Q3: %" PRIu32 "\n",largest_divisor);
}
        
void Question4() {
    uint32_t largest_palindrome = 0;
    for (uint32_t num_1 = 999; num_1 > 0;num_1--) {
        for (uint32_t num_2 = 999; num_2>0; num_2--) {
            uint32_t len = 0;
            uint32_t product = num_1*num_2;
            uint32_t palindrome = 1;
            uint32_t product_digits[6];
            while (product > 0) {
                product_digits[len] = product%10;
                product /= 10;
                len++;
            }
            for (uint32_t i = 0;i<((len+1)/2);i++) {
                if (product_digits[len-(i+1)] != product_digits[i]) {
                    palindrome = 0;
                }
            }
            if ((palindrome)&&(num_1*num_2 > largest_palindrome)) {
                largest_palindrome = num_1*num_2;
            }
        }
    }
    printf("Q4: %" PRIu32 "\n",largest_palindrome);
}

void Question5() {
    uint32_t primes[11] = {2,3,4,5,8,9,7,11,13,17,19};

}