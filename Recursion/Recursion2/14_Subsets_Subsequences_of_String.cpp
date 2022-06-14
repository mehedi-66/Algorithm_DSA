/*
    *********** Subset Subsequences ****************

    i/p => arr[3] = {1, 2, 3};

    power set  => 2^n => 8  => [],[1],[2],[3], [1,2],[2,3],[1,3],[1,2,3]

    power set is set of all subset


    Approach:
        exclude or include concept

                        ({1,2,3}, {})
    1s call                 /      \
                    ({1,2,3}, {})      ({1,2,3}, {1})
                    /     \               /          \
 2n call ({1,2,3}, {})  ({1,2,3},{2})  ({1,2,3}, {1})  ({1,2,3},{1,2})

 this way call goes

*/

#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &nums, vector<int> output, int index, vector< vector<int> > &ans)
{
    // base case
    if(index >= nums.size())
    {
        ans.push_back(output);
        return ;
    }

    // exclude
    solve(nums, output, index+1, ans);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans );




}
int main()
{

    vector<int> nums({1,2,3});
    vector<int> output;
    int index = 0;

    vector< vector<int> > ans;

    solve(nums, output, index, ans);

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
