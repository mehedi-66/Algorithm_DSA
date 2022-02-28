
/*
    Cycle Detection in Directed Graph

    Topological sort is nothing but liniear array of nodes ...

*/
#include<bits/stdc++.h>
using namespace std;

bool isCyclic(vector<int> adj[], int n)
{
   queue<int> q;
   vector<int> indegree(n, 0);

   for(int i = 0; i < n; i++)
   {
       for(auto it : adj[i])
       {
           indegree[it]++;
       }
   }

   for(int i = 0; i < n; i++)
   {
       if(indegree[i] == 0)
       {
           q.push(i);
       }
   }

   int cnt = 0;
   while(!q.empty())
   {
       int node = q.front();
       q.pop();
       cnt++;

       for(auto it : adj[node])
       {
           indegree[it]--;
           if(indegree[it] == 0)
           {
               q.push(it);
           }
       }
   }

   if(cnt == n) return false;

   return true;
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

    if(isCyclic(adj, n))
    {
        cout << "is it has cycle " << endl;
    }
    else{
        cout << "is has no cycle" << endl;
    }

    return 0;
}
