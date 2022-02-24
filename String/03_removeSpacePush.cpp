/*
    remove space ans push back ... "@40"
*/

#include<bits/stdc++.h>
using namespace std;

string  removeSpace(string s)
{
    string temp = "";

    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else{

            temp.push_back(s[i]);
        }
    }

    return temp;
}


int main()
{
    string s = "My name is Mehedi";

    // output: my@40name@40is@40Mehedi

    cout << removeSpace(s);

    return 0;
}
