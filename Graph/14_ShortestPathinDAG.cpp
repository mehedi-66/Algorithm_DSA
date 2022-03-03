
/*
    Shortest Path in wighted DAG => Directed acyclic Graph

    weighted vector< pair<int, int> > adj[n+1];

    first find the Topological sort

    Topological sort
    1) take visited array
    2) call DFS
    3) After call done store the node in stack => Stack

    Find shortest path:
    * Take dist array all => MAX_INT
    1) Take out stack top most element
    2) if(dist[node] != MAX_INT) that is ensure node is visited
    3) nodes Tervarse adj nodes
    4) if i get min distance current node to adj node then update the distance array
 */

 #include<bits/stdc++.h>
 using namespace std;

void findTopoSort(int node, int vis[], stack<int> &st, vector< pair<int,int> > adj[])
{
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(vis[it.first] == 0)
        {
            findTopoSort(it.first, vis, st, adj);
        }
    }

    st.push(node);
}

 void shortestPath(int src, int n, vector< pair<int, int> > adj[])
 {
     // first step is generate topological sort
     int vis[n+1] = {0};
     stack<int> st;
     for(int i = 0; i < n; i++)
     {
         if(vis[i] == 0)
         {
             findTopoSort(i, vis, st, adj);
         }
     }

    // second task is call BFS to topological sorted nodes one by one till the stack is not empty
    int dist[n+1];
    for(int i= 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    // start
    dist[src] = 0;
    while( !st.empty() )
    {
        int node = st.top();
        st.pop();

        //  if the dist [node] == Infinity  then the node not visited yet ..
        // if the node has been reach previously
        if(dist[node] != INT_MAX){
            for(auto it : adj[node])
            {
                if(dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    // print the distance src to Target node;
    for(int i = 0; i < n; i++)
    {
        if(dist[i] == INT_MAX)
        {
            cout << "INT" << " ";
        }
        else{
            cout << dist[i] << endl;
        }
    }



 }


 int main()
 {
     int n, m;
     cin >> n >> m;

     vector< pair<int, int> > adj[n+1];

     for(int i = 0; i < m; i++)
     {
         int u, v, wt;
         cin >> u >> v >> wt;

         adj[u].push_back({v, wt});
     }

                // src
     shortestPath(0, n, adj);

     return 0;
 }
