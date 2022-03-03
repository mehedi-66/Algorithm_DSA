/*
    Articulation Point

    Time Complicity : O(N + E)
    Space Complicity: O(N)


    => If I remove the Articulation point then the graph is divided two or more component

    => low[it] >= tin[node] && parent != -1

    => IN case of first node .. indivisual child is more then 1 then fist node also consider as articulation point

 */
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;

    for(auto it : adj[node])
    {
        if(it == parent){
            continue;
        }

        if(vis[it] == 0)
        {
            dfs(it, node, vis, tin, low, timer, adj, isArticulation);

            low[node] = min(low[node], low[it]);

            if(low[it] >= tin[node] && parent != -1)
            {
                isArticulation[node] = 1;
            }

            child++;

        }
        else{
            low[node] = min(low[node], tin[it]);
        }
    }
    // first node may be articulation piont
    if(child > 1 && parent == -1){
        isArticulation[node] = 1;
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
    vector<int> low(n, -1);
    vector<int> vis(n, 0);
    vector<int> isArticulation(n, 0);

    int timer = 0;
    for(int i = 0; i < n; i++)
    {
        if( vis[i] == 0)
        {
            dfs(i, -1, vis, tin, low, timer, adj, isArticulation);
        }
    }

    // print
    for(int i = 0; i < n; i++)
    {
        if(isArticulation[i] == 1){
            cout << i << endl;
        }
    }


    return 0;
}
