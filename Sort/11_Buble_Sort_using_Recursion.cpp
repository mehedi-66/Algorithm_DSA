/*
    **************** Bubble Sort using Recursion ********
    After one pass one elements is sorted :
    If we solve one case then ==> rest of the case handle by Recursion
*/
#include<bits/stdc++.h>
using namespace std;

void sortArray(int *arr, int n)
{
    // base case ... if array has it is Already sorted
    if(n == 0 || n == 1)
    {
        return ;
    }

    // 1 case solve -- large element go to at the end
    for(int i = 0 ; i < n-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
    }

    // Recursion call
    sortArray(arr, n-1);
}
int main()
{
    int arr[5] = {3, 2, 1, 4, 5};

    sortArray(arr, 5);

    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    // output: 1 2 3 4 5

    return 0;
}
