/*
    ****** Insert at The last or Tail **********

    10 30 40

    [10 | *] --> [30 | *] --> [40 | *] --> NULL


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

void InsertAtTail(Node * &tail, int data)
{
    // create Node
    Node * temp = new Node(data);

    // link
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
    cout << endl;
}


int main()
{
    Node * head = new Node(10);
    Node * tail = head;

    InsertAtTail(tail, 30);
    InsertAtTail(tail, 40);

    print(head);
    // output: 10 30 40




    return 0;
}
