
/*
    Topological sort DAG ( directed acyclic graph)

    1) for each node => indegree needed => we can use array for storing
    2) queue data structure
    3) which indegree zero push into stack =>
    4) run BFS on that node ...
    5) and the reduce degree by 1 for adj node =>
    6) and check adj nodes in degree zero or not??

    input:

    6 6
    5 0
    4 0
    5 2
    2 3
    3 1
    4 1
output: 4 5 0 2 3 1
 */
#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<int> adj[], int n)
{
    queue<int> q;
    vector<int> indegree(n, 0);

    // count in degree
    for(int i = 0; i < n; i++)
    {
        // if i th node u -> v ... u th adj list
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    // push into queue which indegree is zero
    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector< int> topo;
    // bfs call on the queue elements
    while( !q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    // return a topological sorted elements
    return topo;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<int> topo;

    topo = topoSort(adj, n);

    for(int i = 0; i < topo.size(); i++)
    {
        cout << topo[i] << " ";
    }


    return 0;
}
