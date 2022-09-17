/*
    Check For Balance Tree
    Time => O(n^2)

     [ height(left) - height(right) ] <= 1

    for all node


********* Optimize Answer
    Time => O(n)

    by removing the height() call extra

    pair< isBalanced, height >

    returning time send s


*/
#include<bits/stdc++.h>
using namespace std;

int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int left = height(root -> left);
    int right = height(root -> right);

    int ans = max(left, right) + 1;
    return ans;
}

bool isBalanced(Node* root)
{
    // base case
    if(root == NULL)
    {
        return true;
    }

    bool left = isBalanced(root -> left);
    bool right = isBalanced(root -> right);

    bool diff = abs( height(root->left) - height(root->right)) <= 1

    if(left && right && diff)
    {
        return true;
    }
    else{
        return false;
    }
}


// *********** Optimize
pair<int, int> isBalancedFast(Node* root)
{
    // base case
    if(root == NULL)
    {
        pair<int, int> p = make_pair(true, 0);  // initially isBalance true and height 0
        return p;
    }

    // call for left and right
    pair<int, int> left = isBalancedFast(root->left);
    pair<int, int> right = isBalancedFast(root->right);

    // get isBalanced value
    bool leftAns = left.first;
    bool rightAns = right.first;

    // get height

    bool diff = abs(left.second - right.second) <= 1;


    // answer
    pair<int, int> ans;
    // set height
    ans.second = max(left.second, right.second) + 1;

    if(leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    return ans;
}
bool isBalanced(Node* root)
{
    return isBalancedFast(root).first;
}
int main()
{


    return 0;
}
