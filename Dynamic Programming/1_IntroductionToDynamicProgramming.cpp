/*
    ****************** Dynamic Programming *************

    " those who can not remember the past
      are condemned to repeat it"
                               DP


    1) Tabulation  => Bottom up
    2) memorization => Top Down


    ***** Fibonacci number ****
    => 0 1 1 2 3 5 8 13 21

    f(n) = f(n-1) + f(n-2)

    f(4) = f(3) + f(2)

    **** code:
        f(n)
        {
            if(n <= 1)
            {
                return n;
            }

            return f(n-1) + f(n-2);
        }

    ******************************** Generate recursion tree to see  ******************
                            f(5)
                           /    \
                          /      \
                       f(4)      f(3)
                     /    #
                    /      #
                 f(3)      f(2)  here we  see again f(2) call for calculate  THIS is Overlapping Sub problem
                /    \
               /      \
         1  f(2)      f(1)
           /   \
          /     \
      1 f(1)    f(0) 0


          return

    We tends to store value of sub problem like
    when ever f(2) calculate then the reuse the previous value


    Recursion to Memorization
    1) create DP[n+1] for n number subProblem to solve => fill with -1

    2) Store DP[n] = f(n-1) + f(n-2); .. return subProblem value

    3) check if subProblem solve previously or Not => if(DP[n] != -1)


    ******** Code Demo *****

    int DP[N+1] = {-1 all}

    f(n)
    {
        if(n <= 1)
        {
            return n;
        }

        if(DP[n] != -1)
        {
            return DP[n];
        }
        return DP[n] = f(n-1) + f(n-2);
    }


    Time Complicity => O(n)
    space Complicity =>  O(n) + O(n)
                        stack + array dp




    ************* Recursion solution to Tabulation **********
    Bottom up

    1) Base case to required Ans
    2) dp[n+1] create
    3) Base case => dp[0] = 0, d[1] = 1
    4)  for( i = 2; i <= n; i++){

        dp[i] = dp[i-1] + dp[i-2];
    }


    Time Complicity => O(n)
    Space Complicity => O(n) dp array


    ***** Reduce space
    int first = 0, scond = 0;
    for(i=2; i <= n; i++)
    {
        sum = first + second;
        first = second;
        second = sum;
    }

    Time Complicity => O(n)
    Space Complicity => o(1)

*/

#include<bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &dp)
{
    if(n <= 1)
    {
        return n;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = f(n-1, dp) + f(n-2, dp);
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    // memset(dp, -1, sizeof dp);


    // memorization method call
    cout << f(n, dp) << endl;





    // Tabulation method

    int first = 0, second = 1, sum;
    for(int i = 2; i <= n; i++)
    {
        sum = first + second;
        first = second;
        second = sum;
    }
    cout << sum << endl;


    return 0;
}
