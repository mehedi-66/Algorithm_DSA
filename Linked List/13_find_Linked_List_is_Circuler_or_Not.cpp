/*
    ************* Given Linked List is Circularly Linked or Not ***********

    if full linked List has no next node is NULL then it is Circular
    Empty Linked list also Circular

    head to start traverse and again meet to head node then is consider as Circular Linked List

*/
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node * next;

        Node(int d)
        {
            this -> data = d;
            this -> next = NULL;
        }
};
void InsertAtLast(Node * &tail, int d)
{
    Node * temp = new Node(d);
    tail -> next = temp;
    tail = temp;

}
void print(Node * head)
{
    Node * temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
int isCircular(Node * head)
{
    if(head == NULL)
    {
        return true;
    }

    Node * temp = head -> next;

    while(temp != NULL && temp != head)
    {
        temp = temp -> next;
    }

    if(temp == head)
    {
        return true;
    }

    return false;

}
int main()
{
     Node * head = new Node(10);
    Node * tail = head;

    InsertAtLast(tail, 20);
    InsertAtLast(tail, 30);
     InsertAtLast(tail, 40);
      InsertAtLast(tail, 60);

  //  print(head);

    // last pointer next indicate into head
    tail -> next = head;

    //print(head);

    cout << isCircular(head) << endl;
    return 0;

}
