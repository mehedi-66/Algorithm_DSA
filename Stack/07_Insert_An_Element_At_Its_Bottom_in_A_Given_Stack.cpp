/*
    **************** Insert An Element At Its Bottom In Given Stack **************

    Recursive way:

    1) top element pop and store it into Y
    2) when stack is empty then
    3) push the give x
    4) when return back and back that push Y

*/
#include<bits/stdc++.h>
using namespace std;

void pushAtBottom(stack<int> &st, int x)
{
    if(st.empty())
    {
        st.push(x);
        return ;
    }

    // take out
    int take = st.top();
        st.pop();

    // call
    pushAtBottom(st, x);

    // back ... again push those taken element
    st.push(take);

}

int main()
{
    stack<int> st;

    st.push(10);
    st.push(11);
    st.push(12);
    st.push(13);

    pushAtBottom(st, 300);

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
