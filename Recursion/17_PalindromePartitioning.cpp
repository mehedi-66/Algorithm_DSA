/*
    ******************* Palindrome Partitioning **********
    131 LeetCode

    Given a string S partition S such a that substring of the partition is palindrome. Return all possible palindrome partitioning of S
    A palindrome string is a string that reads the same backward as forward

    Input: S = "aab";
    output: ["a", "a", "b"], ["aa", "b"]


**************************** Trying to Partition *******************

                            aabb
                          ----------
                         /     |    \
                        /      |     \
                      a|abb   aa|bb  aab|b
                        ---
                       /   \           x  not valid partitioning
                      /     \
                    a|a|bb    aab|b
                        --      x
                        /  \
                       /    \
                  a|a|b|b   a|a|bb|
                    |
                    |
                 a|a|b|b|

                 return back ... backtracking
*/
#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string S, int start, int end)
{
    while(start <= end)
    {
        if(S[start] != S[end])
        {
            return false;
        }
        start++;
        end--;
    }

    return true;

}


void solve(int index, string S, vector<string> &Partition, vector< vector<string> > &ans)
{
    if(index == S.size())
    {
        ans.push_back(Partition);
        return ;
    }

    // run loop for every index try to partition
    for(int i = index; i < S.size(); i++)
    {
        if(isPalindrome(S, index, i) == 1)
        {
            // try to create Partition
            Partition.push_back(S.substr(index, i - index + 1));

            solve(i+1, S, Partition, ans);

            // remove previously push Partition and BackTracking
            Partition.pop_back();
        }
    }

}

int main()
{
    string S = "aabb";
    vector< vector<string> > ans;
    vector<string> Partition;

    solve(0, S, Partition, ans);


    // print ans

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }


    return 0;
}
