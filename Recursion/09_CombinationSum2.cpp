/*
    *************** Combination sum 2 ************
    Time Complixcity O(2^n x K)
    Space complixcity O(k+x)  average length is K

     Given a collection of candidate numbers (candidates) and a target number (target)
     find all unique combinations in candidates where the candidate numbers sum to target.
     Each number in candidates may only be used once in the combination

     Note: the solution set must not contain duplicate combinations

     Example:
        {10, 1, 2, 7, 6, 1, 5}

        Target => 8

        ans:
        [1, 1, 6]
        [1, 2, 5]
        [1, 7]
        [2 6]


        After sorted call the recursion

        if we pick the one element then we not pick same element then we get the not repereted element

        [1, 1, 1, 2, 2]

        p  x  x  p  x  => p call and x not call

        Approach :
        you are in an index ... from the index can I pick the index or not .. till the end .. can I pick the index or not

        for( i -> n-1)
        {
            if( okay )
             {
                call the recursion
             }
            else{
                not call the recursion
            }

            // when call back form the recursion
            // do something
        }
*/

#include<bits/stdc++.h>
using namespace std;
void findCombination(int index, int n, int arr[], vector< vector<int> > &ans, vector<int> v, int target, int sum)
{
    if(target == 0)
    {
        ans.push_back(v);
        return ;
    }

    for(int i = index; i < 4; i++)
    {
        if(i > index && arr[i] == arr[i-1])
        {
            continue;
        }
        if(arr[i] > target)
        {
            break;
        }
        v.push_back(arr[i]);
        findCombination(i+1, n, arr, ans, v, target-arr[i], sum);
        v.pop_back();

    }
}

int main()
{
    int arr[5] = {2, 1, 2, 1};
    sort(arr, arr+4);
    vector< vector<int> > ans;
    vector<int> v;
    int target = 4;
  // findCombination(0, n, arr, ans, v, target, sum)
    findCombination(0, 4, arr, ans, v, target, 0);

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
