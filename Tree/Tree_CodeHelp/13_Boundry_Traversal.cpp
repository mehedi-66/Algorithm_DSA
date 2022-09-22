/*
    ************* Boundary Traversal *************
    1) left nodes print ==> without leaf node
    2) All leaf Node print
    3) Reverse order Right node print ===> except root, leaf Node


    How to print left part :
                    3
                  /  \
                4     5
                \
                 6

        root print first ==> 3
        root->left go and go print ===> if it is leaf node not print
        |
        if(left exit)
            call(left)
        else
            call(right)


    How to print all leaf node:


*/

#include<bits/stdc++.h>
int namespace std;

void traversalLeft(Node* root, vector<int> &ans)
{
        if(root == NULL)
        {
            return ;
        }

        if(root->left == NULL && root->right == NULL)
        {
            return ;
        }
        // print
        ans.push_back(root->data);

        if(root->left)
        {
             traversalLeft(root->left, ans);
        }
        else{
            traversalLeft(root->right, ans);
        }
}

void traversalLeaf(Node* root, vector<int> &ans)
{
    if(root == NULL)
    {
        return ;
    }
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return ;
    }
    traversalLeaf(root->left, ans);
    traversalLeaf(root->right, ans);
}

void TraverseRight(Node* root, vector<int> &ans)
{
    if(root == NULL)
    {
        return ;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return ;
    }

    //  if right has then go to right

    if(root->right)
    {
        TraverseRight(root->right, ans);
    }
    else{
        TraverseRight(root->left, ans);
    }

    // print ans in case backtracking
    ans.push_back(root->data);
}



vector<int> boundary(Node* root)
{
    vector<int> ans;
    if(root == NULL)
    {
         return ans;
    }
    //cout << "Root data print: " << root->data << endl;
    ans.push_back(root->data);

    // traverse Left Side Nodes
    traversalLeft(root->left, ans);


    // Traverse Leaf Nodes

    // left subtree
    traversalLeaf(root->left, ans);
    // right subtree
    traversalLeaf(root->right, ans);



    // Traverse Right side Nodes

    TraverseRight(root->right, ans);
}
int main()
{


    return 0;
}
