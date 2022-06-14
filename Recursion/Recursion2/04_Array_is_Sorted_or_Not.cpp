/*
    ***************** Array is sorted or not ***************


*/
#include<bits/stdc++.h>
using namespace std;
int isSorted(int arr[], int size)
{
    // my solution

    static int i = 0;

    if(i >= size-1)
    {
        return 1;
    }
    else if(arr[i] > arr[i+1])
    {
        return 0;
    }
    i++;
    return isSorted(arr, size);
}

bool isSorted2(int arr[], int size)
{
    // Teacher solution

    // base case
    if(size == 0 || size == 1)
    {
        return true;
    }

    // first two elements check

    if(arr[0] > arr[1])
    {
        return false;
    }
    else{
            // trick used here
        bool remainingPart = isSorted2(arr + 1, size - 1);
        return remainingPart;
    }
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5};

    cout << isSorted(arr, 5) << endl;
    cout << isSorted2(arr, 5) << endl;

    return 0;
}
