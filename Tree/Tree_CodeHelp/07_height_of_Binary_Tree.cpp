/*
    Time ==> O(n)
    space => O(n) ==> best case O(height) and skew tree => o(n) worst case


    height = longest path => root to leaf Node

    Approach:
        recursion:
            left = find(height)
            right = find(height)

            ans = max(left, right) + 1; // + root



*/
#include<bits/stdc++.h>
using namespace std;

int height(Node * root)
{
    // base case
    if(root == NULL)
    {
        return 0;
    }
    // way
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

int minDepth(TreeNode* root) {

         // base case
        if(root == NULL)
        {
            return 0;
        }
        if(root->left == NULL && root->right == NULL) return 1;
        int left, right;
        left = right = INT_MAX;
        // way
     if(root->left)   left = minDepth(root->left);
     if(root->right)  right = minDepth(root->right);

        int ans = min(left, right) + 1;
        return ans;
}

int main()
{


    return 0;
}
