/*
    ****************** Frog Jump with K Distance **************

    only 0 to n-1 index what is the minimum energy needed

    frog => i => i+1
            i => i+2

    f( idx )
    {
      if( idx == 0 ) return 0;

      left = f( idx - 1 ) + abs( heights[idx] - heights[idx-1] ) ;

      right = INT_MAX;
      if( idx > 1)
        right = f( idx - 2) + abs( heights[idx] - heights[idx - 2] );

        return min( left, right );
    }



   ******** But jump K th index *********
   your are allow to jump
    => i+1
       i+2
       i+3
       i+4  => jump
       ...
       ..
       ..


    First rule of right recursive solution :
    1) represent on Index
    2) do all stuff on that index
    3) return minimum results

    Time Complicity => ( O(n) * K)
    Space Complicity => O(n) + O(n)

    f( idx )
    {
        if( idx == 0 ) return 0;

        minSteps = INT_MIN;

        // jump k times one after another

        for( int j = 1; j <= k; j++)
        {
            // jump one by one 1, 2, 3, 4

            if( idx - j >= 0)
            {
                 jump = f( idx - j ) + abs( a[idx] - a[idx-j] ) ;

                 minSteps = min( minSteps, jump );

            }

        }

        return minSteps;

    }



    **************** Tabulation  Approach **************

    Time Complicity => O(n x K)
    Space Complicity => O(N)

    int dp[n+1];
    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
          minSteps = INT_MAX;

          for(int j = 1; j <= k; j++)
          {
             if(i - j >= 0)
             {
                jump = dp[i-j] + abs( a[idx] - a[idx -j] );
                minSteps = min( minSteps, jump);
             }
          }
          dp[i] = minSteps;
    }


*/
