/*
    ************ Multiple Recursion call *********
    Time Complicity O(2^n) near Exponential

    f()
    {

        f()
        f()
        f()
    }

    Example:
        Fibonacci number :
        0 1 1 2 3 5 8

    N -> f(N)  => N th Fibonacci number

*/
#include<bits/stdc++.h>
using namespace std;
int fibo(int n)
{
    if(n <= 1)
    {
        return n;
    }

    return fibo(n-1) + fibo(n-2);
}

// another way
int fibo(int n)
{
    if(n <= 1)
    {
        return n;
    }
    int last = fibo(n-1);
    int sLast = fibo(n-2);
    return last + sLast;
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;

    return 0;
}
