/*
    ************ Bottom View of Binary Tree *************

                        1
                      /   \
                     2     4
                   /  \   /  \
                  3   5   6   7

                     ----
                      \/

                [3, 2, 6, 4, 7]   ans

                hd elemetn last one is store after word need

                every <0> ---> 1, 5, 6
                      <-1> ---> 2
                      <1> ---> 4
                      <-2> --> 3
                      <2> --> 7

                      last one ans
                      [3, 2, 6, 4, 7]



*/

vector<int>  BottomView(Node* root)
{
    vector<int> ans;
    if(root == NULL)
    {
        return ans;
    }
    map<int, int> topNode;  //<hd, data>

    queue<pair<Node*, int> >  q; // < node, hd>

    q.push(make_pair(root, 0));

    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

            topNode[hd] = frontNode -> data;

        if(frontNode->left)
            q.push(make_pair(frontNode->left, hd-1));
        if(frontNode->right)
            q.push(make_pair(frontNo de->right, hd+1));
    }

    for(auto i: topNode)
    {
         ans.push_back(i.second);
    }

    return ans;



}
