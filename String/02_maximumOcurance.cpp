/*
    maximum number of occurs of character ...

    *** mapping *** one kind of hashing
*/

#include<bits/stdc++.h>
using namespace std;

char getMaximumOcc(string s)
{
    //
    int a[26] = {0};

    for(int i = 0; i < s.size(); i++)
    {
        int x = ((int)s[i] - 'a');
       // cout << x << endl;
       a[x]++;
    }


    int Max = 0, index;
    for(int i = 0; i < 26; i++)
    {
        if(Max < a[i])
        {
            index = i;
            Max = a[i];
        }

    }
    char ans = 'a' + index;
    return ans;
}
int main()
{
    string s = "aabbb";
    // output: b
    cout << getMaximumOcc(s);

    return 0;
}
