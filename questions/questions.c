#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#include <stdlib.h>
#include <time.h>

#include <math.h>

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
    uint64_t primes[8] = {2,3,5,7,11,13,17,19};
    uint64_t product = 2*3*5*7*11*13*17*19;
    uint64_t divisible = 0;
    uint64_t value=0;
    while(!divisible){
        divisible = 1;
        value+=product;
        for (uint32_t i = 2;i<21;i++){
            if (value%i) {
                divisible = 0;   
            }
        }
    }
    printf("Q5: %" PRIu64 "\n",value);
}

void Question6() {
    uint64_t sum = 0;
    uint64_t square_sum = 0;
    for (uint64_t i = 1;i<101;i++){
        sum += i;
        square_sum += i*i;
    }
    printf("Q6: %" PRIu64 "\n",(sum*sum)-square_sum);
}

void Question7() {
    uint32_t primes[10001];
    primes[0] = 2;

    uint32_t number = 2;

    uint32_t counter = 1;

    while (counter < 10001){
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
            primes[counter-1] = number;
        }
        number++;
    }
    printf("Q7: %" PRIu32 "\n", primes[10000]);
}

void Question8() {
    char *digits = "73167176531330624919225119674426574742355349194934"
            "96983520312774506326239578318016984801869478851843"
            "85861560789112949495459501737958331952853208805511"
            "12540698747158523863050715693290963295227443043557"
            "66896648950445244523161731856403098711121722383113"
            "62229893423380308135336276614282806444486645238749"
            "30358907296290491560440772390713810515859307960866"
            "70172427121883998797908792274921901699720888093776"
            "65727333001053367881220235421809751254540594752243"
            "52584907711670556013604839586446706324415722155397"
            "53697817977846174064955149290862569321978468622482"
            "83972241375657056057490261407972968652414535100474"
            "82166370484403199890008895243450658541227588666881"
            "16427171479924442928230863465674813919123162824586"
            "17866458359124566529476545682848912883142607690042"
            "24219022671055626321111109370544217506941658960408"
            "07198403850962455444362981230987879927244284909188"
            "84580156166097919133875499200524063689912560717606"
            "05886116467109405077541002256983155200055935729725"
            "71636269561882670428252483600823257530420752963450";
    uint64_t largest = 0;
    for (uint64_t i = 0;i<(1000-12);i++){
        uint64_t local_largest = 1;
        for (uint64_t j = 0;j<13;j++){
            local_largest *= (digits[i+j]-'0');
        }
        if (local_largest > largest) largest = local_largest;
    }
    printf("Q8: %" PRIu64 "\n", largest);
}

void Question9() {
    for (int64_t a = 1;a<1000;a++) {
        if (((1000*(a-500)%(a-1000))==0)&&((-1*a*a+1000*a-500000)%(a-1000)==0)){
            // Thank you algebra for providing a fraction
            int64_t b = (1000*(a-500)/(a-1000));
            int64_t c = (-1*a*a+1000*a-500000)/(a-1000);
            printf("Q9: %" PRId64 "\n",a*b*c);
            return;
        }
    }
}

void Question10() {
    // Future sight cbf to use linked list
    uint32_t primes[148934];
    primes[0] = 2;

    uint32_t number = 2;

    uint32_t counter = 1;

    uint64_t prime_sum = 2;

    while (number < 2000000){
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
    printf("Q10: %" PRIu64 "\n", prime_sum);
}