
#include<bits/stdc++.h>
using namespace std;

// O ( log n)

int binarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;

    int mid = start + (end - start)/2;

    while(start <= end)
    {
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(key > arr[mid])
        {
            start = mid + 1;
        }
        else if(key < arr[mid])
        {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return -1;
}


int main()
{
    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};

    cout << binarySearch(even, 6, 12) << endl;

    cout << binarySearch(odd, 5, 8) << endl;
    return 0;
}
