/*

    ############ Connected Components ###############

    the main idea is that the node maybe single and together
    in single or group

    always ... run a loop for => 1 to n numbers of node ...

    and keep a visited array  all are initialize with zero ....


    for(int i = 1; i <= n; i++)
    {
        if( vis[i] == 0)
        {
            DFS or BFS call inside here ...
        }
    }


 */

#include<bits/stdc++.h>
using namespace std;
int main()
{


    // for call connected component ...
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            DFS() or BFS()
        }
    }

    return 0;
}
