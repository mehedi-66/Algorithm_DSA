
/*
    Bipartite Graph DFS

*/

#include<bits/stdc++.h>
using namespace std;

bool bipartiteDfs(int node, vector<int> adj[], vector<int> &color)
{
    if(color[node] == -1)
    {
        color[node] = 1;
    }

    for(auto it : adj[node])
    {
        if(color[it] == -1)
        {
            color[it] = 1 - color[node];
            if( !bipartiteDfs(it, adj, color)){
                // return DFS call back => if any two node same color then entire graph is NOT Bipartite
                return false;
            }
        }
        else if(color[it] == color[node]){
            // adj ... same color DFS call return here ..
            return false;
        }
    }

    // Bipartite Graph ...
    return true;
}

bool  checkBipartite(vector< int > adj[], int n)
{
    vector< int > color(n+1);
    for(int i = 1; i <= n; i++) color[i] = -1;

    // multiple components
    for(int i = 1; i <= n; i++)
    {
        if(color[i] == -1)
        {
            if( !bipartiteDfs(i, adj, color))
            {
                // entire graph is not bipartite
                return false;
            }
        }
    }

    // Bipartite Graph ...
    return true;
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

    if(checkBipartite(adj, n))
    {
        cout << "YES Bipartite" << endl;
    }
    else{
        cout << "Not Bipartite" << endl;
    }

    return 0;
}
