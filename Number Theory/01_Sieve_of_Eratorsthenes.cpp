/*
    ************ Sieve of Eratorsthenes **************

    http://www.progkriya.org/gyan/basic-number-theory.html


*/
#include<bits/stdc++.h>
using namespace std;

#define M 1000000
bool marked[M];
void sieve(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (marked[i] == false)   // i is a prime
        {
            for (int j = i * i; j <= n; j += i)
            {
                marked[j] = true;
            }
        }
    }
}
int main()
{
    sieve(30);

    cout << 2 << endl;
    for(int i = 2; i < 30; i++)
    {
        if(marked[i] == false)
        {
            cout << i << endl;
        }

    }

    return 0;
}


