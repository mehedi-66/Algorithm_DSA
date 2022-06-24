/*
    ***************** Largest Rectangle in a histogram **************

    arr[6] = {2, 1, 5, 6, 2, 3};

    find the largest Rectangle area of histogram


             |==|
          |==|  |
          |  |  |
          |  |  |  |==|
    |==|  |  |  |==|  |
    |  |==|  |  |  |  |          Fixed length we are going to extends (left + right) then we get Max area
    -------------------
    2   1  5  6   2  3


    Area => length * breath
            1  * 6 => 6

    Approach #1:
        Brute Force:
            for 1 all possible rectangle
            for 2 all possible rectangle
            ....
            ..
            ..
            n

            TC => O(n^2)

        for(int i = 0; i < n; i++)
        {
            while(left)
            {

            }
            while(right)
            {

            }

            newArea = i * (left + right);

            Area = max(Area, newArea);
        }


    Approach #2: TC => O(n)

        index:

        we have to know the

        1) next smaller
        2) and previous smaller
        3) element from the current element
        4) then we can find the width

        width = next - prev - 1;

        newArea = curr * width;   // curr == length

        Area = max(Area, newAre)


*/
#include<bits/stdc++.h>
using namespace std;


vector<int> nextSmallerElement(int arr[], int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--)
    {
        int curr = arr[i];

        while((st.top() != -1) && (arr[st.top()] >= curr))
        {
            st.pop();
        }

        // ans is stack
        ans[i] = st.top();
        // push index into stack
        st.push(i);
    }

    return ans;
}

vector<int> prevSmallerElement(int arr[], int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for(int i =0; i < n; i++)
    {
        int curr = arr[i];

        while((st.top() != -1) && (arr[st.top()] >= curr))
        {
            st.pop();
        }

        // ans is stack
        ans[i] = st.top();
        // push index into stack
        st.push(i);
    }

    return ans;
}
int largestRectangleArea(int arr[], int n)
{
    vector<int> next(n);
    next = nextSmallerElement(arr, n);

    vector<int> prev(n);
    prev = prevSmallerElement(arr, n);

    int Area = INT_MIN;
     for(int i = 0; i < n; i++)
     {
         int length = arr[i];

          // conner case
         // [2 2 2 2 2]
         // -1 -1 -1 -1

         if(next[i] == -1)
         {
             next[i] = n;
         }

         int width = next[i] - prev[i] - 1;


         int newArea = length * width;

         Area = max(Area, newArea);
     }

     return Area;
}


int main()
{


    int arr[6] = {2, 1, 5, 6, 2, 3};

    cout << largestRectangleArea(arr, 6);


    return 0;
}
