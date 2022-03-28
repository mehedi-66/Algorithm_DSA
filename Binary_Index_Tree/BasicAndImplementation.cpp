/*
            *************** Binary  Index Tree  or BIT tree ************

            always Binary Index Tree start from 1

            idx => 1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16
            f   => 1  0  2  1  1  3  0  4  2  5   2   2   3   1   0   2
            c   => 1  1  3  4  5  8  8 12 14 19  21  23  26   27  27  29
           tree => 1  1  2  4  1  4  0 12  2  7  2   11   3  4    0   29


           how tree cover

            idx => 1   2     3    4    5   6     7    8     9    10      11    12     13     14      15     16
           tree => 1  1..2   3  1..4   5  5..6   7  1..8    9   9..10    11   9..12   13   13..14    15   1...16


            IDEA:

           any number and its power set =>

                2^2   2^1  2^0
           5 => 1        0   1

                2^3  2^2  2^1  2^0
          10 => 1    0    1    0

          Right most 1 in 2^1 = 2 That means => 2 index sum store in index => 10
          that is 9 and 10 index sum

               2^2  2^1  2^0
          4 => 1    0    0

          Right most 1 => 2^2 => 4  That means => 4 index sum store => 1 to 4


    ****** How we get sum 1 to 10 index :
          1) always prefix sum given or calculated
          2) Query(1, 10)
          3) Query(10) given this way


          Query(10)
          range =>  [9,10]      [1,8 ]
          sum   =>  t[10]   +    t[8]  => 7 + 12 => 19


        Query(11)
        range  =>  [11]       [9, 10]     [1, 8]
        sum    =>  t[11]   +   t[10]    +  t[8]
                     2      +    7       +   12  => 21

   *******How we jump one index to next previous index

            flip right most digit => 1 -> 0

            11 => 1 0 1 1
                  1 0 1 0

            8 => 1 0 0 0
             =>  0 0 0 0

    *********  Update

             Update(index, value)

             Update(5, 3)

            1) forward all affected index update make happend

            2^s compliment
            5 => 101
                 010
                  +1
                ---------
                 011

        now and 5 & (2^s compliment)
          5  => 101
         -5     011
            -------
               001

       now add  =>  5 + (5 & -5)

                101
              + 001
            -----------
                110 => 6


*/
#include<bits/stdc++.h>
int arr[10000];
int tree[10000];

// initially all tree index are zero
// one by one element come and affected index updated

int query(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        // back side go
        idx -= (idx & -idx);
    }
    return sum;
}


void update(int idx, int val, int n)
{
    while(idx <= n)
    {
        tree[idx] += val;
        // forward go
        idx += (idx & -idx);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        cin >> arr[i];
        // this way we generate the BIT tree
        update(i, arr[i], n);
    }


    // update the BIT tree
    update(5, 3, n);

    return 0;
}
