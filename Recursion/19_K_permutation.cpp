/*
    ********************* K th permutation Sequence **************

    The set {1, 2, 3, ......, n} contains a total of n! unique permutations.
    By listing and labeling all of the permutations in order, we get the following sequence for n = 3

    Example:
    n = 3
    123
    132
    213
    231
    312
    321

    Given n and k, return the k th permutation sequence


    Approach:
            Brute-force
            *** 1) Recursive way to generate the to all permutation
                2) Recursive
                3) store in a data structure
                4) sort
                5) k-1 is the k-th permutation
                n! time O(N!) x N

    Approach:
        optimal solution :
            n = 4, k = 17

            4! => 24

            [1, 2, 3, 4]

            permutation
            start
                  3 number 6 permutation given
            1 + (2, 3, 4) => 6 => (0 - 5)
            2 + (1, 3, 4) => 6 => (6 - 11)
            3 + (1, 2, 4) => 6 => (12 - 17)
            4 + (1, 2, 3) => 6 => (18 - 23)


        o th permutation
        1 2 3 4

        last
        4 3 2 1


        I am looking for 17 that means => 16 coz 0 based indexing permutation =>
        that why =>
        3 + (1, 2, 4) => (12 - 17)

        In this way 16 permutation 3 is the first number

        3 - - -

        [1, 2, 3, 4]
         0  1  2  3

       k 16/6 = 2
        16 % 6 = 4  th sequence

         3 and rest of the number
        [1, 2, 4] =>  find 4 th sequence

        start
        1 + [2, 4] => 2 => (0-1)
        2 + [1, 4] => 2 => (2-3)
        3 + [2, 4] => 2 =>  (4-5)
                    ----
                      6

           k=> 4 / 2 = 2
             4 % 2 = 0
         3 4 - -

         [1, 2]

         1 + [2] => 1 => (0,0)
         2 + [1] => 1 => (1,1)
                  ----
                   2
``````   k => 0 / 2 => 0
         k => 0 % 2 => 0

        3 4 1 _

        3 4 1 2 Ans

        when any this left then return




        4! => 24
        3! => 6
        2! => 2
        1! => 1

        Time complicity => O(n) x O(n) => O(n^2)
        Space complicity => O(n) store permutation


 */

 #include<bits/stdc++.h>
 using namespace std;

 void getPermutation(int n, int k, vector<int> &ans)
 {
     int fact = 1;
     vector<int> numbers;
     // compute factorial and number list or 1 to n
     for(int i = 1; i < n; i++)
     {
         fact = fact * i;
         numbers.push_back(i);
     }

     numbers.push_back(n);

     // 0 base index
     k = k - 1;
     while(true)
     {
         ans.push_back(numbers[k/fact]);
         numbers.erase(numbers.begin() + k / fact);

         if(numbers.size() == 0)
         {
             break;
         }

         k = k % fact;
         fact = fact / numbers.size();
     }

 }
 int main()
 {
    int n = 4, k = 17;

    vector<int> ans;
    getPermutation(n, k, ans);

    // print
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
     return 0;
 }
