
/*
    1 2
    2 3

    group =>
    ( 1  2 )

    ( 1 2 3) parent of 2,3 is 1

    => findParent()
    => Union()

    Efficient Solution is
    union By Rank & path Compression

.......................
    1) Take a Rank array all are zero
    2) find rank and parent => 1 - 2 => parent=> Rank 0 0 =>
    3) when two rank is same then update rank by 1
    4) who ever smaller rank connected to bigger rank
    5) make a parent of the group by one node

    path Compression =>
    like 4 <- 6 <- 7 <- 8
    what is parent of 8 ?
    it is 4

    we can directly node point itSelf 4
    4<-6
    4<-7
    4<-8
    this a simple example of path compression


*/

#include<bits/stdc++.h>
using namespace std;
int parent[10000];
int Rank[10000];



void makeSet(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
        Rank[i] = 0;
    }
}

// find parent
// 7 -> 6 -> 4 -> 3 parent is 3
int findParent(int node)
{
    if(node == parent[node])
    {
        return node;
    }
    // return parent only
  // return findParent(parent[node]);
    return parent[node] = findParent(parent[node]);
}


// union
void Union(int u, int v)
{
    u = findParent(u);
    v = findParent(v);

    if(Rank[u] < Rank[v])
    {
        parent[u] = v;
    }
    else if(Rank[v] < Rank[u])
    {
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
    makeSet(n);

    while(m--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    // if 2 and 3 belong to the same Component or not
    if(findParent(2) != findParent(3))
    {
        cout << "They are Different comppoent" << endl;
    }
    else{
        cout << "Same Component" << endl;
    }

    return 0;
}
