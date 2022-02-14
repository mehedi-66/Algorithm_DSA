#include<bits/stdc++.h>
using namespace std;

void findPairSum(int arr[], int n, int sum)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {

            if((arr[i] + arr[j]) == sum)
            {
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
}

int main()
{
    int arr[5] = {1, 3, 2, 5, 4};

    sort(arr, arr + 5);

    // {1, 2, 3, 4, 5}

    findPairSum(arr, 5, 6);

}
