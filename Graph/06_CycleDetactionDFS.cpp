
/*
        Undirected Graph

    1) if a node is visited and that node is not a parent node
        then their is a cycle ...

*/

#include<bits/stdc++.h>
using namespace std;


bool checkForCycle(int node, int parent, vector< int > &vis, vector< int > adj[])
{
    vis[node] = 1;

    for(auto it : adj[node])
    {
        if(vis[it] == 0)
        {
            if(checkForCycle(it, node, vis, adj) == 1){
                return true;
            }
        }
        else if( it != parent){
            return true;
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
            if(checkForCycle(i, -1, vis, adj) == 1)
            {
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

    cout << "isCycle : " << isCycle(n, adj) << endl;


    return 0;
}
