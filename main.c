#include <stdio.h>

#define KRED "\x1B[31m"  // color definitions
#define KGRN "\x1B[32m"
#define RESET "\033[0m"  // reset back to normal
#define KREDB "\x1B[41m" // background one
#define KGRNB "\x1B[42m"
#define KBLK  "\x1B[30m" 
//printf colored messages "fail" or "pass" depending on test, reset afterwards
#define mu_assert(pass, fail, test) do { if (!(test)){printf(KRED"%s\n",fail);printf(RESET,"");}\
                                        else{printf(KGRN"%s\n",pass);printf(RESET,"");tests_passed++;} return 0;}while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)
int tests_run    = 0;
int tests_passed = 0;

// Add your function prototypes (delete mine, they're lame anyways):

// EXAMPLES:
int add_numbers(int a, int b);
int multiply_numbers(int a, int b);
int square_number(int a);
int num_of_prime_factors(int a);


// Create your test functions:
// EXAMPLES:
static char * test_1() {
               // message displayed on pass    message displayed on fail     test condition
     mu_assert("PASS: add_numbers(2,3) == 5", "FAIL: add_numbers(2,3) != 5", add_numbers(2,3) == 5);
     return 0;
}

static char * test_2() {
     mu_assert("PASS: multiply_numbers(2,3) == 6", "FAIL: multiply_numbers(2,3) != 6", multiply_numbers(2,3) == 6);
     return 0;
}

static char * test_3() {
     mu_assert("PASS: square_number(2) == 4", "FAIL: square_number(2) != 4", square_number(2) == 4);
     return 0;
}

static char * test_4() {
     mu_assert("PASS: num_of_prime_factors(10) == 3", "FAIL: num_of_prime_factors(10) != 3", num_of_prime_factors(10) == 3);
     return 0;
}

// Add your test here :

static char * all_tests() {
     // EXAMPLES:
     mu_run_test(test_1);
     mu_run_test(test_2);
     mu_run_test(test_3);
     mu_run_test(test_4);
     return 0;
}

// prints how many run, how many failed, percentage bar
void stats(){

     char *result = all_tests();
     printf("Tests run: %d\n", tests_run);
     printf("Tests passed: %d\n", tests_passed);
     int percentage = tests_passed*100/tests_run;
     for (int i = 0; i < (int)percentage/2; i++)
     {
          if(i == (int)percentage/4){
               printf(KBLK"%d%%", percentage);
          }
          printf(KGRNB" ");
     }
     for (int i = 0; i < 50-(int)percentage/2; i++)
     {
          if(i == (100-(int)percentage)/4){
               printf(KBLK"%d%%", 100-(int)percentage);
          }
          printf(KREDB" ");
     }
     printf(RESET,"");
     printf("\n");
}

int main(int argc, char **argv) {
     
     stats();

     // Your code here
     return 0;
}

// Function definitions
// EXAMPLES:
int add_numbers(int a, int b){
     return a+b;
}

int multiply_numbers(int a, int b){
     return a*b;
}

int square_number(int a){
     // this is wrong and it will fail
     return 0;
}

int num_of_prime_factors(int a){
     // this is wrong for 10 and it will fail
     return 1;
}
