/*
    ************** Singly LL ************
    [ 4 | *] --> [ 5| *] --> [ 7| *]---> NULL

    Insert at the head position :

     Head
     |
    [ 5| *] --> NULL


    new Node insert 7

    Head
    |
    [ 7| *]--> [ 5| *]---> NULL



    *********** Way
        temp -> next = Head;
        Head = temp;






*/
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node * next;

        Node(int data)
        {

            this -> data = data;
            this -> next = NULL;
        }


};

void InsertAtHead(Node * &head, int d)
{

    // create New Node
    Node * temp = new Node(d);
    temp -> next = head;
    head = temp;

}

void print(Node * &head)
{
    Node* p = head;
    while(p != NULL)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
}
int main()
{
    // object create of Node
    Node * node1 = new Node(10);

    Node * head = node1;

    InsertAtHead(head, 5);
    InsertAtHead(head, 20);
    print(head);

    // output: 20 5 10

    return 0;
}
