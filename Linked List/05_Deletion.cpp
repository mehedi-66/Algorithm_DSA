/*
    ********************* Deletion *****************

    delete Node ==> head, tail, position or value


*/
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;

        Node(int d)
        {
            this -> data = d;
            this -> next = NULL;
        }

    // Destructor
    ~Node()
    {
        int value = this -> data;
        // memory free
        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
    }

};

void InsertAtTail(Node * &tail, int d)
{
    // create Node
    Node * temp = new Node(d);

    tail -> next = temp;
    tail = temp;
}

void deleteNode(int position, Node * &head)
{
    // deleting first or start Node
    if(position == 1)
    {
        Node * temp = head;
        // move
        head = head -> next;

        // memory
        temp -> next = NULL;
        delete temp;

    }
    else{ // Middle or Last Node Delete

        Node * curr = head;
        Node * prev = NULL;

        int cnt = 1;

        while(cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;

        // memory free
        curr -> next = NULL;
        delete curr;

    }
}

void print(Node * &head)
{
    Node * p = head;
    while(p != NULL)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
}
int main()
{
    Node * head = new Node(10);
    Node * tail = head;

    InsertAtTail(tail, 20);
    InsertAtTail(tail, 30);
    InsertAtTail(tail, 40);

    deleteNode(2, head);

    print(head);


    return 0;
}
