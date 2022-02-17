/*
    find first and last position of key
    Input:
    8 2
    {0, 1, 1, 1, 2, 2, 2, 2};

    Output 4 7
*/

#include<bits/stdc++.h>
using namespace std;

int firstOccarance(int arr[], int n, int key)
{
    int s = 0, e = n - 1;

    int mid = s + (e - s )/2;

    int ans =  -1;

    while(s <= e)
    {
        if(arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
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

    return ans;
}


int lastOccrance(int arr[], int n, int key)
{
    int s = 0, e = n -1;

    int mid = s + (e - s)/2;

    int ans = -1;

    while(s <= e)
    {
        if(arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
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

    return ans;
}


int main(){

    int arr[5] = {1, 2, 3, 3, 3};

    // output: 2 4

    cout << firstOccarance(arr, 5, 3) << endl;

    cout << lastOccrance(arr, 5, 3) << endl;

    return 0;
}
