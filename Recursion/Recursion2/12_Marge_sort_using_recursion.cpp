/*
    *************** Marge Sort Using Recursion *************
    input: array ==> [38, 27, 43, 3, 9, 82, 10];

    we are divided array into two part: mid = (s+e)/2

        divided =>       [38, 27, 43, 3, 9, 82, 10]

                         [38, 27, 43, 3]   [9, 82, 10]

                       [38, 27]  [43, 3]    [9, 82]  [10]

                     [38]  [28]  [43] [3]  [9] [82]  [10]

    start sort => [28, 38]  [3, 43]   [9, 82] [10]

                    [3, 28, 38, 43]  [9, 10, 82]

                      [3, 9, 10, 28, 38, 43, 82]


    Complexity ===>
        space O(n)
        time O(n logn )

*/
#include<bits/stdc++.h>
using namespace std;

void Merge(int *arr, int s, int e)
{
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int  mainArrayIndex = s;
    for(int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

     // merge 2 sorted arrays
     int index1 = 0;
     int index2 = 0;

     mainArrayIndex = s;

     while(index1 < len1 && index2 < len2)
     {
         if(first[index1] < second[index2])
         {
             arr[mainArrayIndex++] = first[index1++];
         }
         else{
            arr[mainArrayIndex++] = second[index2++];
         }
     }

     while(index1 < len1)
     {
          arr[mainArrayIndex++] = first[index1++];
     }
     while(index2 < len2)
     {
         arr[mainArrayIndex++] = second[index2++];
     }

     delete []first;
     delete []second;

}

void mergeSort(int *arr, int s, int e)
{
    // base case ===> when the all single element or empty array return
    if(s >= e)
    {
        return ;
    }

    int mid = (s+e)/2;

    // left part recursion call
    mergeSort(arr, s, mid);

    // right part recursion call
    mergeSort(arr, mid+1, e);


    // sorted array megere
    Merge(arr, s, e);
}
int main()
{
    int arr[5] = {2, 5, 1, 6, 9};
    int n = 5;

    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
