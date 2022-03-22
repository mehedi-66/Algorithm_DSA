/*
    *************** Postorder Traversal ************


    (left, right, root)


*/
#include<bits/stdc++.h>
using namespace std;

void Postorder(struct Node node)
{
    if(node = NULL)
    {
        return ;
    }

    Postorder(node->left);

    Postorder(node->right);

    cout << node->data ;
}

int main()
{




    return 0;
}
