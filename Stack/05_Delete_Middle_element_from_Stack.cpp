/*
    *************** Delete Middle Element from Stack ***************

    Odd case:

    4
    2       4
    9  =>   2
    5       5
    3       3

    After delete middle element

    Even Case:

    8
    7 =>  8
    6     7
    5     5

 */

 #include<bits/stdc++.h>
 using namespace std;

 void solve(stack<int> &st, int cnt, int size)
 {
     // base case when meet in the middle
     if(cnt == size/2)
     {
         st.pop();
         return ;
     }

     // peek out the element for later insert again
     int num = st.top();
     st.pop();

     // recursive call
     solve(st, cnt+1, size);

     // After deleting element restore the stack elements
     st.push(num);

 }

 void deleteMiddle(stack<int> &st, int size)
 {
     int cnt = 0;

     solve(st, cnt, size);
 }
 int main()
 {
    stack<int> st;

    st.push(10);
    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);

    deleteMiddle(st, st.size());

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

     return 0;
 }
