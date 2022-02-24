/*
    Remove all occurences of Substring ...

    input: daabcbaabcbc
    remove: abc
    output:
    pass_1: dabaabcbc

    pass_2: dababc

    pass_3: dab

    ans: dab ********
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    while(s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }

    cout << s << endl;
}
