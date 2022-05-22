/*
        ************** Double Pointer ***********
    int i = 5;

    int * ptr1 =  &i ;   // only i's corresponding pointer

    int ** ptr2 = &ptr1;  // ptr1 corresponding poiter means double pointer create

    int *** ptr3 = &ptr2;   // triple pointer create ... three level

    ptr2 ---> ptr1 ----> i



    ************* pointer with double function ***********

    In case of double pointer:
    where we get the actual result:

    p = p + 1; ?

    *p = *p + 1; ?

    **p = **p + 1; ?




*/
#include<bits/stdc++.h>
using namespace std;

void update(int ** p)
{
   p = p + 1;

    *p = *p + 1;

   **p = **p + 1;

}

int main()
{
    int i = 5;
    int * ptr1 = &i;

    int ** ptr2 = &ptr1; // double pointer create

    cout << &ptr1 << " = " << ptr2 << endl; // output: 0x61fe08 = 0x61fe08

    cout << *ptr2 << " = " << ptr1 << endl; // output: 0x61fe14 = 0x61fe14

    // value print of i
    // one * means one depth value
    cout << i << *ptr1 << **ptr2 << endl; // output: 5

    cout << &i << " " << ptr1 << " " << *ptr2 << endl; // output: 0x61fe14 0x61fe14 0x61fe14

    // now check the update function value:
    cout << "before : " << i << endl;
    cout << "before: " << ptr1 << endl;
    cout << "before: " << ptr2 << endl;
    update(ptr2);
    cout << "after: " << i << endl;
    cout << "after: " << ptr1 << endl;
    cout << "after: " << ptr2 << endl;

    return 0;
}
