/*
    Diameter of Binary Tree (width)

    Time => O(n^2)
    => longest path of two end

        diameter
        |  |  |
        L  R  (L+R)

    op1 = diameter(root->left)
    op2 = diameter(root->right)
    op3 = height(root->left) + 1 + height(root->right)

    int ans = max( op1, max(op2, op3));

    return ans;


************ Optimize the Answer


*/
#include<bits/stdc++.h>
using namespace std;

// find height
int height(Node* root)
{
    // base case
    if(root == NULL)
    {
        return 0;
    }
    // way
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}
int diameter(Node* root)
{
    // base case
    if(root == NULL)
    {
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1; // in case path not add +1 but in case number of nodes add +1

    int ans = max(op1, max(op2, op3));

    return ans;
}


// Time O(n)
/*
    pair<int, int>   => pair< diameter, height>
*/
pair<int, int> diameterFast(Node* root)
{
    // base case
    if(root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    // call for find diameter

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    // option diameter
    int op1 = left.first;
    int op2 = right.first;

    // option height
    int op3 = left.second + right.second + 1;

    // diameter
    pair<int, int > ans;

    ans.first = max(op1, max(op2, op3));

    // height
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node* root)
{
    return diameterFaset(root).first;
}

int main()
{


    return 0;
}
