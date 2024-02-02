/*---
    CS 211 Spring 2023 - Week 03 Lab
    A Review of Recursion in C++

    David C. Tuttle
    Last Modified: 31 Jan 2023
---*/

// CS 211 Spring 2024 - Week 03 Lab
// Blake Culbertson and Dean Callahan

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

/*-----
  function: sumDownBy2: unsigned int -> int

  Purpose: to compute, given a non-negative integer n, the sum
           of all positive integers n, n-2, n-4, etc

  expects: An unsigned (non-negative) integer

  returns: The sum of all positive integers n, n-2, n-4, etc.


-----*/

unsigned int sumDownBy2(unsigned int n) {
  unsigned int total = 0;
  total += n;
  if(n > 1){
    total += sumDownBy2(n - 2);
  } else {
    return n;
  }
  return total;
}

/*-----
  function: recursiveMult: unsigned int, unsigned int -> int

  Purpose: to compute, given non-negative integers j & k,
           their product without using the multiplication operator

  expects: Two unsigned (non-negative) integers

  returns: The product of those integers

-----*/

int recursiveMult(unsigned int j, unsigned int k) {
    // REPLACE THIS LINE OF CODE
    int kTotal=0;    
    if(j==0){
      return 0;
    }
    else{
      kTotal += k;
      kTotal+=recursiveMult(j-1,k);
    }
    return kTotal;
}

/*-----
  function: geometricSum: unsigned int -> double

  Purpose: to compute, given a non-negative integer n, the sum
           of 1 + 1/2 + 1/4 + ... + 1/(2^n)

  expects: An unsigned (non-negative) integer

  returns: The sum of 1 + 1/2 + 1/4 + ... + 1/(2^n)

-----*/

double geometricSum(unsigned int n) {
    double total = 0.0;
    double temp = 0.5;
    if(n == 0){
      return 1;
    }
    for(int i = 0; i < n - 1; i++){
      temp *= 0.5;
    }
    total += temp;
    if(geometricSum(n-1) == 0){
      return total;
    } else{
      total += geometricSum(n - 1);
    }
    return total;
}


/***  TAIL RECURSION VERSION OF geometricSum ***/

/* TAIL RECURSION is a way of writing recusion so that   */
/* the recursion occurs at the very end.  Many compilers */
/* can recognize tail recursion and perform it in a very */
/* efficient manner.  We discuss this in class :-).      */

double geometricSumTail(unsigned int n) {
    // REPLACE THIS LINE OF CODE
    return 0.0;
}


