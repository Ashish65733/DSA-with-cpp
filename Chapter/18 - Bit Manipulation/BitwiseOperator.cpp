#include<iostream>
#include<climits>
#include<vector>
using namespace std;

/*
Bitwise Operator :
    &  : AND
    |  : OR
    ^  : XOR        
    ~  : NOT
    << : Left Shift
    >> : Right Shift
    1's Complement : ~a    -> flip all bits (0 -> 1 , 1 -> 0)
    2's Complement : ~a + 1
    a << b : a * 2^b
    a >> b : a / 2^b
*/

/*
    Bitmasking in C++ involves manipulating individual bits of a number to achieve the desired output. 
It is achieved by generating a bit mask and is used very often for the following operations:

  - Bit Toggle: If a bit is set to 0, it can be toggled to 1 and vice-versa.

  - Bit Setting: If a bit is set to 0 then it's called 'bit is NOT set'. We 
    can set it by performing a toggle operation and change it to 1.This is 
    known as bit setting.

  - Bit Clearing: If a bit is set to 1 then it's called a 'SET-BIT'. We can 
    change it to 0 by performing a toggle operation this is called a - 'Bit-clearing' operation.

  - Checking specific bit is on or off: A bit is said to be on if it's 1 and 
    off if it's 0. For example, an integer can contain multiple bits and we can 
    check if, in that integer, a specific bit is set or not by utilizing bitwise operators.
*/
int main(){
    cout << (~6) << endl; 

    // The most significant bit is 1, so it is a negative number.
    // The most significant bit is 0, so it is a positive number.

    // Flip all the bits, living the MSB bit and then add 1 to it.
    // 6 -> 00000000000000000000000000000110 -> 32 bits
    // ~6 -> 11111111111111111111111111111001 -> Left most is MSB  = 1 (-ve)
    // flip all bits living the MSB = 0000000000000000000000000000110
    // 0000000000000000000000000000110 + 1 = 0000000000000000000000000000111 = 7
    // So answer of (~6) is -7.

    return 0;
}