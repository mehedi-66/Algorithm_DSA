/*
    **************** Merge Sort in Linked List ***************

    1) list divided into two parts ==> up to all are single elements
    2) one single element consider as sorted
    3) merge them and
    4) finally we get merge elements

    Data will Not change only Link will change

    TC => O( n log n)

    Approach 1:
        find mid element

                  mid
       [] -> [] -> [] -> [] -> [] ->[]

       [] -> [] -> []     [] ->  [] -> []
     left                right

*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d)
        {
            this -> data = d;
            this -> next = NULL;
        }
};

void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}
void insertAtTail(Node* &head, Node* &tail, int d)
{
    Node* temp = new Node(d);

    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return ;
    }
    else{
        tail -> next = temp;
        tail = temp;

        return ;
    }
}

Node* findMid(Node* head)
{
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

Node* Merge(Node* left , Node* right)
{
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    // merge 2 sorted linked list
    while(left != NULL && right != NULL)
    {
        if(left -> data < right -> data)
        {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while(left != NULL)
    {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while(right != NULL)
    {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    ans = ans -> next;

    return ans;

}

Node* mergeSort(Node* head)
{
    // base case
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    // break linked list into 2 half
    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;

    // recursive calls to sort both half
    left = mergeSort(left);
    right = mergeSort(right);

    // merger both left and right half
    Node* result = Merge(left, right);

    return result;


}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 5);

    head = mergeSort(head);

    print(head);

    return 0;
}
