
/*
    98. Validate Binary Search Tree

    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

*/






class Solution {
public:

    bool solve(TreeNode* root,  long long int Min,  long long int Max)
    {
        if(root == NULL)  return true;

        if(root->val >= Max || root->val <= Min) return false; // out of boundary

        bool left = solve(root->left, Min, root->val);
        bool right = solve(root->right, root->val, Max);

        return left && right;

    }

    bool isValidBST(TreeNode* root) {
        long long int a = -10e12;
         long long int b = 10e12;
        return solve(root, a, b);
    }
};
