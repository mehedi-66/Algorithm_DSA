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
void swapAlternate(int arr[], int n)
{
    for(int i = 0; i < n; i += 2){
        if(i+1 < n){

              swap(arr[i], arr[i+1]);
        }
    }
}
int main()
{
    int even[8] = {5, 2, 9, 4, 7, 6, 1, 0};
    // output = {2, 5, 4, 9, 6, 7, 0, 1 };
    int odd[5] = {11, 33, 9, 76, 43};
    // output = { 33, 11, 76, 9, 43};

    swapAlternate(even, 8);
    printArray(even, 8);

    swapAlternate(odd, 5);
    printArray(odd, 5);

    return 0;
}
