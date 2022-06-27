/*
    ************ Segment Trees ************
     You are given array and Q queries For each Query find out minimum

        arr[7] = {1, 0, 3, 2, 4, 2, 1}
            index 0  1  2  3  4  5  6

        Q = 3

        1 3 => 0
        3 6 => 1
        2 5 => 2

    Brute forces Solution :

        for(int i = 0; i < q; i++)
        {
            cin >> L >> R;
            min = a[L];
            for( j = L; j <= R; j++)
            {
                min = min(min, a[j]);
            }
        }

    TC => O( Q x (R-L + 1) )

    But given all Query  0  n-1
                         0  n-1
                         0  n-1

        TC => O(Q x N )

        almost O(N^2)




    Now Segment come into the picture

    Segment Tree O( log n)


    Useful things of segment tree:
        1) Rang query in given range
        2) find out Max and Min
        3) sum of given range
        4) we can update in the index value and track







*/
#include<bits/stdc++.h>
using namespace std;
int main()
{


    return 0;
}
