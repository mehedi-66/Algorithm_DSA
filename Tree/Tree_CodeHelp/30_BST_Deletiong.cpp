/*
   ************************* BST Deletion Traversal *******************



                    avg             Skew
            Insertion  =>   O(h)            O(n)
            Search     =>   O(h)            O(n)
            Deletion  =>


            BST => InOrder Traversal is Sorted Order


            BST minimum value present in the Left most position

                            4
                          /   \
                         2     5
                        / \
                       1   3

            Minimum:

                Node* temp = root

                while(temp ->left != NULL)
                {
                    temp = temp->left;
                }

                return temp;

        Maximum:

                Node* temp = root;

                while(temp ->right != NULL)
                {
                    temp = temp->right;
                }

                return temp;


        Home work:  InOrder Precessor
                    InOrder Succesor

                    InOrder Traversal of BST => 2 3 4 5 6
                                        4 => 3 is pre
                                          => 5 is succ

    How to work on code by InOrder Traversal => stop previously in case precessor
                                                stop after word in case succeooor



                                    100
                                 /       \
                               50        110
                              /  \          \
                             25  70          120
                                /             /
                              60            115


                    we want to delete:  120

        Approach:

            Reach to that node first

            code:

                if(root->data == x)
                {
                    ...
                    ..
                }
                else if(root->data > x)
                {
                    left part go
                }
                else
                {
                    right part gos
                }


        the are 4 case of deletion a Node

           1)  0 child  => simple set null return (60)
           2)  1 child => left or right child present: lets 120 delete and up set node 115

               left child case:             right child case:

                temp = root->left;           temp = root->right;
                    delete root;                delete root;
                return temp;                 return temp;




           3)  2 children
                        let say we want to delete 50

                            then we have flow tricks => 50's replace by left part max value 25 => then delete 25 by recursively from left part

                                                OR  => 50's replace by right part Min value  60 ==> then delete 60 from right part recursively









*/

#include<bits/stdc++.h>
using namespace std;

// BST minimum value Node find out
int minVal(Node* root)
{
    Node* temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val)
{
    // base case
    if(root == NULL)
    {
        return root;
    }

    if(root->data == val)
    {
        // 0 child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child

            // left child
            if(root->left != NULL && root->right == NULL)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // right child
            if(root->left == NULL && root->right != NULL)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }


        // 2 child
        if(root->left != NULL && root->right != NULL)
        {
            int minVal = minVal(root->right)->data; // minimum value find out from right subtree

            root->data = minVal;  // replace with that value

            root->right = deleteFromBST(root->right, minVal); // recursive call for removing the value from right part or subTree

            return root;
        }


    }
    else if(root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
    }
    else
    {

        root->right = deleteFromBST(root->right, val);
    }

    return root;
}
int main()
{



    return 0;
}
