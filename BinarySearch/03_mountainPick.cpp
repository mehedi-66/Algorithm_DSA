/*
    0, 1, 0

    /^\

    1) arr[i] < arr[i+1] => s = mid + 1;

    2) arr[i] > arr[i+1] => e = mid ;

    3) pick =>   arr[i-1] < arr[i] > arr[i+1]

*/


#include<bits/stdc++.h>
using namespace std;

int findPick(int arr[], int n)
{
    int s = 0;
    int e = n - 1;

    int mid = s + (e - s)/2;

    while(s < e)
    {
        if(arr[mid] < arr[mid + 1])
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

int main()
{
    int arr[5] = {0, 1, 2, 1, 0};

    // output: 2

    cout << findPick(arr, 5) << endl;

    return 0;
}
