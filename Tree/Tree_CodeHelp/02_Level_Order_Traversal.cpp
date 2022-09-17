
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }

};

Node* buildTree(Node* root)
{
    cout << "Enter data: ";
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout << "Enter left Data: " << data << " " << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter right Data; " << data << " " << endl;
    root -> right = buildTree(root -> right);

    return root;
}

// BFS like Printing

void levelOrderTraversal(Node* root)
{
    queue< Node* > q;
    q.push(root);
    q.push(NULL); // sepearator use .... level order traversal

    while(!q.empty())
    {
        Node* temp = q.front();

        q.pop();

        if(temp == NULL) // prevLevel complete Traversal
        {
            cout << endl;
            if(!q.empty())  // queue still has some child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
             cout << temp -> data << " "; // printing

            if(temp -> left)
            {
                q.push(temp -> left);
            }

            if(temp -> right)
            {
                q.push(temp -> right);
            }
        }


    }

}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);

    return 0;
}
