/*
    ********** Calculating Power using Recursion ************

    a^b ====> is even ==> a^(b/2) * a^(b/2)
        ====> is odd ===> a * (a^(b/2) * a^(b/2) )

*/
#include<bits/stdc++.h>
using namespace std;

int Power(int a, int b)
{
    // base case
    if(b == 0)
    {
        return 1;
    }
    if(b == 1)
    {
        return a;
    }

    // recursive call
    int ans = Power(a, b/2);

    // if b is even
    if(b % 2 == 0)
    {
        return ans * ans;
    }
    else{
        // if b is odd
        return a * ans * ans ;
    }

}

int main()
{
    int a = 2, b = 3;

    cout << Power(a, b);
    return 0;
}
