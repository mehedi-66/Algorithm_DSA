
/*
     Topological sort Directed Graph DAG( directed acyclic graph)

     inside the cycle graph not possible Topological graph and undirected ****

     linear ordering of verties such that
     if there is an edge u->v, u appaires
     before v is that ordering ....

     6 6
     5 0
     4 0
     5 2
     2 3
     3 1
     4 1

     output: 5 4 2 3 1 0

     edge => 4 0

     but output 4 is appeiring 0

*/

#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;

    for(auto it : adj[node])
    {
        if(vis[it] == 0)
        {
            findTopoSort(it, vis, st, adj);
        }
    }

    st.push(node);
}

vector<int> topoSort(vector<int> adj[], int n)
{
    stack<int> st;
    vector<int> vis(n, 0);

    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 0)
        {
            findTopoSort(i, vis, st, adj);
        }
    }

    // pop out the stack value one by one and push into a vector
    vector<int> topo;

    while( !st.empty() )
    {
        topo.push_back(st.top());
        st.pop();
    }

    // return the topological sorted value
    return topo;
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

    vector<int> v;

    v = topoSort(adj, n);

    // print the topological sort
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
