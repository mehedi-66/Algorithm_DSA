/*
    ************** Print All permutations of Given String or Array **********

    leetCode: 46 Permutations

        Given an array nums of distinct integers, return all the possible permutations. you can return the answer in any order

        input: [1, 2, 3]

        output: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]

    First Approach:
                Time complexcity => n! x n
                Spcace Complexicity => O(n) + O(n)

                    Extra space Complexicity
                    .. generate all the permutation
                      number of element is 3 then => n! => 3! => 6

            1) take ds and mark array
            2) call for each element by left recursion call
            3) if pick one element mark its index by 1
            4) when go back unmark the index position

                    [1, 2, 3] arry
                     0  1  2

                    f( [], [0, 0, 0])
                 1 /         2 |         3 \
                  /            |            \
             f([1],[1,0,0])  f([2],[0,1,0]) f([3],[0,0,1])
         2  /          3 \
          /               \
        f([1,2],[1,1,0])  f([1,3],[1,0,1])
        3 /         x \
         /
    f([1,2,3],[1,1,1])
      base case back meet
*/
#include<bits/stdc++.h>
using namespace std;

int N = 3;
void recurPermute(vector<int> &ds, int arr[], vector< vector<int> > &ans, vector<int> &mark)
{
    if(ds.size() == N)
    {
        ans.push_back(ds);
        return ;
    }

    for(int i = 0; i < N; i++)
    {
        if(mark[i] == 0)
        {
            // pick and mark
            ds.push_back(arr[i]);
            mark[i] = 1;

            recurPermute(ds, arr, ans, mark);

            // not pick and unmark
            mark[i] = 0;
            ds.pop_back();

        }
    }
}

int main()
{
    int arr[] = {1, 2, 3};

    vector< vector<int> > ans;
    vector<int> ds;

    // mark vector
    vector<int> mark(3, 0);

    recurPermute(ds, arr, ans, mark);

    // print
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
