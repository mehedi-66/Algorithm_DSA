/*
    ************ Symmetrical Binary Trees **************

    => Draw the state line  based on the center and ... impose left half to right half
    => left half miror to Right half then it called the Symmetrical Tree

    Example 1:  Yes

                1
               / \
              2   2
             / \  / \
            3  4  4  3

    Example 2: No
                 1
               /  \
              2    2
               \    \
               3     3


    Approach: of Tree
            => If we Remove Root and
            => Consider the 1) Left Tree     2) Right Tree => Both different Tree
            => Left Tree    and Right Tree Visit   At the same time and check ... both current position data same
            => If yes Otherwise No

*/
#include<bits/stdc++h>
using namespace std;

  bool solve(TreeNode* L, TreeNode* R)
    {
        if(L == NULL && R == NULL)
        {
            return true;
        }
        if((L == NULL && R != NULL) || (L != NULL && R == NULL))
        {
            return false;
        }
        if(L->val != R->val)
        {
            return false;
        }

        return solve(L->left , R -> right) && solve(L->right, R ->left);

    }

    // from main function
bool isSymmetric(TreeNode* root) {

        if(root == NULL)
        {
            return true;
        }

        return solve(root->left, root->right);
    }
