/*
    **************** Build Tree by Level Order **************

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

void bulidFromLevelOrder(Node* &root)
{
    queue<Node* > q;

    cout << "Enter Data for root: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left Node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1)
        {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right Node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1)
        {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
}
// BFS
void levelOrderTraversal(Node* root)
{
    queue<Node* > q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        cout << temp -> data << " ";
        q.pop();

        if(temp -> left)
        {
            q.push(temp->left);
        }
        if(temp -> right)
        {
            q.push(temp->right);
        }
    }
}
int main()
{
    Node* root = NULL;
    bulidFromLevelOrder(root);

    levelOrderTraversal(root);

    return 0;
}
