
/*
    ****************** Vertical Traversal of Binary Tree ******************
    x axis               -2  -1  0  1 2 3

                         |  | | |  | | | |

                                1
                             /    \
                            2      3
                          /  \    /  \
                         4   5    6   7
                                   \   \
                                    8   9

                       4  2  1 5 6 3 8 7 9   example like this

            Level way store in maping :

                <0> --> 1, 5, 6
                <-1> --> 2
                <1> --> 3
                <-2> --> 4
                <2> --> 7
                <3> --> 9

            print sorted order then we see:
                <-2>  <-1> <0>  <1> <2> <3>

        mapping ==> Horizontally ==> store ==> level wise ( node mapping)

            map< Hd, map< level, nodes > >

            map< int, map< int, vector<int> > > nodes;

            require: hd, level

            --> queue< pair< Node*, pair< int, int> > >

*/

#include<bits/stdc++.h>
using namespace std;
vector<int> verticalOrder(Node* root)
{
    map<int, map< int, vector<int> > > nodes;
    queue< pair<Node*, pair<int, int> > q;
    vector<int> ans;

    if(root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty())
    {
        pair< Node*, pair< int, int> > temp = q.front();
        q.pop();

        Node * frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].insert(frontNode->data);

        // left node has
        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
        else
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
    }

    // ans get from  map
    // map< int, map< int, vector<int> > > nodes;  we want vector

        for(auto i: nodes)
        {
            for(auto j : i.second)
            {
                for(auto k: j.second)
                {
                    ans.push_back(k);
                }
            }
        }

        return ans;

}
int main()
{


    return 0;
}
