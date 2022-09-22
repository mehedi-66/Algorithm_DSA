/*
    ************* Top View Of Binary Tree ****************
                        /\
                        ..

                  -2  -1  0  1  2

                        1
                      /   \
                    2       3
                  /  \     /  \
                 4   5    6    7


                 [4, 2, 1, 3, 7]


        Approach:
                vertical Travers idea need here

                <0> ---> 1,  hide all rest of the
                <-1> --> 2
                <1> ---> 3
                <-2> ---> 4

                map<int, int> mp;
                    HD, data

              logic ==> level order traversal ===> and if any node map with horizontal mapping rest of the node hide auto by top see




*/
#include<bits/stdc++>
using namespace std;
vector<int>  topView(Node* root)
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

        // maintain one to mapping if one value is present for a HD, then do nothing
        if(topNode.find(hd) == topNode.end())
        {
            // if any HD courspondig  value not present then ... store first value
            topNode[hd] = frontNode -> data;
        }
        // level order traversal left to right
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
int main()
{

    return 0;
}
