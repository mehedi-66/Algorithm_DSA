/*
279. Perfect Squares

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words,
it is the product of some integer with itself.

For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.


Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.


Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.


Approach A:

        Number axis draw and ... A ------ B  try to partition  such a way  each part consider as ... square





*/
class Solution {
public:


    vector<int> dp;    // DP table



    int solve(int n)
    {
        if(n <= 3)
            return n;

        if(dp[n] != -1)      // DP check
            return dp[n];

        int ans = n;
        for(int i = 1; i*i <= n; i++)
        {
            ans = min(ans, 1 + solve(n - i*i));
        }

        dp[n] = ans;      // update DP table

        return ans;
    }






    int numSquares(int n) {

        dp.resize(n+1, -1);         // DP table initial

        int ans = solve(n);
        return ans;
    }
};

