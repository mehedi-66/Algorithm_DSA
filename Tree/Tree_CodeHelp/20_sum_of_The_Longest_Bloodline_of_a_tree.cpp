/*
    ********** sum of The Longest Bloodline of a Tree *********

    ==> sum of nodes on the longest path from root to leaf node

   ==> Root to leaf nodes ==> longest path sum

                            4
                          /   \
                         2     5
                       /  \    / \
                      7    1  2   3
                          /
                         6

                13     13    11   12

                longest path 13 second one

    Approach:
            <sum, numberOfNode>
            each node

            go root to leaf node




*/

#include<bits/stdc++.h>
using namespace std;
void solve(Node* root, int sum, int &maxSum, int len, int &maxLen)
{
    // base case
    if(root == NULL)
    {
        if(len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }

        return ;
    }

    sum += root->data;

    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);

}

int sumOfLongestRootToLeafPath(Node* root)
{
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
}
int main()
{


    return 0;
}
