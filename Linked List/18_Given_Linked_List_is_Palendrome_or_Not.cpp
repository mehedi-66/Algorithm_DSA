/*
    ************* given Linked List is Palindrome or Not *****************
    Approach 1:
        copy linked list element into array  then check

    Approach 2:
        not Copy O(1) space
        1) find middle of Linked List ==> right part reverse  (1 2 3 3 2 1)
          2) 1 2 3  -> 1 2 3 compeair left and right part

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
        temp  = temp -> next;
    }
}

Node * getMiddle(Node * head)
{
    Node * slow = head;
    Node * fast = head -> next;

    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
}

Node * reverse(Node * head)
{
    Node * curr = head;
    Node * prev = NULL;
    Node * next = NULL;

    while(curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
bool isPalindrome(Node * head)
{
    if(head -> next == NULL)
    {
        return true;
    }

    // step 1 ==> find middle
    Node * middle = getMiddle(head);

    // step2 ==> reverse List after find middle
     Node * temp = middle -> next;
     middle -> next = reverse(temp);

    // step 3 ==> half
    Node * head1 = head;
    Node * head2 = middle -> next;

    while(head != NULL)
    {
        if(head -> data != head2 -> data)
        {
             return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    // linked list back to normal
      temp = middle -> next;
      middle -> next = reverse(temp);


    return true;
}

int main()
{


    return 0;
}
