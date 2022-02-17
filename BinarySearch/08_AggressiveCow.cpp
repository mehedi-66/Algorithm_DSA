/*
    how to Place cow in difference place so that .. are not Aggressive

    2 3 1 4 6

    sort 1, 2, 3, 4, 6

    Search Space => 0 - maxDistance

    min = 0
    max = 6 - 1

    Search Space => 0 - 5
    mid = 2

    array ... ditance ... 1 - 3 => 2 >= 2


*/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n,  int k, int mid)
{
    int cowCount = 1;
    int lastPos = arr[0];

    for(int i = 0; i < n; i++)
    {
        if(arr[i] - lastPos >= mid){

            cowCount++;

            if(cowCount == k)
            {
                return true;

            }

            lastPos = arr[i];
        }
    }

    return false;

}



int aggressiveCows(int arr[], int n, int k)
{

    // Sort the arr
    sort(arr, arr+n);
    int s = 0;
    int Maxi = -1;
    for(int i = 0; i < n; i++)
    {
        Maxi = max(Maxi, arr[i]);
    }

    int e = Maxi;

    int ans = -1;
    int mid = s + (e - s)/2;

    while(s <= e)
    {
        if(isPossible(arr, n, k, mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }

        mid = s + (e - s)/2;

    }

    return ans;
}
int main()
{
    int arr[5] = {2, 3, 1, 4, 6};


    cout << aggressiveCows(arr, 5, 2) << endl;
}
