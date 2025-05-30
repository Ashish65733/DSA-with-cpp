#include<iostream>
#include<climits>
#include<vector>

using namespace std;

/*
Time Complexity: it is the not actual time taken by the program to execute, it is amount of time taken up by an algorithm as a function of input size(n).
                - Number of operations performed by the code
Space Complexity: Amount of extra space occupied by an algorithm as a function of input size(n).

worst case notation: O (Big O)      --> Upper Bound
Avg. case notation: (SymbolOfTheta) (Theta) --> if O(n) == (SymbolOfOmega)(n) then (SymbolOfTheta)(n)
Best case notation: (SymbolOfOmega) (Omega) --> Lower Bound

* Always try to find worst case complexity.

Big O is most used in Competitive Programming.

- Calculating Big O from functions can be done using the following steps:
step 1 : Ignore constants.
step 2 : Take the largest term.

Ex: f(n) = 3n^2 + 2n + 1000
    step 1 : Ignore constants --> n^2+n
    step 2 : Take the largest term --> n^2
    so, Time Complaxity = O(n^2)

    O(1), O(log n), O(n), O(n log n), O(n^2), O(2^n) --> Common Time Complexities

How to approach Qs:
- First solve the question using brute force.
- Then try to optimize the code. (Using time & space complexity)        

* Assume : 10^8  operation in 1s
so, use approach by analysing the given constraints .
n > 10^8 --> O(1) , O(log n)
n <= 10^8 --> O(n)
n <= 10^6 --> O(n log n)
n <= 10^5 --> O(n logn)
n <= 10^4 --> O(n^2)
n <= 500 --> O(n^3)
n <= 25 --> O(2^n) --> minimum you can submit, you can also submit optimized code.

*/
int main(){
    
    return 0;
}