/*
    Bridge in Graph

   => cut edge give two or more component in graph

  => tin insertion time
  => tlow the backTracking time for low adj[]
*/
#include<bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &tlow, int &timer, vector<int> adj[])
{

    vis[node] = 1;
    tin[node] = tlow[node] = timer++;

    for(auto it : adj[node])
    {
        if(it == parent){
            continue;
        }

        if(vis[it] == 0)
        {
            dfs(it, node, vis, tin, tlow, timer, adj);
            tlow[node] = min(tlow[node], tlow[it]);

            if(tlow[it] > tin[node])
            {
                cout << node << " " << it << endl;
            }
            else{
                tlow[node] = min(tlow[node], tin[it]);
            }
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n, -1);
    vector<int> tlow(n, -1);
    vector<int> vis(n, 0);

    int timer = 0;
    for(int i = 0; i < n; i++)
    {
        if( vis[i] == 0  )
        {
            dfs(i, -1, vis, tin, tlow, timer, adj);
        }
    }

    return 0;
}
