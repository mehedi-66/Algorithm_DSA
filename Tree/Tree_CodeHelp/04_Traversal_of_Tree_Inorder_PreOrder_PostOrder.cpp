/*
    ***************** Traversal of Tree **************

    InOrder     PreOrder    PostOrder

    LNR         NLR          LRN

*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d)
        {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }

};

Node* bulidTree(Node* root)
{
    cout << "Enter Data: ";
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout << "Enter Left data: " << data << endl;
    root -> left = bulidTree(root->left);
    cout << "Enter Right data: " << data << endl;
    root -> right = bulidTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root)
{
    queue< Node* > q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout << temp -> data << " ";

        if(temp -> left)
        {
             q.push(temp -> left);
        }

        if(temp -> right)
        {
            q.push(temp->right);
        }



    }
}

void inorder(Node* root)
{
    // base case
    if(root == NULL)
    {
        return ;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);

}

void preorder(Node* root)
{
    // base case
    if(root == NULL)
    {
        return ;
    }

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);


}

void postorder(Node* root)
{
    // base case
    if(root == NULL)
    {
        return ;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";

}
int main()
{

    Node* root = NULL;

    root = bulidTree(root);

    levelOrderTraversal(root);
    inorder(root);
    preorder(root);
    postorder(root);

    return 0;
}
