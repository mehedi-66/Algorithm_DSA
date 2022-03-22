/*
    *************** Preorder Traversal *************

    Time complexity => O(n) number of nodes of tree

    Space Complexity => O(n) => best case O(log n) but if it is left skew or right skew O(n)


    visited:
    ( root, left,  right )

*/

#include<bits/stdc++.h>
using namespace std;

void preorder(struct Node node)
{
    if(node == NULL)
    {
        return ;
    }


    cout << node->data ;

    preorder(node->left);

    preorder(node->right);
}

int main()
{

}
