/*
    *********** Bitwise Operator **********

    AND &
    OR |
    XOR ^
    Left Shift <<
    Right Shift >>
    NOT ~


    AND &

    a  b  a&b
    0  0   0
    0  1   0
    1  0   0
    1  1   1


    OR |

    a  b  a|b
    0  0   0
    0  1   1
    1  0   1
    1  1   1


    XOR ^  (important)

    a  b  a|b
    0  0   0
    0  1   1
    1  0   1
    1  1   0


    Example:
    a=5, b=7  => a&b
    a = 101
    b = 111
    _________
        101 => 5

    Bitwise Operators only work on bits ( Binary Represntation)


    Left shift ( << )

    5 << 1

    5 => 00000101

    5 << 1 => 0] => 00001010 => shift left side simply by one bit

    5 << 2
    5 => 00000101 =>
    5 << 2 => 00010100 => shift by two digit become now 20


    --------
    5 << 1
    => 5 * 2^1  Note: pow(2,1) not xor okay

    Remember Formula: a << n => a * 2^n



    Right Shift ( >> )
    5 >> 1
    5 => 00000101
      => 0000010 [1 discard one bit

    5 >> 1 => 00000010

    --------
    a >> n => a / 2^n





    NOT (~)
    Flipping of the All the bit
    ~5
    5 => 00000101
    ~5 => 11111010

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{

    cout << (5 << 1) << " " << (5 << 2) << endl;
    // 10 20
    cout << (5 >> 1) << " " (5 >> 2) << endl;
    // 2 1
    return 0;
}
