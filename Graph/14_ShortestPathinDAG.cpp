
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
