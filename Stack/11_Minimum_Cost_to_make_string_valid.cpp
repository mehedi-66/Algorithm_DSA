/*
    ************* Minimum Cost to Make a string valid ***********

    i/p => expression string :  {   }

    {}{}
    {{}}

    { } }  inValid


    Minimum how many bracket we reverse so that the string is valid

    input => { { {}
    output => {} {}  1 ans

    condition:
        1) number of open == close bracket
        2) every close bracket should have open bracket before it
            { ==> }

    Invalid Pattern :
        1) {{{{{....
        2) }}}}}}.....
        3) }}}}{{{{

    Algorithm:
        1) odd length  ==> -1
        2) i/p string ==> valid part remove from stack
        3) remaining part => above 3 invalid part pattern follow
        4) }}}{{{
            a => count of close bracket
            b => count of open bracket

        ans = ((a+1)/2) + ((b+1)/2)


*/

#include<bits/stdc++.h>
using namespace std;


int findMinimumCost(string &s)
{
    // odd condition
    if(s.size()% 2 == 1)
        return -1;

    stack<char> st;

    for(int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        if(ch == '{')
            st.push(ch);
        else
        {
            // ch is close brace
            if(!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    // stack contains invalid expression
    int a = 0, b = 0;
    while(!st.empty())
    {
        if(st.top() == '{')
        {
            b++;
        }
        else{
            a++;
        }
        st.pop();
    }

    // minimum cost
    int ans = (a+1)/2 + (b+1)/2;

    return ans ;

}


int main()
{
    string s = "{{}{{}{}"; // invalid string {{

    cout << findMinimumCost(s);


    return 0;
}
