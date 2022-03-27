/*
    **************** Subset sum ****************

    leetCode => 90 Subsets II

    Given an integer array nums that may contain duplicates, return all possible subsets(the power set)
    the solution set must not contain duplicate subsets. Return the solution in any order

    arr[] = {1, 2, 2}
    output: [], [1], [1, 2], [1, 2, 2], [2], [2, 2]


    first Approach: tell the interviewer pick or not pick
                    2^n power set => subset

                    when we generate all the subset 2^n => store in set => list < of list >
                    it take M * log m

    Recursion Approach:
                        Time complexcity => O(2^n x n)
                        space Complexity  => O(2^n) x O(n)

                        we develop recursion such a way that the recursion not generate duplicate subset

                        => Recursion will generate itself a => list

                        1) first sept carrying a empty => data structure
                        2)


                [1, 2, 2, 2, 3, 3]
                 0  1  2  3  4  5

                 f(0, [])
                /   |        \
               /    |         \
        f(1, [1])  f(2, [2])   f(5, [3])   f(6, [3])
        /     \------------|
f(2, [1, 2])  f(2, [1, 2]) f(3, [1, 3])
                x same list generate


root f(0,[]) => pick 0 index & go 1  pick 1 index go 2       x same list generate [3]

        ***** pick one index and next recursion call to based on the next index
        if any picking index give same list of any of them not pick



*/
#include<bits/stdc++.h>
using namespace std;

int arraySize = 3;
void findSubsets(int index, int arr[], vector<int> &ds, vector< vector<int> > &ans)
{
   // cout << "Mehedi" << endl;
    ans.push_back(ds);
    for(int i = index; i < arraySize; i++)
    {
        if(i != index && arr[i] == arr[i-1]) continue;

        // pick
        ds.push_back(arr[i]);

        findSubsets(i+1, arr, ds, ans);

        // not pick
        ds.pop_back();
    }
}
int main()
{
    int arr[] = {1, 2, 2};
    vector< vector<int> > ans;
    vector<int> ds;

    sort(arr, arr+3);

    findSubsets(0, arr, ds, ans);

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
