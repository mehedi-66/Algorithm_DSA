/*
    ***************** Quick Sort **************
    Merge Sort:
        1) Array
        2) Divided
        3) Merge

    Quick Sort:

        Time Complexity O(n log n)
        Space Complexity O(n)

        1) Array
        2) one element pick and insert that into right prosition
        3) give right position such a way that left side elements are smaller and right side element are greater


    Example:
        [2, 3, 1, 4]

        1 pick ===> [1, 2, 3, 4]

*/
#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    // count less then pivot
    int cnt = 0;
    for(int i = s+1; i <= e; i++)
    {
        if(arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // place pivot at index position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right < a <  ==> [ < ] [a] [ < ]
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex)
    {
            while(arr[i] <= pivot)
            {
                i++;
            }

            while(arr[j] > pivot)
            {
                j--;
            }

            if(i < pivotIndex && j > pivotIndex)
            {
                swap(arr[i++], arr[j--]);
            }
    }

    return pivotIndex;
}
void quickSort(int arr[], int s, int e)
{
    // base case
    if(s >= e)
    {
        return ;
    }

    // partition
    int p = partition(arr, s, e);

    // left part
    quickSort(arr, s, p-1);

    // right part
    quickSort(arr, p+1, e);

}
int main()
{
    int arr[5] = {2, 4, 1, 6, 9};
    int n = 5;
    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
