/*
    ***************** Circular Linked List **************


*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node * next;

        // constructor
        Node(int d)
        {
            this->data = d;
            this->next = NULL;
        }

        ~Node()
        {
            int val = this->data;
            if(this->next != NULL)
            {
                delete next;
                next = NULL;
            }
        }
};

void insertNode(Node * &tail, int element, int d)
{
    // assuming that the element is present in the List

    // empty list
    if(tail == NULL)
    {
        Node * newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        // non-empty List
        // assuming that the element is present in the list

        Node * curr = tail;

        while(curr -> data != element)
        {
            curr = curr -> next;
        }

        // element found -> curr is representing element node
        Node * temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}
void print(Node * tail)
{
    Node * temp = tail;
    cout << tail -> data << " ";
    while(tail -> next != temp)
    {
        cout << tail -> data << " ";
        tail = tail -> next;
    }
}
int main()
{

    Node * tail = NULL;
    insertNode(tail, 5, 3);

    print(tail);

    return 0;
}
