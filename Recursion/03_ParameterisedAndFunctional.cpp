/*
    ***************** Parameterised and Functional ************

    1) sum of first N number
    2) Functional sum of first N number
        n + f(n-1)

        3 + f(2) => make sense
        2 + f(1)
        1 + f(0)

    3) Factorial of N
        return n * f(n-1)



*/

#include<bits/stdc++.h>
using namespace std;

// parameterize
void sumOfFirst_N_numbers(int i, int sum)
{
    if(i < 1)
    {
        cout << sum << endl;
         return ;
    }

    sumOfFirst_N_numbers(i-1, sum+i);
}


// Functional
int functional(int n)
{
    if(n == 0)
    {
        return 0;
    }
    return n + functional(n-1);
}

// Factorial
int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }

    return  n*factorial(n-1);
}
int main()
{
    int n, sum = 0;
    cin >> n;

   sumOfFirst_N_numbers(n, sum);

   cout << functional(n) << endl;

   cout << factorial(n) << endl;
    return 0;
}
