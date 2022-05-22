/*
    ************** Reference Variable Static and Dynamic Memory **********

    //********* when we use stack memory that called static memory allocation:
    //********* when we use Heap memory that called Dynamic memory allocation:

    1) Reference Variable ==> one person has two name ==> same memory but different different name

    create reference Variable:
    int i = 5;
    int & j = i;

    i and j ===> indicate same memory location:

    ******* Why we use reference variable
    // pass by value and pass by reference ===> in case of pass by reference we use ===> reference variable:

    update(int &a, int b){}  ==> here a is pass by reference and b is pass by value


    ********* Array

        int arr[n]; ===> it is bad practice (because array size have to know in compile time)

        memory ===> stack + heap

        when we give value in run time by user ===> stack memory is smaller then the user requirement that time program will crashed
        that is why it is a bad practice


    ********** How we create large size memory : Dynamic memory Allocation
    Heap Memory create and linking

    new ===> keyword

    new char;

    it return address of heap memory ( because heap memory we do not allowed to give name of variable )

    // pointer store address

    char * ch = new char;

    memory view:
    point by address

    stack [  ch(710) ] ------------ heap [   710  ]

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i = 5;
    // create a ref variable
    int &j = i;

    cout << i << " " << j << endl; // output: 5 5
    j++;
    cout << i << " " << j << endl; // output: 6 6


    // inside the heap memory allocation

    char * ch = new char;
    *ch = 'a';
    cout << *ch << " address= " << ch << endl; // output: a address= a↓x

    // create an array into heap memory 5 length
    int *arr = new int[5];

    // variable size array create inside Heap memory
    int n;
    cin >> n;

    int * arr1 = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    // the Heap memory not free automatically
    // we have to free it
    // delete array
    delete []arr1;

    // delete variable of heap memory
    delete ch;

    return 0;
}
