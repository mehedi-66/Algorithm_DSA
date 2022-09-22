/*
    ************** Check the Given Tree is valid BST or not ***************

    1) Every Node left Subtree is less than the root node
    2) Every Node right subtree is Greater that the root Node

    we have to maintain a [] range

    if the node is the between a range the it is valid

                    5
                  /   \
 [INT_MIN, 5]    3     7   [5, INT_MAX]

*/

bool isValid(TreeNode * root)
{
    return isValidBST(root, INT_MIN, INT_MAX);
}

bool isValidBST(TreeNode* root, minVal, maxVal)
{
    if(root == NULL) return true;

    if(root->data >= maxVal || root->data <= minVal) return false;

    return isValidBST(root->left, minVal, root->data) && isValidBST(root->right, root->data, maxVal);
}
