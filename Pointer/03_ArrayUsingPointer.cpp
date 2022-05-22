/*
    *********** Array in Pointer *********

    int arr[10];
    fixed size array create where 40 byte memory allocated contigous

    first block of memory address is => arr itself address is the first address





*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10] = {2, 3, 4};

    cout << "address of first meory block is :" << arr << endl; // output: 0x61fdf0
    // using & address operator
    cout << "address of array block : " << &arr << endl;  // output: 0x61fdf0  same

    cout << "address of first location: " << &arr[0] << endl; // output: 0x61fdf0

    // first location value print
    cout << "first location value: " << arr[0] << endl; // output: 2
    cout << "First location value: " << *arr << endl; // output: 2

    // second location value
    cout << "second value: " << arr[1] << endl; // output: 3
    cout << "second value: " << *(arr + 1) << endl; // output: 3

    // one formula like things
    // arr[i] means ==> *(arr + i)

    int i = 3;
    cout << i[arr] << endl; // output: somthing

    int *ptr = &arr[0];
    cout << sizeof(ptr) << endl; // output: 8
    cout << sizeof(*ptr) << endl; // output: 4
    cout << sizeof(&ptr) << endl; // output: 8

    // Same things in case of array
    cout << &arr[0] << endl;
    cout << &arr << endl;
    cout << arr << endl;

    int *p = &arr[0];

    // different things
    cout << p << endl; // the array pointers address
    cout << &p << endl; // the itself address


     return 0;
}
