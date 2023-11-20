
/*
        102. Binary Tree Level Order Traversal


    Given the root of a binary tree,
    return the level order traversal of its
    nodes' values. (i.e., from left to right, level by level).


            3
           /  \
          9   20
             /  \
            15   7


    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]
*/










class Solution {
public:
    vector<vector<int>> ans;

    void solve(TreeNode* root)
    {
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            TreeNode* x = q.front();
            q.pop();


            if(x == NULL)
            {
                if(!q.empty())
                    q.push(NULL);
                ans.push_back(temp);
                temp.clear();
            }
            else{

            temp.push_back(x->val);

            if(x->left)
                q.push(x->left);
            if(x->right)
                q.push(x->right);
            }


        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
       if(root == NULL) return ans;
        solve(root);

        return ans;
    }
};
