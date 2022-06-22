/*
    ************ Add two number using given Linked List**********
     34
    230
    ____
     264

    Approach:
         1 2 3
           4 6

           We start making sum on the right position

           1) revers two linked list
                3 2 1
                6 4
                ____
                9 6 1
                maintain carry and on going

                ans linked list reverse
                1 6 9

*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d)
        {
            this->data = d;
            this->next = NULL;
        }
};

void print(Node* ans)
{
    Node* temp = ans;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* reverse(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward  ;
    }

    return prev;
}

void insertAtTail(Node* &head, Node* &tail, int val)
{
    Node* temp = new Node(val);

    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else{
        tail->next = temp;
        tail = temp;
        return;
    }
}
Node* add(Node* first, Node* second)
{
    /*
        After reverse
        5 4
        5 4 3
        _____
        0 9  3
        c1 c0
    */

    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(first != NULL && second != NULL)
    {
        //cout << first->data << " " << second->data << endl;

        int sum = carry + first->data + second->data;
        //cout << sum << endl;
        int digit = sum % 10;

        //Node* temp = new Node(digit);

        // create node ans add in answer Linked List
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;

        first = first -> next;
        second = second -> next;
    }

    while(first != NULL)
    {
        int sum = carry + first->data;
        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;

        first = first->next;
    }
    while(second != NULL)
    {
        int sum = carry + second -> data;
        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;

        second = second->next;
    }

    while(carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }

    return ansHead;

}

Node* addTwoLists(Node* first, Node* second)
{
    // step 1 - reverse input LL
    first = reverse(first);
    second = reverse(second);

    // step 2 - add 2 LL
    Node* ans = add(first, second);

    // step 3
      ans = reverse(ans);

      return ans;
}
// Improve coding Approach
Node* twoAdd(Node* first, Node* second)
{
    first = reverse(first);
    second = reverse(second);

    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;



    while(first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if(first != NULL)
            val1 = first -> data;

        int val2 = 0;
        if(second != NULL)
            val2 = second -> data;

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;

        if(first != NULL)
            first = first -> next;

        if(second != NULL)
            second = second -> next;
    }

    return ansHead;
}

int main()
{
    Node* first = NULL;
    Node* Ftail = NULL;

    insertAtTail(first, Ftail, 1);
    insertAtTail(first, Ftail, 4);
    insertAtTail(first, Ftail, 5);

    Node* second = NULL;
    Node* Stail = NULL;

    insertAtTail(second, Stail, 4);
    insertAtTail(second, Stail, 5 );

    ///Node* ans = addTwoLists(first, second);

   // print(ans);
   // print(first);
   // print(second);

    Node* ans1 = twoAdd(first, second);

    print(ans1);



    return 0;
}
