/*
    ************ Basic Recursion ************

    One Big Problem solution Depend on same type

    2^n

    2^4 = 2 x 2 x 2 x 2
        = 2 x 2^3

    Here 2^4 big problem depend on the 2^3 same type of small problem

    2^n = 2 x 2^n-1

     Requrance Relation: f(n) = 2 x f(n-1)


    1) Factorial
        5! = 5 x 4 x 3 x 2 x 1

           = 5 x 4!
        n! = n x (n-1)!

    Recurance Relation => f(n) = n x f(n-1)


    *********** two things ********
    1) Base case
    2) Requrance Relation

*/

#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{

    if(n == 0)
    {
        return 1;
    }

    /*
    int smallerProblem = fact(n-1);

    int bigerProblem = n * smallerProblem;

    return bigerProblem;
    */

    return n * fact(n - 1);
}

int Power(int n)
{
    if(n == 0)
    {
        return 1;
    }

    return 2 * Power(n - 1);
}
int main()
{
    int n;
    cin >> n;

    int ans = fact(n);

    cout << ans << endl;

    int Power1  = Power(n);

    cout << Power1 << endl;

    return 0;
}
