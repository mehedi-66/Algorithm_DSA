/*
    **************** Valid Parentheses ***************

    Every opening bracket has to has closing bracket

    [ () {} ( {} )]

    1) if opening bracket, stack push
    2) if close bracket, stack top check and pop


*/
#include<bits/stdc++.h>
using namespace std;

bool matches(char top, char ch)
{
    // () {} []

    if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch =']' && top == '['))
        return true;
}

bool matchParentheses(stack<char> st, string expr)
{

    for(int i = 0; i < expr.size(); i++)
    {
        char ch = expr[i];

        // opening bracket
        if(ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else{
            // closing bracket

            if(!st.empty())
            {
                char top = st.top();

                if(matches(top, ch))
                {
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else
            {
                // stack is empty and closing bracket meet
                return false;
            }
        }
    }

    // after insert and pop finish
    if(st.empty())
        return true;
    else
        return false;


}

int main()
{
    string expr = "[(){}]";

    stack<char> st;

    bool ans = matchParentheses(st, expr);

    if(ans)
        cout << "Match" << endl;
    else
        cout << "Not match" << endl;


    return 0;

}


