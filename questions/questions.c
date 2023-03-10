#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#include <stdlib.h>
#include <time.h>

#include <math.h>

#include <questions.h>
#include <useful.h>
#include <data.h>

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
    uint64_t largest = 0;
    for (uint64_t i = 0;i<(1000-12);i++){
        uint64_t local_largest = 1;
        for (uint64_t j = 0;j<13;j++){
            local_largest *= (Q8_data[i+j]-'0');
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
    // Grid Size 20x20
    uint32_t length = 20;
    uint32_t kernel_size = 4;
    uint32_t matrix[length][length];
    // Convert to matrix of numbers
    for (int j = 0;j<length;j++){   // column j
        for (int i = 0;i<length;i++){   // row i
            matrix[i][j] = (Q11_data[3*(20*j+i)]-'0')*10+Q11_data[3*(20*j+i)+1]-'0';
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

void Question13() {
    uint16_t numbers[100][50];
    uint16_t sum[52] = {0};
    // 0 lsd
    for (uint16_t i = 0;i<100;i++) { // row
        for (uint16_t j = 0;j<50;j++) { //column
            numbers[i][j]=(Q13_data[i*50+j]-'0');
            sum[49-j]+=numbers[i][j];
        }
    }
    for (uint32_t i = 0;i<52;i++){
        uint16_t remainder = sum[i];
        sum[i] = 0;
        uint16_t counter = 0;
        while (remainder > 0) {
            sum[i+counter]+=remainder%10;
            remainder /= 10;
            counter++;
        }
    }
    // It can only go up to 52 digits
    printf("Q13: ");
    for (uint16_t i = 0;i<10;i++){
        printf("%"PRIu16,sum[51-i]);
    }  
    printf("\n");
}

void Question14() {
    uint32_t longest_chain = 0;
    uint32_t longest_seed = 0;
    for (uint64_t i = 1;i<1000000;i++){
        uint32_t chain = collatz(i);
        if (chain>longest_chain) {
            longest_seed=i;
            longest_chain = chain;
        }
    }
    printf("Q14: Chain Length - %" PRIu32 ", Seed - %"PRIu32"\n",longest_chain,longest_seed);
}

void Question15() {
    // Using this sequence you can find that the pattern is:
    // (2*n)! / (n!)^2
    // Out of dedication I will now attempt to solve the above with C using n=20
    // grid_step(0,0,n);
    
    // If you simplify for n=20, you get the below product
    uint64_t product = (uint64_t)pow(2,(10-8))*7*23*5*3*29*31*11*37*39;
    
    printf("Q15: %" PRIu64"\n",product);
}

void Question16() {
    uint16_t digits[500] = {0};
    digits[0] = 1;
    uint16_t msb = 0;
    for (uint16_t i = 0;i<1000;i++){
        for (uint16_t j = 0;j<msb+1;j++){
            digits[j]*=2;
        }
        for (uint16_t j = 0;j<msb+1;j++){
            uint16_t digit = digits[j];
            digits[j] = 0;
            uint16_t counter = 0;
            while(digit > 0) {
                digits[j+counter]+=digit%10;
                digit/=10;
                counter++;
            }
            // Only perform loop up to msb for efficiency
            if(j+counter-1 > msb)msb+=(counter-1);
        }
    }
    uint64_t sum = 0;
    for(uint16_t i = 0;i<500;i++){
        sum+=digits[i];
    }
    printf("Q16: %"PRIu64"\n",sum);
}

void Question17() {
    uint16_t ones[10] = {0,3,3,5,4,4,3,5,5,4};
    uint16_t tens[10] = {0,3,6,6,5,5,5,7,6,6};
    uint16_t teens[10] = {0,6,6,8,8,7,7,9,8,8};
    uint16_t hundereds[10] = {0};
    uint16_t thousands[10] = {0};
    for (uint16_t i = 1;i<10;i++){
        hundereds[i]=ones[i]+10;
        thousands[i]=ones[i]+8;
    }
    uint32_t sum = 0;
    for (uint16_t j = 1;j<=1000;j++){
        
        uint16_t i = j;
        // Process ones/tens together because of teens
        // This process be expanded every 10^3 if required
        if ((i%100>10)&&(i%100<20)){
            sum+=teens[(i%100)-10];
            i/=100;
        } else {
            // Process ones
            sum+=ones[i%10];
            i /= 10;
            sum+=tens[i%10];
            i /= 10;
        }
        // Process hundereds/thousands
        sum+=hundereds[i%10];
        // remove and for regular hundreds
        if ((j%100==0)&&(j%1000>0)) sum-= 3;
        i /= 10;
        sum+=thousands[i%10];
    }
    printf("Q17: %"PRIu32"\n",sum);
}

void Question18() {
    // No Jagged Arrays >:(
    uint32_t triangle[15][15] = {0};
    for (uint16_t i = 0;i<15;i++){  //Row
        for (uint16_t j = 0;j<i+1;j++){ //Column
            uint16_t index = i*(i+1)/2+j;
            triangle[i][j] = (Q18_data[3*index]-'0')*10+(Q18_data[3*index+1]-'0');
        }
    }
    for (uint16_t i = 14;i>0;i--){  //Row
        for (uint16_t j = 0;j<i;j++){ //Column
            triangle[i-1][j] += (triangle[i][j] > triangle[i][j+1]) ? triangle[i][j] : triangle[i][j+1];
        }
    }
    printf("Q18: %"PRIu32"\n",triangle[0][0]);
}

void Question19() {
    uint16_t year = 1901;
    uint16_t day = 1;
    uint16_t weekday = 2;

    uint16_t months_no_leap[12] = {1,32,60,91,121,152,182,213,244,274,305,335};
    uint16_t months_leap[12] = {0,0,1,1,1,1,1,1,1,1,1,1};

    uint16_t counter = 0;

    while (year < 2001) {
        for (uint16_t i = 0;i<12;i++){
            if ((!(weekday))&&(day==(months_no_leap[i]+months_leap[i*((!(year%4)))]))) counter++;
        }
        day++;
        weekday++;
        weekday%=7;
        if (day > 365+((!(year%4)))){
            day = 1;
            year++;
        }
    }
    printf("Q19: %"PRIu16"\n",counter);
}

void Question20() {
    uint16_t digits[163] = {0};
    digits[0] = 1;
    uint16_t msb = 0;
    for (uint16_t i = 2;i<101;i++){
        for (uint16_t j = 0;j<msb+1;j++){
            digits[j]*=i;
        }
        for (uint16_t j = 0;j<msb+1;j++){
            uint16_t digit = digits[j];
            digits[j]=0;
            uint16_t counter = 0;
            while(digit>0){
                digits[j+counter]+=digit%10;
                digit/=10;
                if (j+counter==msb) msb++;
                counter++;
            }
        }
    }
    uint16_t sum = 0;
    for (uint16_t i = 162;i>0;i--){
        sum+=digits[i];
    }
    printf("Q20: %"PRIu16"\n",sum);
}

void Question21() {
    uint32_t primes_length = 10000;
    uint32_t primes[primes_length];
    memset(primes,0,sizeof(uint32_t)*primes_length);

    // Generate prime list
    prime_list(primes,10000);

    uint16_t amicable[10000] = {0}; // 0 = not checked yet

    uint32_t sum_all_amicable = 0;

    for (int i = 220;i<10001;i++) {
        if(amicable[i]) continue;
        uint32_t sum_1=sum_factors(i,primes,primes_length)-i;
        uint32_t sum_2=sum_factors(sum_1,primes,primes_length)-sum_1;
        if ((sum_2==i)&&(i!=sum_1)){    // make sure that the numbers aren't equal
            amicable[i]++;
            amicable[sum_1]++;
            sum_all_amicable+=(i+sum_1);
        }
    }
    printf("Q21: %"PRIu32"\n",sum_all_amicable);
}

// This requires a linked list...
void Question22() {
    FILE *fp;
    char c;
    fp = fopen ("./../files/Q22.txt", "r");
    int name_counter = 0;
    uint128_t names[5163] = {0};
    char * names_char = (char *)names;

    int byte_counter = -1;

    while(1)
    {
        c = fgetc ( fp );
        if (c == EOF) break;

        if (c == ',') continue;
        if (c == '"') {
            if (byte_counter < 0) {
                byte_counter++;
            } else {
                byte_counter = -1;
                name_counter++;
            }
            continue;
        }
        if (name_counter >= 0) {
            *(names_char+(sizeof(char)*byte_counter + sizeof(uint128_t)*name_counter)) = c;
            byte_counter++;
        }
    }

    qsort(names, 5163, sizeof(uint128_t), compare_function);

    uint32_t local_sum = 0;
    uint64_t global_sum = 0;

    for (int i = 0;i<5163;i++){
        for (int j = 0;j<sizeof(uint128_t)/sizeof(char);j++){
            c = *(uint8_t*)(names_char+i*sizeof(uint128_t)+j*sizeof(char));
            if (c==0) break;
            local_sum+= c -'A'+1;
        }
        global_sum+=(uint64_t)local_sum*(i+1);
        local_sum=0;
    }

    printf("Q22: %"PRIu64"\n",global_sum);
    fclose (fp) ;
}