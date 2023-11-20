
/*
    ****************** build Tree From InOrder and PostOrder Traversal ********************

    => Input InOrder and PostOrder

        InOrder    =>   [4, 8, 2, 5, 1, 6, 3, 7]
        PostOrder  =>   [8, 4, 5, 2, 6, 7, 3, 1]

        InOrder => LNR => left root right
        postOrder => LRN => left right root

        That means => postOrder Last node is the Root node always


                index start from last element or postOrder


                                1
                             /    \
                        [4,8,2,5]  [6,3,7]      => InOrder
                        [8,4,5,2]  [6,7,3]     => postOrder


                        2
                    /      \
                [4,8]      [5]   => InOrder
                [8,4]      [5]   => postOrder


                4
               / \
                 [8]    => Inorder
                 [8]    => postOrder




      Full Binary Tree:
                        1
                     /    \
                    2      3
                   / \    / \
                  4   5   6  7
                   \
                    8






    code focus => index start from last and decrease by 1
                and Right part or InOrder solve fast and the left part






*/

#include<bits/stdc++.h>
using namespace std;

int findPosition(int in[], int element, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n)
{
    if(inde < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = post[index--];  // after taking root index decrease
    Node* root = new Node(element);         // create root

    int position = findPosition(in, element, n);  // find position

    // recursive call Focus Right call first Happened

    root -> right = solve(in, post, index, position+1, inorderEnd);

    root->left = solve(in, post, index, inorderStart, position-1);



    return root;
}

Node* buildTree(int in[], int post[], int n)
{
    // n here is InOrder length

    int preOrderIndex = n-1;
    Node* ans = solve(in, post, preOrderIndex, 0, n-1, n);

    return ans;

}
int main()
{



    return 0;
}
