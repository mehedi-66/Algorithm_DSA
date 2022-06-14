/*
    ************ Letter Combination of a Phone Number *********


*/
#include<bits/stdc++.h>
using namespace std;

void solve(string digit, string output, int index, vector<string> &ans, string mapping[])
{
    // base case
    if(index >= digit.length())
    {
          ans.push_back(output);
          return;
    }

    int number = digit[index] - '0';
    string value = mapping[number];

    for(int i = 0; i < value.size(); i++)
    {
        output.push_back(value[i]);
        solve(digit, output, index+1, ans, mapping);

        output.pop_back();
    }

}
int main()
{

     string digit;
     cin >> digit;
     vector<string> ans;
     string output;
     int index = 0;
     string mapping[10] = {"","","abc","def","ghi","jkl","mno", "pqrs", "tuv","wxyz"};

     solve(digit, output, index, ans, mapping);

     for(int i = 0; i < ans.size(); i++)
     {
         cout << ans[i] << " ";
     }
    return 0;
}
