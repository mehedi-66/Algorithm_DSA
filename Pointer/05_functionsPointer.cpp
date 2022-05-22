/*
    ************ Function in Pointer case ************



*/

#include<bits/stdc++.h>
using namespace std;

void print(int *p)
{
    cout << p << endl; // output: 0x61fe14

    cout << *p << endl; // output: 5
}

void update(int *p)
{
    p = p + 1;
}

void updateValue(int *p)
{
    *p = 10;
}

// Here int arr[] === int *arr same
int getSum(int *arr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{

    int value = 5;
    int *p = &value;

    print(p);

    cout << "Before : " << p << endl; // output: Before : 0x61fe14
    update(p);
    cout << "After : " << p << endl; // output: After : 0x61fe14
    // Address same

    // but we can update value:
    updateValue(p);

    cout << *p << endl; // output: 10


    // array pass into function

    int arr[10] = {1, 2, 3};

    cout << getSum(arr, 3) << endl;

    return 0;
}
