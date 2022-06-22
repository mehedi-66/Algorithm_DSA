/*
    ************** Doubly Link List *****************

        prev      next
        [ * | 5 | * ]

        Two Link List


*/
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node * prev;
        Node * next;

        Node(int d)
        {
            this -> data = d;
            this -> prev = NULL;
            this -> next = NULL;
        }

        // destructor
        ~Node()
        {
            int val = this->data;
            if(next != NULL)
            {
                delete next;
                next = NULL;
            }

        }
};

int getLength(Node * head)
{
     int len = 0;
     Node * temp = head;

     while(temp != NULL)
     {
         len++;
         temp = temp -> next;
     }

     return len;
}

void print(Node * head)
{
    Node * temp = head;
    while(temp != NULL)
    {
         cout << temp -> data << " " ;
         temp = temp -> next;
    }

    cout << endl;
}

// Insert at head Node

void InsertAtHead(Node * &head, Node* &tail, int d)
{

    // if list is empty
    if(head == NULL)
    {
        Node * temp = new Node(d);
        head = temp;
        tail = temp;
        return ;
    }
    // create Node
    Node * temp = new Node(d);
    //    temp            head
    // [* |10| *]      [* |5| *]

    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

// Insert at Tail Node

void InsertAtTail(Node* &head, Node* &tail, int d)
{
    // if list is empty
    if(tail == NULL)
    {
        Node * temp = new Node(d);
        tail = temp;
        head = temp;
        return;
    }
     // create Node
     Node * temp = new Node(d);

     //  head                    tail           temp
    // [* |3| *]  [* |4| *]  [* |7| *]       [* |10| *]

    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void InsertAtPosition(Node* &head, Node * &tail, int position, int d)
{
    // insert at Start
    if(position == 1)
    {
        InsertAtHead(head, tail, d);
        return ;
    }

    Node * temp = head;
    int cnt = 1;

    while(cnt < position - 1 )
    {
        temp = temp -> next;
        cnt++;
    }

    // insert at Last Position
    if(temp -> next == NULL)
    {
        InsertAtTail(head, tail, d);
        return ;
    }

    // create a Node for d
    Node * nodeToInsert = new Node(d);
    //       nodeToInsert
    //         []
    //    temp
    // []  []    []  []

    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;


}

// ************ Deleting of Doubly Link List

void DeleteNode(int position, Node* &head)
{
    // deleting first or start Node
    if(position == 1)
    {
        Node * temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;

        delete temp;
    }
    else{
         //         prev  curr
        // []  []   []     []     []

        // deleting any middle node or last node
        Node * curr = head;
        Node * prev = NULL;

        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        // linking
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}

int main()
{
    Node * node1 = new Node(10);
    Node * head = node1;
    Node * tail = node1;

    InsertAtHead(head, tail, 20);
    InsertAtHead(head, tail, 30);

    InsertAtTail(head, tail, 40);
    print(head);
    // output: 30 20 10 40


    InsertAtPosition(head, tail, 2, 100);

    print(head); // output: 30 100 20 10 40


    // delete Node
    DeleteNode(2, head);

    print(head); // output: 30 20 10 40
    cout << getLength(head) << endl;

    return 0;
}

