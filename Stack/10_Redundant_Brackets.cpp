/*
    **************** Redundant Brackets ***********

    ( (a+b) )  // outer brackets redundant

    needless brackets are call redundant Brackets

    ( a + (a + b) ) // it is okay for outer brackets

    without any operation +, -, *, /  are redundant bracket
    (b) ... no need this

    Approach:
        1) if opening Bracket => ( or operator +,-,*,/ then push into stack
        2) then ) closing bracket come check any operator in then top or not

*/

#include<bits/stdc++.h>
using namespace std;
bool findRedundantBracket(string &s){

    stack<char> st;

    for(int i = 0; i< s.size(); i++)
    {
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            // (a+b)

            // closing bracket or letter
            if(ch == ')')
            {
                bool isRedundant = 1;

                while(st.top() != '(')
                {
                    char top = st.top();

                    if(top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = 0;
                    }

                    st.pop();
                }

                if(isRedundant == 1)
                        return true;

                st.pop();
            }

        }
    }

    // no redundant found
    return false;

}
int main()
{
    string s = "((a+b))"; // redundant brackets

    cout << findRedundantBracket(s) << endl;

    return 0;
}
