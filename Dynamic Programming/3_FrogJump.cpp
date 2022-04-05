
/*
    ********************* Minimum cost to Frog Jump *************

   Frog Jump

   There is a frog an the 1st step of on N stairs long staircase. The frog wants to reach the Nth stair.
   HEIGHT is the height of the (i+1) th stair. if Frog jumps from i th to j th stair. The energy lost in the jump
   is given by HEIGHT[i-1] in the Frog is an ith staircase. he can jump either to (i+1) the stairs or to (i+2) the stair.
   Your task is to find the minimum total energy used by the frog to reach from 1st stair to N th stair


    jump  => |

       10   10   20  => 40
     |      |    |    |
cost 10    20   30   10
     |      |         |
        10      10    => 20

     |           |    |
          20       20  => 40

    Try all possible way
    Recursion


    1) Represent Index
    2) Do all stuffs on that index
    3) take the main ( all stuffs )
        f(n-1) min energy  req of reach (n-1) from 0



    Approach code:

    f( index )
    {
        if( index == 0 ) return 0;

        left = f( index - 1) + abs( arr[index] - arr[index - 1] );

        if( index > 1 )
        right = f( index - 2) + abs( arr[index] - arr[index - 2] );


        // minimum

        return min( left, right );

    }


    ********** Convert Recursion to DP *************
        Memorization
        => Look at the parameter changing ( index )

    1) create DP array n+1
    2) Before returning up to store the result DP[index] = Min(left + right)

    if( DP[index] != -1 ) return DP[index]




    ****************** Tabulation Bottom to up Appr
    1) in the bottom dp[0] = 0
    2) bottom to up fill it up
    3) for(i = 1; i <= n-1; i++)
      {
        f_step = dp[idx-1] + abs(a[idx] - a[idx - 1]);

        if(i > 1)
            s_step = dp[idx - 2] + abs(a[idx] - a[idx-2]);

        dp[idx] = min( f_step, s_setp );
      }

*/
#include<bits/stdc++.h>
using namespace std;

// ********* only Recursion ***********

int frogJump(int index, vector<int> &heights)
{
    if(index == 0) return 0;

    int left = frogJump(index - 1, heights) + abs(heights[index] - heights[index - 1]);

    int right = INT_MAX;

    if(index > 1)
        right = frogJump(index - 2, heights) + abs(heights[index] - heights[index - 2]);

        return min(left, right);
}

// *********** Convert the Recursion to DP Solution ********

int DpF(int idx, vector<int> &heights, vector<int> &dp)
{
    if(idx == 0) return 0;
    // if value has on dp
    if(dp[idx] != -1) return dp[idx];

    int left = DpF(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);

    int right = INT_MAX;

    if(idx > 1)
        right = DpF(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);

        // Before returning store into dp array
    return dp[idx] = min(left, right);
}


int main()
{

    int n = 5;
    vector<int> heights({10, 20, 3, 30, 10});

    // Recursion only
    cout << frogJump(n-1, heights) << endl;


    // convert recursion to DP

    vector<int> dp(n+1, -1);
    cout << DpF(n-1, heights, dp) << endl;



    // *********** Tabulation Approach ************

    vector<int> DP(n+1, 0);
    DP[0] = 0;

    for(int i = 1; i < n; i++)
    {
        int fs = DP[i-1] + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i > 1)
            ss = DP[i-2] + abs(heights[i] - heights[i-2]);

         DP[i] = min(fs, ss);
    }

    cout << DP[n-1] << endl;


    // ************ Space Optimization *********

    int prev = 0;
    int prev2 = 0;

    for(int i = 1; i < n; i++)
    {
        int fs = prev + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;

        if(i > 1)
            ss = prev2 + abs(heights[i] - heights[i-2]);

        int curi = min(fs, ss);

        // next step update
        prev2 = prev;
        prev = curi;
    }

    cout << prev << endl;


    return 0;
}
