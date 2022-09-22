/*
    **************** Right View of Binary Search Tree **************


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

    // right to left goes
    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);

}

vector<int> leftView(Node* root)
{
    vector<int> ans;
    solve(root, ans, 0);

    return ans;
}
