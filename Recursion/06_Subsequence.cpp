/*
    ********************* Recursion Subsequence **********

    Powes set

    a contigous and non-contigous sequences,
    which follows the order

    3 => 2^3 => 8 many subsequence

    arr = {3, 1, 2}
    3
    1
    2
    3 1
    1 2
    3 2
    3 1 2
--------------------

    1 x 1 taken and not taken of the indexes
=> 3   2
    x 1 1
=>    1 2

*/
#include<bits/stdc++.h>
using namespace std;
void subsequence(int index, int n, int arr[], vector<int> &sub)
{
    if(index >= n)
    {
        // print the subsequence
        for(auto x : sub)
        {
            cout << x << " ";
        }
        cout << endl;

        return ;

    }

    // take of the index
    sub.push_back(arr[index]);

    subsequence(index + 1, n, arr, sub);


    // not take the index
    sub.pop_back();

    subsequence(index + 1, n, arr, sub);



}
int main()
{
    int arr[5] = {3, 1, 2};
    vector<int> v;
    subsequence(0, 3, arr, v);

    return 0;
}
