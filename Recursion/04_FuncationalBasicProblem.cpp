/*
    ******************** Basic Problem on Functional Recursion ********

    1) Reverse an Array
    2) Given string is Palindrome or not

*/
#include<bits/stdc++.h>
using namespace std;

void swapRecursion(int l, int r, int arr[])
{

    if(l >= r)
    {
        return ;
    }
    swap(arr[l], arr[r]);

    swapRecursion(l+1, r-1, arr );
}

// string is palindrome or not
int palindrome(int l, int r, string &s)
{
    if(l >= r)
    {
        return true;
    }
    else if(s[l] != s[r])
    {
        return false;
    }

    return palindrome(l+1, r-1, s);


int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
                // l  r
    swapRecursion(0, 4, arr);
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    // take a string
    string s = "MeSu";
    cout << palindrome(0, s.size()-1, s) << endl;

    return 0;
}
