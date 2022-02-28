
/*
    Shortest Path Undirected Graph

    src => target

    store min distance inside the distance array

    1) take distance array
    2) put in infinity
    3) initial take zero go
    4) go adj nodes add weight (1) if the added distance smaller then previous then take it in distance array ...


    4 6
    0 1
    0 2
    1 2
    1 3
    2 3
    2 4

    0 1 1 2 2

*/

#include<bits/stdc++.h>
using namespace std;

void shortestPathBFS(vector<int> adj[], int n, int src)
{
    int dist[n+1];
    for(int i = 0; i <= n; i++) dist[i] = INT_MAX;

    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it : adj[node])
        {

            if(dist[node]+1 < dist[it])
            {
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }

    // print the distance array ....

    for(int i = 0; i <= n; i++){
        cout << dist[i] << " ";
    }
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

    shortestPathBFS(adj,  n, 0);

    return 0;
}
