/*
    ************ Inorder Traversal **********

    Time Complexity:

    Space Complexity:


    ( left, Root, Right )
 */

 #include<bits/stdc++.h>
 using namespace std;

 void Inorder(struct Node node)
 {
     if(node == NULL)
     {
         return ;
     }

    Inorder(node->left);

    cout << node->data ;

    Inorder(node->right);

 }

 int main()
 {


     return 0;
 }
