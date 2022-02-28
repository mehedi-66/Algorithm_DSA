
/*
        Undirected Graph

    1) By traverse time if a node is previously visited
    2) And the visited node is not the parent node then
    3) this sign for cycle of that graph

*/

#include<bits/stdc++.h>
using namespace std;


bool checkForCycle(int s, int n, vector< int > adj[], vector< int > &visited)
{
    // create q queue for BFS

    queue< pair< int, int >> q;

    visited[s] = 1;
    q.push({s, -1});

    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it : adj[node])
        {
            if(visited[it] == 0)
            {
                q.push({it, node});
                visited[it] = 1;
            }
            else if(parent != it)
            {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int n, vector< int > adj[])
{
    vector< int > vis(n+1, 0);

    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            if(checkForCycle(i, n, adj, vis) == 1){
                return true;
            }
        }
    }

    return false;
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

    cout << "isCycle : " << isCycle(n, adj);

    return 0;
}
