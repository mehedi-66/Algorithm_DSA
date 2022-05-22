/*
    *************** Dynamic Memory Allocation ****************

    2D array create in Static way:
    int arr[5][5];

    1D array ( static )
    int arr[10];

    1D array (Dynamic )

    int * arr = new int[10];

    Dynamic 2D array

    int ** arr  new int * [n];
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row;
    cin >> row;

    int col ;
    cin >> col;

    int ** arr = new int*[row];
/*
    [int*]
    [int*]
    [int*]
    [int*]
*/
    // creation done 2D array ===> collum creating

    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[col];
    }



    // taking input
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // taking output
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }



    // releasing memory

    for(int i = 0; i < n; i++)
    {
         delete [] arr[i];
    }

    delete []arr;

    return 0;
}
