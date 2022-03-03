/*
    Kruskal's Algorithm To find Minimum Spanning Tree
    time complexity: O(m log m)
    space complexity: O(n)

    1) Take weighted sorted array
    2) Check the two node is same component or not
    3) different component then add on the minimum spanning tree


    4 5
    0 1 1
    0 2 1
    1 3 1
    1 2 3
    2 3 2
    MST cost => 3
    0 - 1
    0 - 2
    1 - 3
*/
#include<bits/stdc++.h>
using namespace std;

struct node{

    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findParent(int u, vector<int> &parent)
{
    if(u == parent[u])
    {
        return u;
    }
    return findParent(parent[u], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &Rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if(Rank[u] < Rank[v])
    {
        parent[u] = v;
    }
    else if(Rank[v] < Rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        Rank[u]++;
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    // structure type node
    vector<node> edges;
    for(int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    // sorted array based on weight
    sort(edges.begin(), edges.end(), comp);

    // parent array pointed itself as parent
    vector<int> parent(n+1);
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    vector<int> Rank(n+1, 0);


    int cost = 0;
    vector< pair<int, int> > mst;
    for(auto it : edges)
    {
        if(findParent(it.v, parent) != findParent(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            Union(it.u, it.v, parent, Rank);
        }
    }


    // print the Minimum Spanning tree
    cout << "MST cost => " << cost << endl;
    for(auto it : mst){
        cout << it.first << " - " << it.second << endl;
    }



    return 0;
}
