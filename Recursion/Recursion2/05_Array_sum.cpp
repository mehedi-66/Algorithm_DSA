/*
    *************** Array elements sum ***************

*/
#include<bits/stdc++.h>
using namespace std;
int getSum(int arr[], int size)
{
    if(size == 0)
    {
        return 0;
    }
            // *arr value of arr[0];
    int sum = *arr + getSum(arr + 1, size - 1);
    cout << sum << endl;
    return sum;
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5};

    cout << getSum(arr, 5);
    return 0;
}
