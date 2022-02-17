
/*
    Search in Rotated Array and Sorted array
    input: {7, 9, 1, 2, 3}
    key : 2

    1) find pivot
    2) second Part {1, 2, 3} => arr[pivot] <= target <= arr[n-1]
    3) first part {7, 9} => arr[0] <= target <= arr[pivot - 1]
    4) Binary Search on that range specifically search on
*/

#include<bits/stdc++.h>
using namespace std;


// find pivot
int Pivot(int arr[], int n)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e - s)/2;

    while(s < e)
    {
        if(arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e - s)/2;
    }

    return s;
}

// Binary Search
int BinarySearch(int arr[], int s, int e, int key)
{
    int mid = s + (e - s)/2;

    while(s <= e)
    {
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(key > arr[mid])
        {
            s = mid + 1;
        }
        else if(key < arr[mid])
        {
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }

    return -1;
}

// find key
int findPositionKey(int arr[], int n, int key)
{
    int pivot = Pivot(arr, n);

    if(key >= arr[pivot] && key <= arr[n-1])
    {
        return BinarySearch(arr, pivot, n-1, key);
    }
    else{
        return BinarySearch(arr, 0, pivot-1, key);
    }
}

int main()
{
    int arr[5] = {7, 9, 1, 2, 3};

    cout << findPositionKey(arr, 5, 2);
}
