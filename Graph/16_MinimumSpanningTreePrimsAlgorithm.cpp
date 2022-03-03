
/*
        *** two solution *** O(n^2) as well O(nlogn)
        find key minimum using priority_queue

        Minimum Spanning Tree => by Prims Algorithm
        MST => Minimum Spanning Tree

        Key point:
       1) Minimum Spanning Tree is a tree there is not cycle
       2) make N nodes and N-1 edges => any nodes to reach to others node 0 to all

       Algorithm is Simple:
       1) Take a node and pick minimum weight/distance to go
       2) if more then 1  nodes are take then .. => check All nodes adj nodes and pick all of them Minimum to go (next one)
       3) if the Minimum weight/distance gives cycle then not take that one .. coz tree does not have cycle
       4) When N nodes are taken then stop ...
       5) this is the Minimum Spanning tree and sum off all edge gives the Minimum number weight sum

       For implement
       1) take key[], mst[], parent[] arrays
       2) start from initial 0/1
       2) find minimum in key array min distance pick if not mst true
       3) iterate adj nodes => update parent and key array nodes => with min distance  and parent nodes


    input:
    4 5
    0 1 1
    0 2 2
    1 2 3
    1 3 1
    2 3 2

    output:
    -1 0
    0 1
    0 2
    1 3

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector< pair<int, int> > adj[n];

    int u, v, wt;
    for(int i = 0; i < m; i++)
    {
        // 0 1
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // Prim's algorithm start here
    int parent[n];
    int key[n];
    bool mstSet[n];

    // array initialize
    for(int i=0; i<n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    // start node
    key[0] = 0;
    parent[0] = -1;

    // spanning tree N - 1 edges
    for(int cnt=0; cnt < n-1; cnt++)
    {
        int mini = INT_MAX, node;

        // find the minimum distance node to pick
        for(int i=0; i < n; i++)
        {
            // if the node not part of MST and distance is minimum
            if(mstSet[i] == false && key[i] < mini)
            {
                mini = key[i], node = i;
            }
        }


        // the node taken for MST
        mstSet[node] = true;

        for(auto it : adj[node])
        {
            int x = it.first;
            int weight = it.second;
            if(mstSet[x] == false && weight < key[x])
            {
                parent[x] = node;
                key[x] = weight;
            }
        }

    }

    for(int i = 0; i < n; i++)
    {
        cout << parent[i] << " " << i << endl;
    }

    return 0;
}




// **************** Find minimum using O(nlogn) priority queue **********
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector< pair<int, int> > adj[n];

    int u, v, wt;
    for(int i = 0; i < m; i++)
    {
        // 0 1
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // Prim's algorithm start here
    int parent[n];
    int key[n];
    bool mstSet[n];

    // array initialize
    for(int i=0; i<n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }

    // start node
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

    key[0] = 0;
    parent[0] = -1;
    // pq.push( dis, node);
    pq.push({0, 0});

    // spanning tree N - 1 edges
    for(int cnt=0; cnt < n-1; cnt++)
    {

        // find the minimum distance node to pick
       int node = pq.top().second;
        pq.pop();

        // the node taken for MST
        mstSet[node] = true;

        for(auto it : adj[node])
        {
            int x = it.first;
            int weight = it.second;
            if(mstSet[x] == false && weight < key[x])
            {
                parent[x] = node;
                key[x] = weight;
                pq.push({key[x], x});
            }
        }

    }

    for(int i = 0; i < n; i++)
    {
        cout << parent[i] << " " << i << endl;
    }

    return 0;
}

