/*
    ********* Left View of Binary Tree **************


                        1
                      /   \
                    2       4
          see     /  \     /  \
                 3    5   7    8
                       \        \
                        9        11
                                   \
                                    10

                 [1, 2, 3, 9, 10]

                 level wise see first


        Approach:
            when we traverse node ==> each level first node is the left view

            Level order || recursion way

        each level first node ???
             level track we have keep then ==> suppose call left or right increase level by 1 right??

*/
void solve(Node* root, vector<int> &ans, int level)
{
    // base case
    if(root == NULL)
    {
        return ;
    }

    // we entered into a new level
    if(level == ans.size())
        ans.push_back(root->data);

    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(Node* root)
{
    vector<int> ans;
    solve(root, ans, 0);

    return ans;
}
