/*
    **************** Subsequence of String *********
    string s = "abc";

    remove and not remove and get subsequence
        bc
        ac
        ab
        a
        b
        c
       abc
        ""
*/
#include<bits/stdc++.h>
using namespace std;

void solve(string str, string output, int index, vector<int> ans)
{
    // base case
    if(index >= str.size())
    {
        // if not need empty string
        if(output.size()>0){
            ans.push_back(output);
        }

        return ;
    }

    // exclude
    solve(str, output, index+1, ans);

    // include
    char element = str[index];
    output.push_back(element);
    solve(str, output, index+1, ans);

}

int main()
{
    string str = "abc";

    vector<string> ans;
    string output = "";
    int index = 0;

    solve(str, output, index, ans);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }


    return 0;
}
