/*
    ******************* build Tree from => InOrder and PreOrder Traversal *********************

    Input:
        InOrder  => [1, 6, 8, 7]
        PreOrder => [1, 6, 7, 8]

        InOrder => LNR => Left  Root  Right

        PreOrder => NLR => Root  Left  Right

        Step 1:  start from preOrder left most element as index
        Step 2:  find index element inside the InOder traversal called as Position
        Step 3:  divided left and right part on InOder and call recursion

                Left part Range [ startInOrder, pos -1]
                Right part Range [pos + 1, endInOrder]


      Now see

        index = 0;   preOrder as root element
                        1
                     /    \
    InOrder       []     [6, 8, 7]

    PreOrder     []      [6, 7, 8]



                            6
                         /    \
                        []    [8, 7]      InOrder
                        []    [7, 8]      PreOrder


                                7
                             /    \
                            [8]   []     InOrder
                            [8]    []    PreOrder


                                 8
                                / \
                               []  []




        Final Tree:
                        1
                         \
                          6
                           \
                            7
                           /
                          8

    One More Example:
            InOrder   => [3, 1, 4, 0, 5, 2]
            PreOrder =>  [0, 1, 3, 4, 2, 5]



                        0
                       /  \
                      1    2
                    /  \   /
                   3   4  5


    Algorithm :

        => we start PreOrder index [left most] element consider as root element

        => Find root element position in InOrder Traversal

        => root-> left = solve( inorderStart, pos-1)
        => root-> right = solve( pos+1, inorderEnd)



    Optimize :
   In case find inOrder element position by Create  map

   map<element, position> mp;




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

Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
{
    if(inde >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = pre[index++];  // after taking root index increase
    Node* root = new Node(element);         // create root

    int position = findPosition(in, element, n);  // find position

    // recursive call
    root->left = solve(in, pre, index, inorderStart, position-1);

    root -> right = solve(in, pre, index, position+1, inorderEnd);

    return root;
}

Node* buildTree(int in[], int pre[], int n)
{
    // n here is InOrder length

    int preOrderIndex = 0;
    Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);

    return ans;

}
int main()
{



    return 0;
}
