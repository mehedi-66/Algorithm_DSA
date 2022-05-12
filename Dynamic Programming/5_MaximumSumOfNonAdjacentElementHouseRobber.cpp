/*
    ************** Maximum Sum of Non Adjacent Elements ****************

    You are given an array list of N integers. you are supposed to return the maximum sum of
    subsequence with the constraint that no two elements are adjacent in the given array list

    1) you can pick a element which is not adj

    Example:
    1 2 4

    output : 1 4 => 5

    2 1 4 9

    output: 2 9 => 11

    ****** Approach *********

    Time Complicity => O( 2^n )

    pick and Not Pick => recursion

    1) Lets try out all subsequences
    2) pick the one with the Maximum sum


    ***** way to write recursion *****
    1) Index
    2) do all stuffs on the index
    3) return Best ans

    => pick subsequences with no adjacency element

    => f( idx ) => maximum sum => ( 0 ---- index )


       f( idx )
       {
          if( idx == 0 ) return a[ idx ]

          if( idx < 0 ) return 0;

            // take the element into my subsequence a[idx]

          pick = a[idx] + f( idx - 2) ;

          notPick = 0 + f( idx - 1) ;

          return max( pick , notPick ) ;

       }

    ************** Recursion to DP **********
    Time Complicity => O(n)
    Space Complicity => O(n) +  O(n)

    if Recursion has overlapping sub problem then we can Memorization

                2  1  4  9
        index   0  1  2  3

                    f(3)
                 /       \
                /         \
            f(1)         f(2)
           /   \           /  \
          /     \        f(0)  f(1)  overlap
        f(-1)    f(0)



    ************ DP Memorization to Tabulation ***********
    Time Complicity => O( n )
    Space Complicity => O( n)

    1) declare dp array
    2) base case dp[0] = 0;
    3) if neg = 0 => index

    for( i = 1; i < n; i++)
    {
        take = a[idx];

        if( i > 1 ) take += dp[i - 2];

        notTake = 0 + d[i - 1];

        dp[i] = max( take, notTake )
    }



    ********************* Space Optimization ***************
    Time Complicity => O( n )
    Space Complicity => O( 1 )

    (i-2)(i-1) i
    x x x x x x x

    previous two value is needed



 */

 #include<bits/stdc++.h>
 using namespace std;

 int fRecursion(int idx, vector<int> &nums)
 {
     if(idx == 0) return nums[idx];

     if(idx < 0 ) return 0;

     // Pick
     // add to my subsequence and call
     int pick = nums[idx] + fRecursion(idx - 2, nums);

     // Not Pick
     // not added into my subsequence

     int notPick = 0 + fRecursion(idx-1, nums);

     // return best
     return max(pick , notPick);
 }

 int fDp(int idx, vector<int> &nums, vector<int> &dp)
 {

     if(idx == 0) return nums[idx];

     if(idx < 0) return 0;

     // if value has then return that one
     if(dp[idx] != -1) return dp[idx];

     int pick = nums[idx]  + fDp(idx - 2, nums, dp);

     int notPick = 0 + fDp(idx - 1, nums, dp);

     // Before returning store into DP array
     return dp[idx] = max(pick, notPick);


 }

 int main()
 {

    vector<int> nums({2, 1, 4, 9});

    int n = nums.size();

    cout << fRecursion(n-1, nums) << endl;

    // *********** DP solution ********

    vector<int> dp(n, -1);

    cout << fDp(n-1, nums, dp) << endl;






    // ************* Tabulation ************
    // Button to up

    vector<int> DP(n, 0);
    DP[0] = nums[0];
    int neg = 0;

    for(int i = 1; i < n; i++)
    {
        int take = nums[i];
        if(i > 1)
            take += DP[i - 2];

       int notTake = 0 + DP[i - 1];

        DP[i] = max(take, notTake);

    }

    cout << DP[n-1] << endl;






    // *************** Space Optimization *********

       // prev2 prev   i

    int prev = nums[0];
    int prev2 = 0;

    for(int i = 1; i < n; i++)
    {
        int take = nums[i];

        if(i > 1)
            take += prev2;

        int notTake = 0 + prev;

        int curi = max( take, notTake);
        prev2 = prev;
        prev = curi;
    }

    cout << prev  << endl;

     return 0;
 }
