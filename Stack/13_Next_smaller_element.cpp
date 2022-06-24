/*
    ************ Next Smaller Elements *****************

    Next smaller element ==> first smaller element

    i/p ==> [2,  1,  4,  3];

            [1,  -1,  3, -1]

    Approach 1:
        1) For 2 ==> (n-1) comparison
        2) For 1 ==> (n-2)
        3) For 4 ==> (n-3)

        TC ==> O(n^2)

    Approach 2:
        1) process from right side ans push the smallest element
        2)  st.push(-1);
        3) curr element  ==> up to small element not found pop() form stack
        4) curr element push into stack

        TC => O(n)

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(int arr[], int n)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(n);

    for(int i = n -1; i >= 0; i--)
    {
        int curr = arr[i];

        while(st.top() >= curr)
        {
            st.pop();
        }

        // ans is stack top

        ans[i] = st.top();
        st.push(curr);
    }

    return ans;


}
int main()
{
    int arr[4] = {2, 1, 4, 3};

    vector<int> ans;

    ans = nextSmallerElement(arr, 4);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;


    return 0;
}
