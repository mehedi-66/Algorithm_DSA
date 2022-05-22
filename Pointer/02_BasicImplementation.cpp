#include<bits/stdc++.h>
using namespace std;
int main()
{
    //pointer to int is create, and pointing to some garbage address
    //int *p;

    int *p = NULL;
   // cout << *p << endl; // segmentation fault

    int i = 5;
    int *ptr = &i;

    cout << *ptr  << endl;

    int *ptr1 = 0;
    ptr1 = &i;

    cout << ptr1 << endl;
    cout << *ptr1 << endl; // output: 5;

    int num = 5;
    int a = num;


    // reference changing

    int *ptr2 = &num;
    cout << "before: " << num << endl; // output: 5

    (*ptr2)++;

    cout << "After: " << num << endl; // output: 6


    // Copy one pointer data to another pointer:
    int *q = ptr;

    cout << ptr  << " = " << q << endl; // output: 0x61fdec = 0x61fdec
    cout << *ptr << " = " << *q << endl; // output: 5 = 5


    // pointer Arithmetic
    int c = 3;
    int b = 5;

    int *t = &c;
    int  *x = &b;

    (*t)++;

    cout << (*t) + (*x) << endl; // output: 9;


    t = t + 1;  // go to next pointer location

    return 0;
}
