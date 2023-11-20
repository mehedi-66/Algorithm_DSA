/*
    103. Binary Tree Zigzag Level Order Traversal

    Given the root of a binary tree, return the zigzag level
    order traversal of its nodes' values. (i.e., from left to right, then
    right to left for the next level and alternate between).

         3
           /  \
          9   20
             /  \
            15   7

    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[20,9],[15,7]]

*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > result;
        if(root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        bool LeftToRight = true;

        // level order traversal

        while(!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);

            for(int i = 0; i < size; i++)
            {
                TreeNode* frontNode = q.front();
                q.pop();

                // fill up data normal order or reverse order
                int index = LeftToRight ? i : size - i - 1;
                ans[index] = frontNode->val;

                if(frontNode->left)
                {
                    q.push(frontNode->left);
                }
                if(frontNode->right)
                {
                    q.push(frontNode->right);
                }
            }

            // direction change
            LeftToRight = !LeftToRight;

            result.push_back(ans);

        }
          return result;
    }


};
