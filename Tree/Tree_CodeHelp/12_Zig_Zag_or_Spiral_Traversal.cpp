/*
    ************* Zig Zag Traversal or Spiral Traversal ****************

    level order traversal
    1L ==> L --> R
    2L ==> R --> L
    3L ==> L --> R
    4L ==> R --> L

    Approach :

*/

#include<bits/stdc++.h>
using namespace std;
vector<int> zigZagTraversla(Node* root)
{
    vector<int> result;
    if(root == NULL)
    {
        return result;
    }

    // first node
    queue<Node*> q;
    q.push(root);

    bool flagLeftToRight = true;

    // level order traversal
    while(!q.empty())
    {
        int size = q.size(); // level size
        vector<int> ans(size);
         // process level
         for(int i = 0; i < size; i++)
         {
             Node* frontNode = q.front();
             q.pop();

            // normal order or reverse order
             int index = flagLeftToRight ? i : size - i - 1;
             ans[index] = frontNode -> data;

             if(frontNode -> left)
             {
                 q.push(frontNode->left);
             }
             if(frontNode -> right)
             {
                 q.push(frontNode->right);
             }

         }

        // direction change
        flagLeftToRight = !flagLeftToRight;

         // ans store into resul
         for(auto i : ans)
         {
             result.push_back(i);
         }
    }
}

int main()
{


    return 0;
}
