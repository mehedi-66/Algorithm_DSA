/*
    find pivot in an array

    input {1, 2, 3, 7, 9} => sorted
        {7, 9, 1, 2, 3} => rotated

*/

#include<bits/stdc++.h>
using namespace std;

int getPivot(int arr[], int n)
{
    int s = 0;
    int e = n - 1;

    int mid = s + (e - s)/2;

    while(s < e)
    {
        // 8, 10, 17,
        // in graph first line all element lay in a[mid] >= a[0]
        if(arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else{
            // in graph second line
            // 1, 3
            // take mid coz not skip the pick element
            e = mid;
        }

        mid = s + (e - s)/2;
    }
    // e and s same point .. one of them return
    return s;
}

int main()
{
    int arr[5] = {8, 10, 17, 1, 3};

    cout << getPivot(arr, 5) << endl;
}
