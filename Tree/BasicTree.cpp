
// ************* Introduction of Tree ********

/*
    Trees are a hierarchical data structure in computer science where the data is structured in a parent / child relationship
    example: computer folder

    1) root
    2) children
    3) leaf node
    4) sub tree .. if you stay any node the entire portion
    5)  Ancestus => if any node upper nodes ancestus


    Full Binary Tree => either has 0 or 2 children

    Complete BT => 1) all levels are completely filled except
                    the last level
                 2) the last level has all nodes as left as possible

    Perfect BT => all leaf nodes are at same level
                   (means full complete)

    Balanced BT => hight of tree at max log(N) nodes

    Degenerate Tree => squeed tree (left or right )



    ******************* Tree Representation in C++ *****************
    left | data | right

    struct node{
        struct node *left;
        int data;
        struct node *right;

    }

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

int main()
{
    struct Node *root = new Node(1);

    /*
        1
      /  \
     2    3
      \
       5
    */

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);
}
