#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int gcd(unsigned int m, unsigned int n){
    if (n == 0)
        return m;
    else
        return gcd(n, m % n);
}