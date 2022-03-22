/*
    **************** Combination sum 1 problem ***********

    {2, 3, 6, 7}
    target = 7
    {2, 2, 3}
    {7}

    target sum reduce and check and call recursion



*/
#include<bits/stdc++.h>
using namespace std;
void findCombination(int index, int n, int target, int arr[], vector< vector<int> > &ans, vector<int> &sub)
{
    // reduction target depend on the current value pick from array
    if(index >= n)
    {
        if(target == 0)
        {
            ans.push_back(sub);
        }
        return ;
    }

    // pick up the element
    if(arr[index] <= target)
    {
        sub.push_back(arr[index]);
        // one index take many number of time
        findCombination(index, n, target-arr[index], arr, ans, sub);
        sub.pop_back();
    }

    findCombination(index+1, n, target, arr, ans, sub);
}

int main()
{
    int arr[] = {2, 3, 6, 7};
    vector< vector<int> > ans;
    vector<int> sub;
    int target = 7;
    findCombination(0, 4, target, arr, ans, sub);

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
