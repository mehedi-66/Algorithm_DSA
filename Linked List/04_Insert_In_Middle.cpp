/*
    *********** Insert In Middle *********

    10 30 40

    [10 | *] --> [30 | *] --> [40 | *] --> NULL

    Now 20 insert In 2nd position

    [10 | *] --> [20 | *] --> [30 | *] --> [40 | *] --> NULL

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
};

void InsertAtHead(Node * &head, int d)
{
    // create new Node
    Node * temp = new Node(d);

    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node * &tail, int d)
{
    // create Node
    Node * temp = new Node(d);

    tail -> next = temp;
    tail = temp;
}

void InsertAtPosition(Node * &head, Node * &tail,  int position, int d)
{
    // insert at Start
    if(position == 1)
    {
        InsertAtHead(head, d);
    }

    Node * temp = head;

    int cnt = 1;

    while(cnt < position-1)
    {
        temp = temp -> next;
        cnt++;
    }

    // insert at Last position
    if(temp -> next == NULL)
    {
        InsertAtTail(tail, d);
    }

    // creating a Node for d
    Node * nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void print(Node * &head)
{
    Node * p = head;

    while(p != NULL)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}


int main()
{
    Node * head;
    Node * tail;

    InsertAtHead(head, 10);
    tail = head;
    InsertAtTail(tail, 30);
    InsertAtTail(tail, 40);

                // head , position, value
    InsertAtPosition(head, tail,  2, 20);

    print(head);
    return 0;
}
