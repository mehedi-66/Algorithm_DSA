

/*
        100. Same Tree

       Given the roots of two binary trees p and q, write a function to check if they are the same or not.

    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


        1               1
       / \            /  \
      2   3          2    3

*/




class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // traverse two tree at a time and check
        if(p  == NULL && q == NULL)
        {
            return true;
        }
        if(p == NULL && q != NULL)
        {
            return false;
        }
        if(p != NULL && q == NULL)
        {
            return false;
        }

        // left and right visit
        bool left = isSameTree(p -> left , q -> left);
        bool right = isSameTree(p -> right, q -> right);

        bool value = p -> val == q -> val;

        if(left && right && value)
        {
            return true;
        }
        else{
            return false;
        }
    }
};
