/*
    ************* Level Order Travarsal*************

                    1
                   /  \
                  2    3
                 / \   / \
                4  5  6   7

            Visited level by level:
            1
            2 3
            4 5 6 7

            output: 1 2 3 4 5 6 7


     1) Need Queue data structure
     2) initially root insert on queue
     3) Need a vector of vector wise vector< vector<int> >
     4) pick queue element and traverse
     5) if node has left or right element then put it on the queue
     6) if the node all left and right is visited then push in to the vector of level

*/

#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > levelOrder(TreeNode* root)
{
    vector< vector<int> > ans;

    if(root == NULL)
    {
        return ans;
    }
    queue< TreeNode* > q;
    q.push(root);

    while( !q.empty() )
    {
        int size = q.size();
        vector<int> level;

        for(int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if(node-left != NULL)
            {
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
            level.push_back(node->val);
        }
        ans.push_back(level);
    }

    return ans;

}



int main()
{


    return 0;
}
