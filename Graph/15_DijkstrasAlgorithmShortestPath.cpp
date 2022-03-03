/*
    Dijkstra's Algorithm Find the shortest Path

    1) take a priority queue in min heap
    2) take a distance array with INT_MAX
    3) run BFS and
    4) check the distance is adj node is current node => src to target is min the update the distance array
    5) After queue is empty then print the distance array

    priority_queue<int> q_Max;   by default is => Max heap

    priority_queue< int, vector<int>, greater<int> > q_Min;


*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, source;
    cin >> n >> m;

    vector< pair<int, int> > adj[n+1];

    int u, v, wt;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

     cin >> source;


     // Dijkstra's Algorithm begins from here
     priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;  // min-heap; in pair  => (dis, node)

     vector<int> distTo(n+1, INT_MAX);

     // First or source;
     distTo[source] = 0;
     pq.push(make_pair(0, source));

    while( !pq.empty())
    {
        //int queue =>  pair< dis, node>
        int dist = pq.top().first;
        int parentNode = pq.top().second;
        pq.pop();

        for(auto it : adj[parentNode])
        {
            // adj[] pair( node, weight)
            int next = it.first;
            int nextWeight = it.second;

            if(distTo[next] > distTo[parentNode] + nextWeight)
            {
                distTo[next] = distTo[parentNode] + nextWeight;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    cout << "The distances from source" << source << " are: " << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << distTo[i] << " ";
    }


    return 0;
}
