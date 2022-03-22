/*
    ******************* Subset Sum problem *****************
    Given a list of N integers print sums of all subsets in it. output should be printed in increasing order of sums



    2 => 2^2 => 4 subset is

    N = 2
    {2, 3}

    output: 0, 2, 3, 5

    Approach 1:
        power Set => O(2^n) x N

    Approach 2: TC => O(2^n) Sp O(2^n log(2^n) )
        Recursion ... which index is select or not select
        p x p like

*/

#include<bits/stdc++.h>
using namespace std;
void findSumSubset(int index, int n, int arr[], vector<int> &sumSubset, int sum)
{
    if(index >= n)
    {
        sumSubset.push_back(sum);
        return;
    }

    // pick the element
    findSumSubset(index+1, n, arr, sumSubset, sum+arr[index]);

    // do not pick the element
    findSumSubset(index+1, n, arr, sumSubset, sum);
}

int main()
{
    int arr[] = {2, 3};
    vector<int> sumSubset;
    findSumSubset(0, 2, arr, sumSubset, 0);

    sort(sumSubset.begin(), sumSubset.end());
    for(int i = 0; i < sumSubset.size(); i++)
    {
        cout << sumSubset[i] << " ";
    }
    return 0;
}
