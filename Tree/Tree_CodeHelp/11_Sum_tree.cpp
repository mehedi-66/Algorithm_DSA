/*
    ***************** Sum Tree ***********
    in a particular Node

        x
       / \
      L   R

      x = L + R

      if Any Node ==> left subtree + right subtree

        all follow the condition then return true


*/

#includec<bits/stdc++.h>
using namespace std;

// pair< isOk, sum>

pair<int, int> isSumTreeFast(Node* root)
{
    //base case
    if(root == NULL)
    {
        pair<int, int> p = make_pair<true, 0>;
        return p;
    }
    if(root->left == NULL && root -> right == NULL)
    {
        // leaf node case
        pair<int, int> p = make_pair(true, root->data);
        return p;
    }

    pair<int, int> leftAns = isSumTreeFast(root->left);
    pair<int, int> rightAns = isSumTreeFast(root->right);

    // standing into a particular node
    // 3 things have to check ... left , right, and x = l + r

    bool left = leftAns.first;
    bool right = leftAns.first;

    // x == l + r
    bool condition = (root -> data  == (leftAns.second + rightAns.second));

    pair<int, int> ans;

    if(left && right && condition)
    {
        ans.first = true;
        //ans.second = root->data + leftAns.second + rightAns.seocnd;
        ans.second = 2* root->data;
    }
    else{
        ans.frist = false;
    }
    return ans;
}
int main()
{


    return 0;
}
