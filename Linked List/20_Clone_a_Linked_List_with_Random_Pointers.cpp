/*
    ******************** Clone a Linked List with Random Pointer ***************
    Node{
        int data;
        Node* next;
        Node* random;
    }

    [2| * #] one Node
        1) point to next node
        2) and randomly point to another Node

    we have to clone this Node

    Approach 1:
        ** create a clone list (using original list next pointer)
        **  find the original list ==> random pointer how may distance it point

        for(){
                for()
        }

        Time complexity : O(n^2)

    Approach 2:
        ** create a clone list (using original list next pointer)
        ** Mapping with ===> original to clone node

            a b c
            | | |
            x y z

        ** cloneNode -> random = mapping[ originalNode -> random ]

        TC => O(n)
        SC => O(n) map used

    Approach 3:
        [a] [b] [c]
         | /  | / | /
        [x]  [y] [z]

        1) create a clone Link
        2) CloneNode add in between original Linked List
        3) copy random pointer

            temp -> next -> random =  temp -> random -> next;

         4) revert change done in step 2
*/
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* random;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int d)
{
    Node* newNode = new Node(d);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return ;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

Node* copyList(Node* head)
{
    // step 1: create a clone List
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp -> next;
    }

    // step 2: create a map
    unordered_map< Node*, Node*> oldToNewNode;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL)
    {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }


    // step 3: set random pointer
    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL)
    {
        cloneNode ->   = oldToNewNode[originalNode -> random];
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }

    return cloneHead;
}

// Better approach TC => O(n) and SC => O(1)

Node* copyList(Node* head)
{
    // step 1: create a clone List
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while(temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp -> data)

        temp = temp -> next;
    }

    // step 2: cloneNode add in between Original List
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL)
    {
        Node* next = originalNode -> next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode = next;
    }

    // step 3: random pointer copy

    temp = head;

    while(temp != NULL)
    {
        if(temp -> next != NULL)
        {
            if(temp->random != NULL)
            {

                temp -> next -> random = temp -> random -> next;
            }
            else
            {
                temp ->next = temp -> random;
            }
        }

         temp = temp -> next -> next;
    }

    // step 4: revert changes done in step 2

    originalNode = head;
    cloneNode = cloneHead;

     while(originalNode != NULL && cloneNode != NULL)
     {
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;

        if(originaNode != NULL)
            cloneNode -> next = originalNode -> next;

        cloneNode = cloneNode -> next;
     }

    // step 5: return ans;

    return cloneHead;
}


int main()
{


    return 0;
}
