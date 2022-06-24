/*
    ************** Reverse Stack using Recursion *****************

    Algo:
        1) Stack top element => side store
        2) using reursion to reverse remaining stack
        3) insert at bottom

        9    9
        7  =>    7
        4        4
        3        3
                     => recursion call
                          3
                          4
                          7
bottom at insert <= take 9 <=  back

*/

#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }

    int take = st.top();
    st.pop();

    insertAtBottom(st, x);

    st.push(take);
}

void reverseStack(stack<int> &st)
{
    // base case
    if(st.empty())
    {
        return;
    }

    int take = st.top();
    st.pop();

    // recursive call

    reverseStack(st);

    // insert bottom call

    insertAtBottom(st, take);
}

int main()
{
    stack<int> st;

    st.push(10);
    st.push(11);
    st.push(12);
    st.push(13);

     reverseStack(st);

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
