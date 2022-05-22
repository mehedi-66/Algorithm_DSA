/*
    *********** Introduction of Pointer *********

    int num = 5;

    inside the memory create a block that address of num let's say 120

    memory has a symbol table that store all the variable mapping with it address => num -- 120

    when we try to access the num it print the content of that address 5

    Pointer:
        pointer store address

    int *ptr = &num;

    ***
    int *ptr; ======> only declear the pointer is bad practice
    int *ptr = NULL; ===> okay


    int *ptr = &num;

    ptr and num Represent the same memory location:

    which one the right side that type of pointer you have to make:

    char ch = 'M';

    char *p = &ch;


    When Print the value of pointer:

    int *ptr = &num;

    only *ptr called the dereferencing

    cout << num << *ptr << endl; // value print






*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num = 5;

    cout << num << endl; // output: 5

    // address of Operator => &

    cout << "address of num is : " << &num << endl;
    // output: address of num is : 0x61fe1c


    // pointer:

    int *ptr = &num;

    cout << "value is: " << *ptr << endl; // output: 5

    cout << "address is: " << ptr << endl; // ouput: 0x61fe1c


    double d = 4.3;
    double *p2 = &d;

    cout << "Address is: " << p2 << endl; // output:  0x61fe00
    cout << "Value is: " << *p2 << endl; // output: 4.3

    cout << "size of :" << sizeof(num) << endl; // output: 4
    cout << "size of *ptr: " << sizeof(*ptr) << endl; // output: 4
    cout << "size of ptr: " << sizeof(ptr) << endl; // output: 8

    // in all data type pointer size 8 becouse it store Address


    return 0;
}
