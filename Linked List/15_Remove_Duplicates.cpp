/*
    ************ Remove Duplicates in Sorted and Unsorted Linked list ************



    // Random order Linked List duplicate element

    Approach 1: O(n^2)
        current +1 element to last if same type element present then delete all of them

    Approach 2: sort Linked List O( n log n)
        then delete O(n)

    Approach 3: time => O(n) space O(n) map< Node * , bool > visited



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
    cout << endl;
}

void RemoveDuplicates(Node * head)
{
    // empty list
    if(head == NULL)
    {
        return ;
    }

    // non empty list
    Node * curr = head;

    while(curr != NULL)
    {
         // [1]  [2] [2] [3]
        // focus curr -> next not null
        if((curr -> next != NULL) && curr -> data == curr -> next -> data)
        {
            Node * next_next = curr -> next -> next;
            Node * nodeToDelete = curr -> next;

            delete (nodeToDelete);
            curr -> next = next_next;

        }
        else{ // no equal

            curr = curr -> next;
        }
    }
}


int main()
{

    Node * head = new Node(10);
    Node * tail = head;

    InsertAtLast(tail, 20);
    InsertAtLast(tail, 30);
    InsertAtLast(tail, 30);
    InsertAtLast(tail, 30);

    print(head);

    RemoveDuplicates(head);

    print(head);
    return 0;
}
