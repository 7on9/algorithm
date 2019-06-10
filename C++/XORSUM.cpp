/* c++ program to print count of values such
  that n+i = n^i */
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
// function to count number of values less than
// equal to n that satisfy the given condition
void countValues(unsigned long long n)
{
    // unset_bits keeps track of count of un-set
    // bits in binary representation of n
    unsigned long long unset_bits=0;
    while (n)
    {
        if ((n & 1) == 0)
            unset_bits++;
        n=n>>1;
    }
 
    // Return 2 ^ unset_bits
    cout <<(1 << unset_bits);
}
 
// Driver code
int main()
{
    unsigned long long n;
    cin >> n;
    countValues(n);
    return 0;
}
