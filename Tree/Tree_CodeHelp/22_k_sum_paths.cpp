/*
    *************** K sum paths *********************
    Find the paths ==> where sum of the path equals to ==> K


    Approach 1:
            Find all the then check ==> if any path sum is equal to K then count ++



*/

void solve(Node* root, int k, int &count, vector<int> path)
{
    // base case
    if(root == NULL)
    {
        return ;
    }

    path.push_back(root->data);

    // left
    solve(root->left, k, count, path);
    // right
    solve(root->right, k, count, path);

    // check for K sum present or not
    int sum = 0;
    for(int i = path.size()-1; i >= 0; i--)
    {
        sum += path[i];
        if(sum == k)
        {
            cnt++;
        }
    }

    // remove element from back time
    path.pop_back();
}


int sum(Node* root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);

    return count;
}
