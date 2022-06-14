/*
    *************** Linear Search using Recursion **************
*/
#include<bits/stdc++.h>
using namespace std;

bool LinearSearch(int arr[], int size, int key)
{
    if(size == 0)
    {
        return 0;
    }
    else if(arr[0] == key)
    {
        return 1;
    }

    return LinearSearch(arr+1, size-1, key);
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5};

    cout << LinearSearch(arr, 5, 10) << endl;

    return 0;
}
