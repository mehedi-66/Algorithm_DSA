
/*
        Kosarajus's Algorithm for Strongly Connected Components SCC

        Time complicity => O (N + E)
        Space complicity => Transpose=>O(N+E) - node=>O(N) - stack=>O(N)

        Three steps =>
        1) sort all nodes in acording to finishing time
            => Topological Sort => Time =>  O(N)
        2) Transpose the Graph => Time => O(N+E)

        3) DFS call according to finishing time => Time=> O(N + E)
 */
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(vis[it] == 0)
        {
            dfs(it, st, vis, adj);
        }
    }
    st.push(node);
}

void revDfs(int node, vector<int> &vis, vector<int> transpose[])
{
    cout << node << " ";
    vis[node] = 1;
    for(auto it : transpose[node])
    {
        if(vis[it] == 0)
        {
            revDfs(it, vis, transpose);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Step 01 => Topological sort
    stack<int> st;
    vector<int> vis(n, 0);
    for(int i=0; i<n; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i, st, vis, adj);
        }
    }

    // Step 02 => Transpose
    vector<int> transpose[n];

    for(int i=0; i<n; i++)
    {
        // remark visited array with zero
        vis[i] = 0;
        for(auto it : adj[i])
        {
            // previously i_Node to it_Node but now
            transpose[it].push_back(i);
        }
    }


    // step 03 => go on the nodes DFS by its finishing time
    while( !st.empty() )
    {
        int node = st.top();
        st.pop()

        if(vis[node] == 0)
        {
            cout << "SCC: ";
            revDfs(node, vis, transpose);
            cout << endl;
        }
    }



    return 0;
}
