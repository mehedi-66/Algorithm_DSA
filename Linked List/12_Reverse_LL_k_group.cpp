/*
    ************ Reverse Link List ***********
    Reverse Link List with k Group

    k = 2

    3  2  7  8  9  11

    2  3  8  7  11   9

    Approach:
        starting k node reverse Rest of the Recursion will Solve

        [] [] [] [] [] []


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

Node * kReverse(Node * head, int k)
{
    // base case
    if(head == NULL)
    {
        return NULL;
    }

    // step1: reverse first k nodes
    Node * forward = NULL;
    Node * curr = head;
    Node * prev = NULL;

    int cnt = 0;

    while(curr != NULL && cnt < k)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;

        cnt++;
    }
    // step2: Recursion will help

    if(forward != NULL)
    {
        head -> next = kReverse(forward, k);
    }

    // step3: return head of recursive call
    return prev;
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
int main()
{
    Node * head = new Node(10);
    Node * tail = head;

    InsertAtLast(tail, 20);
    InsertAtLast(tail, 30);
     InsertAtLast(tail, 40);
      InsertAtLast(tail, 60);

    print(head);

    head = kReverse(head, 2);

    print(head);
    return 0;
}
