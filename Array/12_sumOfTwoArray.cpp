/*
    sum of two array element ....

    arr1 = {1, 2, 3, 4}
    arr2 = {6}

    1 2 3 4
          6
   ------------
    1 2 4 0


    1) array length and carry
     carry = sum / 10;
     arr[i] = sum % 10;

*/

#include<bits/stdc++.h>
using namespace std;


vector< int > Reverse(vector< int > v)
{
    int s = 0;
    int e = v.size() - 1;

    while(s <= e)
    {
        swap(v[s++], v[e--]);
    }

    return v;
}
vector< int > sumOfTwoArray(vector< int > a, vector< int > b)
{
    vector< int > ans;

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while(i >= 0 && j >= 0)
    {
        int val1 = a[i];
        int val2 = b[j];

        int sum = val1 + val2 + carry;

        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);

        i--;
        j--;
    }
    while(i >= 0)
    {
        int sum  = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while(j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    while(carry != 0)
    {
        int sum  = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }

    // reverse the ans array coz all element we insert .. ultta...way

   ans = Reverse(ans);
    return  ans;
}


int main()
{

    vector< int > a = {1, 2, 3, 4};
    vector< int > b = {6};
    vector< int > v = sumOfTwoArray(a, b);

    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
