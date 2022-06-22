/*
    ******************** Detect and Remove Loop in Linked List *****************

    --> Detect Cycle in Linked List
    --> Remove Cycle in Linked List
    --> Beginning / start node of loop in LL

    Approach :

        map< Node * , bool >

        if a Particular Node visited or not previously


    Approach:

        Floyd's Cycle detection Algorithm

        ---> In head <== slow and fast point
        ---> slow increment by 1 step and fast increment by 2 step
        ---> if they are meet any point
        ---> then their is a cycle
        ---> others wise no cycle



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

bool detectLoop(Node * head)
{
    if(head == NULL)
    {
        return false;
    }

    map< Node* , bool > visited;

    Node * temp = head;

    while(temp != NULL)
    {
        // cycle is present
        if(visited[temp] == true)
        {
            return 1;
        }
        // not visited
        visited[temp] = true;

        temp = temp -> next;
    }

    // not find any cycle
    return 0;
}

// floyd's Detection  Algorithm

Node * floydDetectLoop(Node * head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node * slow = head;
    Node * fast = head;

    while(slow != NULL && fast != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast)
        {
            // if meeting point found
            return slow;
        }
    }

    return NULL;
}

Node * getStartingNode(Node * head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node * intersection = floydDetectLoop(head);
    Node * slow = head;

    while(slow != intersection)
    {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
}


// Remove loop
void removeLoop(Node * head)
{
    if(head == NULL)
    {
        return ;
    }

    Node * startOfLoop = getStartingNode(head);

    Node * temp = startOfLoop;
    // temp next not meeting in the start Node runing
    while(temp -> next == startOfLoop)
    {
        temp = temp -> next;
    }

    temp -> next = NULL;
}


int main()
{
    Node * head = new Node(10);
    Node * tail = head;

    InsertAtLast(tail, 20);
    InsertAtLast(tail, 30);
    InsertAtLast(tail, 40);
    InsertAtLast(tail, 60);

    // print(head);
    tail -> next = head;

    cout << detectLoop(head) << endl;
    cout << floydDetectLoop(head) -> data << endl;

    Node * loop = getStartingNode(head);

    cout << loop -> data << endl;

    // remove Loop
    removeLoop(head);

    print(head);

    return 0;
}
