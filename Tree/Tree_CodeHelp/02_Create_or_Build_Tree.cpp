/*
                1
               / \
              3    5
             / \   / \
            7  11  17

*/

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
        int data;
        Node * left;
        Node * right;

        Node(int d)
        {
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }

};

Node* buildTree(Node* root)
{
    cout << "Enter the Data: ";
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left: " << endl;
    root -> left = buildTree(root->left);
    cout << "Enter data for inserting in Right: " << endl;
    root -> right = buildTree(root->right);

    return root;

}
int main()
{
    Node* root = NULL;

    // creating a tree
     root = buildTree(root);

    return 0;
}
