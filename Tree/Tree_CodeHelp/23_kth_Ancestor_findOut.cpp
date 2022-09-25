/*
    **************** k th Ancestor find out ********************

                                1
                              /   \
                             2    3
                           /  \
                           4   5

                           4 node ==> k=1 ancestor find out

        Approach 1:
             root to nth nodes path find out then ==> back to traverse on the path

                                  2  1 0
        in case ==> 4 to root ==> 1 2 4

                    k2 ==> 1 is kth node of ancestor

      Approach 2:
            Recursive way
            we do not want to use ==> vector extra space

*/
#include<bits/stdc++.h>
using namespace std;

Node* solve(Node* root, int &k, int node)
{
    // base case
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data ==  node)
    {
        return root;
    }

    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);

    // back time
    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k <= 0)
        {
            // ans lock
            k = INT_MAX; // so that not reach in the zero again
            return root;
        }
        return leftAns;

    }

    if(leftAns == NULL && rightAns != NULL)
    {
         k--;
        if(k <= 0)
        {
            // ans lock
            k = INT_MAX; // so that not reach in the zero again
            return root;
        }
        return rightAns;
    }

    return NULL;

}

int kthAncestor(Node* root, int k, int node)
{
    Node* ans = solve(root, k, node);
    // ans is root node then return -1;
    if(ans == NULL || ans->data == node)
    {
        return -1;
    }
    else{
        return ans->data;
    }
}
int main()
{


    return 0;
}
