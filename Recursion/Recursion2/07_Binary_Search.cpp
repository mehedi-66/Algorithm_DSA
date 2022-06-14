/*
    ******************* Binary Search using Recursion ***************
    Array must be sorted when we are going to apply Binary Search
*/
#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int *arr, int s, int e, int k)
{
    // base case
    // element not found
    if(s > e)
    {
        return -1;
    }
    // element found


    int mid = s + (e - s)/2;

    if(arr[mid] == k)
    {
        return mid;
    }

    if(arr[mid] < k)
    {
        // right side
        return binarySearch(arr, mid+1, e, k);
    }
    else{
        return binarySearch(arr, s, mid-1, k);
    }
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5};
    int size = 5;
    int key = 4;

    binarySearch(arr, 0, size, 4);
    return 0;
}
