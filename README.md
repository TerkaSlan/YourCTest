# YourCTest
Yes, you can create a testing "framework" within your `main.c`.

Suitable for beginners to testing and/or C - no header files or knowledge of autotools required, the framework is a part of your C code.

This project is basically an enhanced, more colorful version of:
http://www.jera.com/techinfo/jtns/jtn002.html

## How it works:

Download the main.c file, which already contains some examples

Create a function at the bottom, add a function prototype  at the top:
  `int my_func(int a);`

Write the test with messages for pass and fail scenarios and the test condition:
```  
  static char * my_test() {
     mu_assert("PASS: my_func(2) == 2", "FAIL: my_func(2) != 2", my_func(2) == 2);
     return 0;
  }
```
Add your test to the function that checks all the tests:
```  
  static char * all_tests() {
     mu_run_test(test_1);
     mu_run_test(test_2);
     mu_run_test(my_test);
     return 0;
}
```
Compile as you would your regular C code:
  `gcc main.c -o test`

Run `./test` and see what fails and what passes:
![test_result](http://i64.tinypic.com/25p1jc6.png)

That's all, feel free to play with it and create your personalised, even cooler one!

