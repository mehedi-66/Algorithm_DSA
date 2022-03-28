/*
    ******************* Climbing Stairs *************

    you have given a number of stairs. Initially, you are at the 0 th stair,
    and you need to reach the N th stair. Each time you can either climb one step or two steps.
    you are supposed to return the number of distinct way in which you can climb from the 0 th to N th step

  step => 1    1   1
         0 -- 1-- 2 -- 3

  step=>  2      1
        0 --- 2 -- 3

  step=> 1    2
       0 -- 1 --- 3




  1D dp problem

  ********* How to understand the dp problem ******
   1) count the total number of way
   2) Min or Max output ... it hast to multiple way to reach on position to another position
   3) try all possible way



   ************** Remember **********
   1) try to represent the problem in terms to INDEX
   2) do all possible stuffs on that  INDEX all to the problem statement
   3) sum of all staffs -> count all ways
   or min of all


    0 to n

    assume that all is index stairs


            f(n) number of ways

            0 th n-1 =>  1 way
            1 th n-2 =>  => 0 way
            f(n)
            {

                if(n == 0) return 1;
                if(n == 1) return 0;
                // all way

                left = f(n-1);
                right = f(n-2);

                // count all the way

                return left + right ;
            }


*/

#include<bits/stdc++.h>
using namespace std;

int f(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;

    return f(n-1) + f(n-2);



}

int main()
{
    int n;
    cin >> n;

    cout << f(n) << endl;
}
