/*
    ********* Maximum sum of Non Adjacent Node **************

                        1
                      /   \
                     2     3
                   /      / \
                  1      4   5

                if root take then 2, 3 not get into the sum ==> 1+1+4+5 = 1
                if root not take then ==> lower 1, 4, 5 not get into sum ==> 2+3 => 5


       Approach:
             pair<a, b>
              a --> maxSum by including node at current level
              b --> maxSum by excluding node at current level

                     <1+4+11, 4+11> 1
                                  /   \
                          <2,4> 2      3   <3, 11>
                               /       / \
                        <4,0> 4  <5,0>5   6  <6,0>



*/
#include<bits/stdc++.h>
using namespace std;
pair<int, int> solve(Node* root)
{
    // base case
    if(root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right =solve(root->right);

    pair<int, int> res;
    // <a, b> ==> current level a includes and b excludes
    //  current level if a => includes then
    res.first = root->data + left.second + right.second;

    // current level excludes data ==> get max == prev level ==> include or exclude data
    res.second = max(left.first, left.second) + max(right.first, right.second);
    return res;
}


int getMaxSum(Node* root)
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}
int main()
{


    return 0;
}
