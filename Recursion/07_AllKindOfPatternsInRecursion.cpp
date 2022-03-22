/*
    *************** All kind of Pattern in Recursion **********
    Time Complexity O(2^n)

    concept ( take | not take )

    1) Printing subsequences whose sum is K

    KSum(index, n, arr, v, sum, k)

    Example: {1, 2, 1}  given k = 2;

    take x take
    1 x 1

    x take x
    x 2 x


********************* count the subsequence with sum == k ***********
    structure like this

    int f()
    {
        base case
            return 1 => condition satisfies
            return 0 => condition not satisfies

        l = f()
        r = f()

        return l + r;
    }



*/

#include<bits/stdc++.h>
using namespace std;

// Print all subsequence
void KSum(int index, int n, int arr[], vector<int> &v, int sum, int k)
{
    //cout << "Mehedi" << endl;
    if(index >= n)
    {
        if(sum == k)
        {
            for(auto it : v)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return ;
    }

    // pick or take
    v.push_back(arr[index]);
    sum += arr[index];

    KSum(index + 1, n, arr, v, sum, k);

    // NOT Pick or not Take
    v.pop_back();
    sum -= arr[index];

    KSum(index + 1, n, arr, v, sum, k);


}


// Print any one subsequence
bool KSumAnySequencePrint(int index, int n, int arr[], vector<int> &v, int sum, int k)
{

    if(index >= n)
    {
        // condition satisfied Base case
        if(sum == k)
        {
            for(auto it : v)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        else{
         return false;
        }

    }

    // pick or take
    v.push_back(arr[index]);
    sum += arr[index];

    if( KSumAnySequencePrint(index + 1, n, arr, v, sum, k) == true)
    {
        // if any sequences if true then no call happened simply return true;
        return true;
    }

    // NOT Pick or not Take
    v.pop_back();
    sum -= arr[index];

   if( KSumAnySequencePrint(index + 1, n, arr, v, sum, k) == true)
    {
        // if any sequences if true then no call happened simply return true;
        return true;
    }

    return false;
}



// Count the number of  subsequence
int KSumCount(int index, int n, int arr[], int sum, int k)
{

    if(index >= n)
    {
        // condition satisfied Base case
        if(sum == k)
        {
            return 1;
        }
        else{
         return 0;
        }
    }

    // pick or take

    sum += arr[index];

  int l = KSumCount(index + 1, n, arr, sum, k);

    // NOT Pick or not Take

    sum -= arr[index];

   int r = KSumCount(index + 1, n, arr, sum, k);

    return l + r;
}

int main()
{
    int arr[5] = {1, 2, 1};
    vector<int> v;
    // KSum(index, n, arr, v, sum, k)
    KSum(0, 3, arr, v, 0, 2);

    KSumAnySequencePrint(0, 3, arr, v, 0, 2);

    cout << KSumCount(0, 3, arr, 0, 2);
    return 0;
}
