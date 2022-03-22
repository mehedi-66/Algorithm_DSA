/*
    ************** BitMasking **********

    Q1: playing with Bits

        how many number of bit in between this

        Example: a=10, b=15; a -> b (inclusive)

            a = 10 => 1010 => 2
                11 => 1011 => 3
                12 => 1100 => 2
                13 => 1101 => 3
                14 => 1110 => 3
                15 => 1111 => 4
                    ______
                      17 bit
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int coutnSetBits(int n)
{
    int cnt = 0;
    while(n > 0)
    {
        cnt += (n&1);
        n = n >> 1;
    }
    return cnt;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll test; cin >> test;
    while(test--)
    {
        int a, b; cin >> a >> b;
        int cnt = 0;

        for(i = a; i <= b; i++)
        {
            // check if the no is event is less than b
            if( (i&1) == 0 && i < b)
            {
                cnt += 2 * countSetBits(i) + 1;
                i++;
                continue;
            }
        }
        cout << cnt << "\n";
    }



    return 0;
}
