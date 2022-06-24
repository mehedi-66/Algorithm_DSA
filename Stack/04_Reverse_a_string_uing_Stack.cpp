/*
    ***************** Reverse a string using Stack ***************

    swap way we can reverse string
    but here we are going to use Stack

    Stack has Basic property that ... after insert it gives the revers order

    TC => O(n)
    SC => O(n) for stack extra space
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "mehedi";

    stack<char> st;

    for(int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        st.push(ch);
    }

    string ans = "";

    while(!st.empty())
    {
        char ch = st.top();
        ans.push_back(ch);

        st.pop();
    }

    cout << ans << endl;
    return 0;
}
