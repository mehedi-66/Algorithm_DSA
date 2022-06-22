/*
    ************ sort 0s, 1s, 2s in Linked List ************

    1 0 2 1 2

    => 0 1 1 2 2

    Approach 1: count how may 0 and 1 and 2
        then place them from beginning to

    Approach 2: Data replacement is not allowd
        then ==> change the Node Link
        We make the Link list ==>

        zero =>
        one =>
        two =>

        store and after all done merge All of them



*/

#include<bits/stdc++.h>
using namespace std;

void sortList(Node * head)
{
    int zeroCount = 0;
    int oneCout = 0;
    int twoCout = 0;

    Node * temp = head;

    while(temp != NULL)
    {
        if(temp -> data == 0)
            zeroCount++;
        else if(temp -> data)
            oneCout++;
        else if(temp -> data)
            twoCout++;

        temp = temp -> next;
    }

    temp = head;

    while(temp != NULL)
    {
        if(zeroCount != 0)
        {
            temp -> data = 0;
            zeroCount--;
        }
        else if(oneCout != 0)
        {
            temp -> data = 1;
            oneCout--;
        }
        else if(twoCout != 0)
        {
            temp -> data = 2;
            twoCout--;
        }

        temp = temp -> next;

    }
}

void insertAtTail(Node * &tail, Node * curr)
{
    tail -> next = curr;
    tail = curr;
}
// with out change the data only change the link

void sortList(Node * head)
{
    // dummy node create with -1;
    Node * zeroHead = new Node(-1);
    Node * zeorTail = zeroHead;
    Node * oneHead = new Node(-1);
    Node * oneTail = oneHead;
    Node * twoHead = new Node(-1);
    Node * twoTail = twoHead;

    Node * curr = head;

    while(curr != NULL)
    {
        int value = curr -> data;

        if(value == 0)
        {
            insertAtTail(zeroTai, curr);
        }
        else if(value == 1){
            insertAtTail(oneTail, curr);
        }
        else if(value == 2)
        {
            insertAtTail(twoTai, curr);
        }
    }

    // merge this newly created linked list

    // zero list non empty
    if(oneHead -> next != NULL)
    {
        zeroTail -> next = oneHead -> next;
    }
    else{
        // zero list empty
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    // setup head
    head = zeorHead -> next;

    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;


}
int main()
{


    return 0;
}
