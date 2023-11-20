
/*
    ******************** 108. Convert Sorted Array to Binary Search Tree ****************************

    Given an integer array nums where the elements are sorted in ascending order, convert it to
    a height-balanced binary search tree.


    Example:
        [-10,-3,0,5,9]

        find out mid then ... divided the array two part ... left and right
        this way
                        0
             [-10, -3]      [5, 9]
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        return createTree(nums, 0, nums.size()-1);
    }

    TreeNode* createTree(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = (start + end)/2;

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = createTree(nums, start, mid-1);
        node->right = createTree(nums, mid+1, end);
        return node;
    }

};
