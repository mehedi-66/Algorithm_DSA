#include<bits/stdc++.h>
using namespace std;
void inorder(Node * root, int &cnt)
{
    // base case
    if(root == NULL)
    {
        return ;
    }

    inorder(root -> left, cnt);
    // logic
    if(root -> left == NULL && root -> right == NULL)
    {
        cnt++;
    }
    inorder(root->right, cnt);
}

int countLeafNode(Node * root)
{
    int cnt = 0;
    inorder(root, cnt);
}
int main()
{

    countLeafNode(root);
    return 0;
}
