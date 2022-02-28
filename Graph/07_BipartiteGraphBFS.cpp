/*
        Bipartite Graph BFS

        that can be colored using 2 colors such that
        no two adjacent nodes have same color...

        like : blue and green ... divided two color graph .. function (doman and range)



    *** Always possible two color => is the graph has no cycle

    *** Cycle length
    1) even => possible  two color graph
    2) odd  => not possible two color graph


    Bipartite Graph => even length cycle and without cycle

    approach

    1) take color array  color[] and initialize with => -1
    2) queue
    3) making color one by one and oposite color as well
    4) if a node is already visited then check it is opositie or nor??
*/

#include<bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int s, vector< int > adj[], vector< int > &color)
{

    queue< int > q;
    q.push(s);
    color[s] = 1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it : adj[node])
        {
            if(color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if(color[it] == color[node]){
                // adj two nodes have some color not Bipartite graph
                return false;
            }
        }
    }

    // the components is Bipartite
    return true;
}
bool checkBipartite(vector< int > adj[], int n)
{
    vector< int > color(n+1);
    for(int i=1;  i<=n; i++) color[i] = -1;

    for(int i = 1; i <= n; i++)
    {
        if(color[i] == -1)
        {
            // if any node is not bipartite then entire graph is not Bipartite
            if(!bipartiteBfs(i, adj, color))
            {
                return false;
            }
        }
    }

    // Bipartite Graph return true
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
