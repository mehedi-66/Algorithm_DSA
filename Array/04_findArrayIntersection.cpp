/*
    1) first array one by one element search on second array
    2) if match then update second array index with INT_MIN
    3) break second loop
 */
#include<bits/stdc++.h>
using namespace std;

// boot force solution
void findArrayIntersection(int arr1[], int n, int arr2[], int m)
{
    for(int i = 0; i < n; i++)
    {
        int element = arr1[i];

        for(int j = 0; j < m; j++)
        {
            if(element == arr2[j])
            {
                cout << arr2[j] << endl;
                arr2[j] = -1;
                break;
            }
        }
    }
}


// if the both array is sorted then ... we can be little bit optimize
void findArrayIntersectionOptimize(int arr1[], int n, int arr2[], int m)
{
    for(int i = 0; i < n; i++)
    {
        int element = arr1[i];

        for(int j = 0; j < m; j++)
        {
            // if the array 2 element is bigger then break...
            if(element < arr2[j]){
                break;
            }
            if(element == arr2[j])
            {
                cout << arr2[j] << endl;
                arr2[j] = -1;
                break;
            }
        }
    }
}

// **** now two pointer approach *****
/*
    sorted two array

    i = 0, j = 0;

    1) arr1[i] < arr2[j] { i++ }
    2) arr1[i] == arr2[j] { print and i++, j++}
    3) arr1[i] > arr2[j] { j++ }
*/

void findArrayIntersectionByTwoPointer(int arr1[], int n, int arr2[], int m)
{
    int i = 0, j = 0;

    while(i < n && j < m)
    {
        if(arr1[i] == arr2[j])
        {
            cout << arr1[i] << endl;
            i++, j++;
        }
        else if(arr1[i] < arr2[j])
        {
            i++;
        }
        else if(arr1[i] > arr2[j])
        {
            j++;
        }
    }
}


int main()
{
    int arr1[4] = {1, 2, 3, 3};
    int arr2[2] = {3, 4};

    findArrayIntersection(arr1, 4, arr2, 2);

    findArrayIntersectionOptimize(arr1, 4, arr2, 2);

    findArrayIntersectionByTwoPointer(arr1, 4, arr2, 2);
    return 0;
}
