/*
    ********** Macros Global Variables inline function & Default Args ***********

    Macros ==> #define
    macros is peace of program that replace by macro values
*/
#include<bits/stdc++.h>
using namespace std;

#define PI 3.14

// global variable
int score = 15;

int a()
{
    score = 20;
}


inline int getMax(int &a, int &b)
{
    return (a > b) ? a : b;
}
int main()
{
    int r = 5;
    double area = PI * r * r;
    cout << area << endl;

    a();
    cout << score << endl; // output: 20


    // ************ Inline function ************
    // are used to reduce the function call overhead
    // if the compiler know that it function is inline that time replace all the call by default

    int a = 5, b = 6;

    int ans = getMax(a, b); // compiler getMax() replace by ===> (a>b) ? a : b;

    a = 10;
    b = 3;
    ans = getMax(a, b); // replace by (a>b) ? a : b;
    return 0;
}
