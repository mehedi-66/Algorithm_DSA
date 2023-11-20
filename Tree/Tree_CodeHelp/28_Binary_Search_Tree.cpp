/*

    **************** Binary Search Tree ************************

                                root
                               /    \

                All   less than       greater than

        Example of BST:
                            10
                           /  \
                          7    15
                         / \     \
                        5   9     17
                                 /  \
                                16   19


            Base case : insertion complexity O(log n)

                            avg             Skew
            Insertion  =>   O(h)            O(n)
            Search     =>   O(h)            O(n)
            Deletion  =>


            BST => InOrder Traversal is Sorted Order

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
Node* insertIntoBST(Node* root, int data)
{
    if(root == NULL)
    {
        root = new Node(data); // initial node
        return root;
    }

    if(data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;


}

void takeInput(Node* &root)
{

    int data;
    cin >> data;
    while(data != -1)
    {

        root = insertIntoBST(root, data);
        cin >> data;
    }
}
int main()
{

    Node* root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);


    return 0;
}
