/*
    *************** Link List *************
    What is Link List?

    Linear Data Structure
        - collection of Nodes
        - Node is [data, nextNodeAddres]

    [ 3| *] --> [ 5 | *] --> [ 9| *] --> NULL


    Why need Link list ??
        - After run the pro we can not change the size of  array
        - in Case of Link List size can be change
        - Dynamic data structure
        - Node are created inside the Heap Memory

    Type of Link List
        - Singly  LL
        - Doubly LL
        - Circular LL
        - Circular Doubly LL


     Example of Node :

     class LinkListNode{
        public:
            int data;
            LinkListNode * next;
     }





*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node * next;


    // constructor to initialize the Node
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};


int main()
{
    // create object of the Node with value
    Node * node1 = new Node(10);

    cout << node1 -> data << endl; // 10
    cout << node1 -> next << endl; // 0

    return 0;
}
