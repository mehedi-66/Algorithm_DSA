/*
                    avg             Skew
            Insertion  =>   O(h)            O(n)
            Search     =>   O(h)            O(n)
            Deletion  =>


            BST => InOrder Traversal is Sorted Order

*/


#include<bits/stdc++.h>
using namespace std;

bool searchBST(Node * root, int x)
{
    if(root == NULL)
    {
        return false;
    }

    if(root->data == x)
    {
        return true;
    }
    if(root->data > x)
    {
        // left part
        return searchBST(root->left, x);
    }
    else
    {
        // right part
        return searchBST(root->right, x);

    }
}


// Iterative solution

bool searchBST(Node* root)
{
    Node* temp = root;

    while(temp != NULL)
    {

        if(temp->data == x)
        {
            return true;
        }

        if(root->data > x)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
}
int main()
{



    return 0;
}
