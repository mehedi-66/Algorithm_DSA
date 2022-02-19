/*
    Selection Sort

    Time Complexity
    worst case  and best case O(n^2)

    Space Complexity O(1)

    Use case => small number of element and constant space


    1) round / passes
    2) smallest element pick
    3) and right place
    4) arr[i] to small arr[j] => swap()

    Example:
        64, 25, 12, 22, 11

    pass: 11, 25, 12, 22, 64

*/


#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    // coz last index only one element already sorted n-1
    for(int i = 0; i < n-1; i++)
    {
        int minIndex = i;

        for(int j = i; j < n; j++)
        {
            if(arr[minIndex] > arr[j])
            {
                minIndex = j;
            }

        }

        swap(arr[minIndex], arr[i]);

//        if( i != minIndex )
//        {
//            swap(arr[Min], arr[i]);
//        }
    }
}

void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {2, 3, 1, 4, 5};

    selectionSort(arr, 5);

    printArr(arr, 5);


    return 0;
}
