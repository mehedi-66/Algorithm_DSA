/*
    Insertion Sort

    Time complexity

    Best Case : O(n)
    worst case: O(n^1)


    Space complexity
    O(1) no extra array need

    insertion meaning ... insert some think ... right place
    1) take one by one an place in the right place ...
    2) all insertion done we get sorted array ...
    3) inside the array shift element not swap

    Same Array ... Partition

    Example: 5, 2, 6, 9, 4 => card

    insert 5 :=> 5 | now arr : 2, 6, 9, 4

    insert 2 :=> 2, 5 | now arr :  6, 9, 4

    insert 6 :=> 2, 5, 6 | now arr : 9, 4

    insert 9: 2, 5, 6, 9 | now arr :=> 4

    insert 4: 2, 4, 5, 6, 9

    we get sorted array > 2, 4, 5, 6, 9

*/

#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    // initially first element sorted that why n-1 for run
    for(int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j;
        for( j = i-1; j>=0; j--)
        {
            if(arr[j] > temp)
            {
                // shift
                arr[j+1] = arr[j];

            }
            else if(arr[j] < temp){
                break;
            }
        }

        arr[j+1] = temp;
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

    insertionSort(arr, 5);

    printArr(arr, 5);

    return 0;
}
