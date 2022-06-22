/*
    **************** Reverse a Link List *************


*/
#include<bits/stdc++.h>
using namespace std;
class Node{
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
    // create Node
    Node * temp = new Node(d);

    tail -> next = temp;
    tail = temp;
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
void RecReverse(Node * &head, Node * curr, Node * prev)
{
    // base case
    if(curr == NULL)
    {
        head = prev;
        return ;
    }
    else{

        Node * forward = curr -> next;
        RecReverse(head, forward, curr);
        curr -> next = prev;
    }
}
void Reverse(Node * &head)
{

    if(head == NULL || head->next == NULL)
    {
        return ;
    }
    else{
        Node * prev = NULL;
        Node * curr = head;
        Node * forward = head;

        RecReverse(head, curr, prev);

       /*
        while(curr != NULL)
        {
            forward = forward -> next;
            curr -> next = prev;
            prev = curr;
            curr  = forward;
        }

        head = prev;

        */
    }
}
int main()
{
    Node * head = new Node(10);
    Node * tail = head;

    InsertAtLast(tail, 20);
    InsertAtLast(tail, 30);

    print(head);

    Reverse(head);

    print(head);

    return 0;
}

