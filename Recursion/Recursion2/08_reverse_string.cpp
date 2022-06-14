/*
    ******************** Reverse String ****************
*/
#include<bits/stdc++.h>
using namespace std;

void Reverse(int i, int j, string &s)
{
    // base case
    if(i > j)
    {
        return ;
    }
    swap(s[i], s[j]);

    Reverse(i+1, j-1, s);
}

int main()
{

    string s = "abcde";

    Reverse(0, s.size()-1, s);
    cout << s << endl;
    return 0;
}
