/*
    *************** Count the Ways to Reach the Nth Stairs ************


*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arr[46];

    int climbStairs(int n)
    {

        for(int i = 0; i < 46; i++)
            arr[i] = -1;

        return solve(n);

    }

    int solve(int n)
    {
        if(n == 1) return 1;
        if(n == 2) return 2;

        if(arr[n] != -1)
        {
            return arr[n];
        }

        return arr[n] = solve(n-1) + solve(n-2);
    }
};

int main()
{
    Solution obj = Solution();
    cout << obj.climbStairs(5) << endl;

}
