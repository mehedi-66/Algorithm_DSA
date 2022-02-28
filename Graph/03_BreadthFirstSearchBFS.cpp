
/*
            BFS

    1) visited array vis[] = {0}
    2) 1 to n => if(vis[i]) BFS(i)
    3) queue
    4) Traverse all => adj node
    5) make as visited


*/

#include<bits/stdc++.h>
using namespace std;

vector< int > bfsOfGraph(int n, vector< int > adj[])
{
    vector< int > bfs;
    vector< int > vis(n+1, 0); // visited array initialize with zero

    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            // declare queue
            queue< int > q;
            q.push(i); // node push into queue
            vis[i] = 1;

            while(!q.empty())
            {
                // take out top most queue element and visited adj list

              int node = q.front();
              q.pop();

              bfs.push_back(node); // visited node

              // visit all adj nodes ...

              for(auto it : adj[node])
              {
                 if(vis[it] == 0)
                 {
                     q.push(it);
                     vis[it] = 1;
                 }
              }

            }

        }
    }


    return bfs;
}



int main()
{
    int n, m;
    cin >> n >> m;

    vector< int > adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // get the traverse BFS arr
    vector< int > bfs;

    bfs = bfsOfGraph(n, adj);

    // print BFS
    for(int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
    }

    return 0;
}
