/*
    ******************* Lowest Common Ancestor in a Binary Tree ****************

    LCA ==> tree

     n1 and n2 ==> nodes we have to find out lowest common ancestor of that nodes


                                            5
                                          /   \
                                        4      3
                                      /  \     / \
                                     7    8   22  27
                                         / \       /
                                        12  9     29

                                n1 = 8
                                n2 = 27

                                given node to up like n1 = 8-->4-->5
                                                     n2 = 27-->3-->5

                                                     in both case 5 is common and lowest ancestor




                                 Another Example:
                                        5
                                       /
                                      2
                                     / \
                                    3   4
                                   n1    n2

                                   2 is the lowest common ancestor







        Approach:
                            1
                          /   \
                         2     3
                       /      /  \
                      6      4    5
                       \     n2   /
                        8        21
                                 n1



            path find root to n1 and n2
            n1 path ==> 1, 3, 5, 21
            n2 path ==> 1, 3, 4

                          3 <==== back to front common is 3

        Approach2:

            left and right call ==> 1) left == null and right == null ==> return null
                                    2) left or right not null then return that not null value
                                    3) if both not null then return root that is common ancestor

        Time: O(n)
        Space: O(n) --> skew tree other height
*/
#include<bits/stdc++.h>
using namespace std;


Node * LCA(Node* root, int n1, int n2)
{
    if(root == NLL)
    {
        return NULL;
    }

    if(root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node* leftAns = LCA(root->left, n1, n2);
    Node* rightAns = LCA(root->right, n1, n2);

    if(leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else{
        return NULL;
    }
}
int main()
{


    return 0;
}
