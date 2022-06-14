/*
    ******************** Check Palindrome ******************
    if one string and it's reverse is the same string it is called palindrome

    1) Approach is that: string ==> its reverse and compaire is ===> it take extra space
    2)  Two pointer approach
*/
#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s, int i, int j)
{
    if(i > j)
    {
        return 1;
    }
    else if(s[i] != s[j])
    {
        return 0;
    }

    return checkPalindrome(s, i+1, j-1);
}
int main()
{
    string s = "abba";

   cout <<  checkPalindrome(s, 0, s.size()-1);

    return 0;
}
