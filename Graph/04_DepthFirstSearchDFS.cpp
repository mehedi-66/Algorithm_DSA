/*

    1) take visited array
    2) 1 to n  node travaras
    3) stack by default using reaction call
    4) visit adj list .... one by one

*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector< int > &vis, vector< int > adj[], vector< int > &dfsStore)
{
    dfsStore.push_back(node);
    vis[node] = 1;

    for(auto it : adj[node])
    {
        if(vis[it] == 0)
        {
            dfs(it, vis, adj, dfsStore);
        }
    }
}


vector< int > dfsOfGraph(int n, vector< int > adj[])
{
    vector< int > dfsStore;
    vector< int > vis(n+1, 0);

    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i, vis, adj, dfsStore);
        }
    }

    return dfsStore;
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

    vector< int > dfs;

    dfs = dfsOfGraph(n, adj);

    for(int i = 0; i<dfs.size(); i++)
    {
        cout << dfs[i] << " ";
    }


    return 0;
}
