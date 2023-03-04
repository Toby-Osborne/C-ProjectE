#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#include <stdlib.h>
#include <time.h>

#include <math.h>

#include <questions.h>
#include <useful.h>

#include <string.h>

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

void Question11() {
    char grid[1201] = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 "
    "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 "
    "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 "
    "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 "
    "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 "
    "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 "
    "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 "
    "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 "
    "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 "
    "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 "
    "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 "
    "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 "
    "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 "
    "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 "
    "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 "
    "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 "
    "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 "
    "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 "
    "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 "
    "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48 ";
    // Grid Size 20x20
    uint32_t length = 20;
    uint32_t kernel_size = 4;
    uint32_t matrix[length][length];
    // Convert to matrix of numbers
    for (int j = 0;j<length;j++){   // column j
        for (int i = 0;i<length;i++){   // row i
            matrix[i][j] = (grid[3*(20*j+i)]-'0')*10+grid[3*(20*j+i)+1]-'0';
        }
    }
    uint64_t max = 0;
    for (int j = 0;j<(length-kernel_size);j++) {    // column j
        for (int i = 0;i<(length-kernel_size);i++) {    //row i
            for (int m = 0;m<kernel_size;m++) {
                    uint64_t product_vertical = 1;
                    uint64_t product_horizontal = 1;
                for (int k = 0;k<kernel_size;k++) {
                    product_vertical *= matrix[i+m][j+k];
                    product_horizontal *= matrix[i+k][j+m];
                }
                if ((product_vertical > max)||(product_horizontal > max)) {
                    max = (product_vertical > product_horizontal) ? product_vertical : product_horizontal;
                }
            }
            uint64_t product_diagonal = 1;
            uint64_t product_diagonal_n = 1;
            for (int m = 0;m<kernel_size;m++){
                product_diagonal *= matrix[i+m][j+m];
                product_diagonal_n *= matrix[i+m][j+3-m];
            }
            if ((product_diagonal > max)||(product_diagonal_n > max)) {
                max = (product_diagonal > product_diagonal_n) ? product_diagonal : product_diagonal_n;
            }
        }
    }
    printf("Q11: %" PRIu64 "\n", max);
}

void Question12() {
    uint32_t primes_length = 3000;
    uint32_t primes[primes_length];
    prime_list(primes,primes_length);

    uint32_t factors[500] = {0};
    uint32_t factors_repeats[500] = {0};

    uint32_t num_factors_last = 0;
    uint32_t num_factors_current = 0;
    
    uint32_t triangle_index = 1;
    uint64_t triangle_last=1;
    uint64_t triangle_current = 2;

    while (num_factors_current*num_factors_last < 500){
        memset(factors, 0, sizeof(uint32_t)*num_factors_current);
        memset(factors_repeats, 0, sizeof(uint32_t)*num_factors_current);

        triangle_last = triangle_current;
        triangle_current = triangle_index+1;
        if (!(triangle_current%2)) triangle_current/=2;

        uint32_t factors_length_current = prime_factorization(triangle_current, factors, factors_repeats, 500, primes, primes_length);

        num_factors_last = num_factors_current;
        num_factors_current = num_factors_from_primes(factors_repeats, factors_length_current);
        triangle_index++;
    }
    printf("Q12: factors: %" PRIu32 ", number: %" PRIu64 "\n",num_factors_current*num_factors_last,triangle_last*triangle_current);   
}