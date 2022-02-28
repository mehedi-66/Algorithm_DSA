/*
     Directed Graph Cycle detection
    1) vis[] = {0}
    2) dfsVis[] = {0}
    3) if one going a node if visited
    4) and dfsvis == 1 then their is a cycle
 */

#include<bits/stdc++.h>
using namespace std;
bool checkCycle(int node, vector<int>adj[], vector<int> &vis, vector<int> &dfsVis)
{
    vis[node] = 1;
    dfsVis[node] = 1;
    for(auto it : adj[node])
    {
        if(vis[it] == 0)
        {
            if(checkCycle(it, adj, vis, dfsVis))
            {
                return true;
            }

        }
        else if(dfsVis[it])
        {
            return true;
        }

    }

    dfsVis[node] = 0;
    return false;
}

bool isCycle(vector<int> adj[], int n)
{
    vector<int> vis(n+1), dfsVis(n+1);
    for(int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        dfsVis[i] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            if(checkCycle(i, adj, vis, dfsVis))
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

    }


    if(isCycle(adj, n))
    {
        cout << "Yes Cycle " << endl;
    }
    else
    {
        cout << "Not Cycle " << endl;
    }
    return 0;
}
