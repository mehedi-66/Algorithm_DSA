/*
    1) count 0 and 1 and replace them in sorted order first 0 then 1
    2) sort() O(nLogn)
    3) two pointer ... approach
*/
#include<bits/stdc++.h>
using namespace std;


void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void sortOne(int arr[], int n)
{
    int left = 0, right = n - 1;

    while(left < right)
    {
        while(arr[left] == 0 && left < right)
        {
            left++;
        }

        while(arr[right] == 1 && left < right)
        {
            right--;
        }

        if(left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }

    }
}


int main()
{
    int arr[8] = {1, 1, 0, 0, 0, 0, 1, 1};

    sortOne(arr, 8);

    printArray(arr, 8);
    return 0;
}
