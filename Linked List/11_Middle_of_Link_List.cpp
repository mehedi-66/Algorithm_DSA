/*
    ************** Middle of Link List ***********
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
    tail->next = temp;
    tail = temp;
}
void print(Node * &head)
{
    Node * temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
int getLength(Node * head)
{
    int len = 0;

    while(head != NULL)
    {
        len++;
        head = head -> next;
    }

    return len;

}

int findMiddle(Node * head)
{
    int len = getLength(head);

    return (len/2);
}

// Good Approach

Node * getMiddle(Node * head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

  if(head -> next -> next == NULL){

        // if only two node
        return head -> next;
    }

        Node * slow = head;
        Node * fast = head -> next;

        while(fast != NULL)
        {
            fast = fast -> next;

            if(fast  != NULL)
            {
                fast = fast -> next;
            }

            slow = slow -> next;
        }

        return slow;

}
int main()
{
    Node * head = new Node(10);
    Node * tail = head;

    InsertAtLast(tail, 20);
    InsertAtLast(tail, 30);
    InsertAtLast(tail, 40);

   int ans = findMiddle(head);

    Node * temp = head;

    while(ans--)
    {
        temp = temp -> next;
    }

    cout << temp -> data << endl;

    temp = getMiddle(head);
    cout << temp -> data << endl;

    return 0;
}
