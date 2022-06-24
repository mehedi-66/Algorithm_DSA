/*
    ************* Sort Stack ****************

 */
 #include<bits/stdc++.h>
 using namespace std;


 void sortedInsert(stack<int> &st, int x)
 {
        // stack not empty and stack top value smaller then up value
        if(st.empty() || ( !st.empty() && (st.top() < x)))
        {
            st.push(x);
            return ;
        }

        int take = st.top();
        st.pop();

        //  recursive call
        sortedInsert(st, x);

        st.push(take);
 }

 void sortStack(stack<int> &st)
 {
     // base case
     if(st.empty())
     {
         return ;
     }

     int take = st.top();
     st.pop();

     // recursive call
     sortStack(st);

     //  sort login here
      sortedInsert(st, take);

 }
 int main()
 {

    stack<int> st;
    st.push(1);
    st.push(5);
    st.push(2);
    st.push(7);

    sortStack(st);

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
     return 0;
 }
