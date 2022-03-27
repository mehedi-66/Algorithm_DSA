/*
    *************** M Coloring problem in graph ***********

    none of the two adjacent nodes are same color:

    Time complexity: O(n^m) all possible color
    space complexity: O(n) color array + O(n) axualiary space

    N = 4
    M = 3
    E = 5
    1 2
    2 3
    3 4
    4 1
    1 3

    output: 1

    It is possible to color the given graph using 3 color

    *** To find out every possible way ... it easy to use recursion

                            M = 3
                            0 1
                            0 2
                            0 3
                            1 2
                            1 3

                            f(0)
                color  1 /   2|   \ 3
                        /     |    \
                     f(1)
                  1 /     \
0 th node already 1 color  \2
                           f(2)
                          /
                        3/
                      f(3)
                      /   2\    3\
                    1/      \     \
                    x        x    f(4)

                                    T return

                                    when we get any possible solution then it the ans

*/
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
{
    for(int k = 0; k < n; k++)
    {
        // none of the adj node has same == col then .. if it is same color then return false
        if(k != node && graph[k][node] == 1 && color[k] == col)
        {
            return false;
        }

    }

    //
    return true;
}


bool solve(int node, int color[], int m, int n, bool graph[101][101])
{
    if(node == n)
    {
        return true;
    }
    //check using M color is possible to color or not
    for(int i = 1; i <= m; i++)
    {
        if( isSafe(node, color, graph, n, i) == 1)
        {
            // coloring
            color[node] = i;

            // call with next node

            if(solve(node+1, color, m, n, graph) == 1)
            {
                return true;
            }
            // if not possible to color backtrack and remove previous putting color
            color[node] = 0;
        }
    }

    // after all try it is not possible to color then return false;
    return false;
}
int main()
{

    // graph input:
    int n, m, e;
    cin >> n >> m >> e;

    bool graph[1001][101];
    for(int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    int color[n] = {0};

    if(solve(0, color, m, n, graph) == 1)
    {
        cout << "coloring is possible" << endl;
    }
    else
    {
        cout << "Not coloring is possible" << endl;
    }


    return 0;
}
