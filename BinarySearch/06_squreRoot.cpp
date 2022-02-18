




#include<bits/stdc++.h>
using namespace std;


int sqrtInteger(int num)
{
    int s = 0;
    int e = num;

    long long int mid = s + (e - s)/2;
     int ans = - 1;

    while(s <= e)
    {
        long long int squre = mid * mid;

        if(squre == num)
        {
            return mid;
        }
        else if(squre < num)
        {
         ans = mid;
         s = mid + 1;
        }
        else{
            e = mid - 1;
        }

        mid = s + (e - s)/2;
    }
    return ans;
}


// Fore sqrt after decimal point

double morePrecision(int n, int precision, int tempSol)
{
    double factor = 1;
    double ans = tempSol;

    for(int i = 0; i < precision; i++)
    {
        // .1 => 0.01 => 0.001
        factor = factor / 10;

        for(double j = ans; j*j < n; j = j + factor)
        {
            ans = j;
        }

    }

    return ans;
}


int main()
{
    int num = 10;

    int tempSol = sqrtInteger(num);

    cout << "Answer is " << morePrecision(num, 3, tempSol);

    return 0;
}
