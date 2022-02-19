/*
    Reverse Array
     input: 1 2 3 4 5

    output : 5 4 3 2 1

*/

#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int n)
{
    int s = 0;
    int e = n-1;

    while(s <= e)
    {

        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[5] = {2, 1, 3, 4, 5};

    reverseArray(arr, 5);

    print(arr, 5);
}
