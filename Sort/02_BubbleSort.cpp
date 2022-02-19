/*
    Bubble Sort

    time complexity
    worst case:  O(n^2)
    best case: O(n)  => already sorted check

    space Complexity O(1)

    1) round / pass
    2) a > b near element swap(a, b)
        10 > 3 => 3 < 10
    3) After first we get one largest element
    4) After ith round ith largest element place right place

    Round 1:
            10, 1, 7, 6, 14, 9

            1, 10, 7, 6, 14, 9
            1, 7, 10, 6, 14, 9
            1, 7, 6, 10, 14, 9
            1, 7, 6, 10, 14, 9
            1, 7, 6, 10, 9, 14

            14 we get....



*/


#include<bits/stdc++.h>
using namespace std;


void bubbleSort(int arr[], int n)
{
    // total number of round n - 1 => if we satar 1 to n it is okay coz arr start from zero
    for(int i = 1; i < n; i++)
    { // round 1 to n-1

        bool swaped = false;
        for(int j = 0; j < n - i; j++)
        { // process element till n - i th index
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swaped = true;
            }
        }

        if(swaped == false)
        {
            break;
        }
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
    int arr[5] = {3, 2, 1, 4, 5};

    bubbleSort(arr, 5);

    printArr(arr, 5);

    return 0;
}
