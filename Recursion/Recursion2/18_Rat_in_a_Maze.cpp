/*
    ************** Rat in a Maze ***********

    2D matrix

    [1,1] to [n-1, n-1]  destination have to go

    1=> allowed move
    0=> not allowed move

    u d r l ==> move can be


    1) visited array to identity ... path traverse or not


    safe move
    (i,j) => (k,l)

    * inside the matrix
    * 1 has the cell
    * not visited previously

*/
#include<bits/stdc++.h>
using namespace std;

int isSafe(int x, int y, int n, int visited[4][4], int a[4][4])
{
    // inside the matrix and not visited and matrix cell value is 1

    if((x >= 0) && (y >= 0) && visited[x][y] == 0 && a[x][y] == 1)
    {
        return true;
    }
    else{
        return false;
    }
}
void solve(int a[4][4], int n, vector<string> &ans, string path, int visited[4][4], int x, int y)
{
    // base case
    if(x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return ;
    }

    visited[x][y] = 1;

    // 4 choices D, L, R, U

    // down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, n, visited, a))
    {
        path.push_back('D');
        solve(a, n, ans, path, visited, newx, newy);

        // normal back
        path.pop_back();
    }

    // left
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, n, visited, a))
    {
        path.push_back('L');
        solve(a, n, ans, path, visited, newx, newy);

        // normal back
        path.pop_back();
    }

    // Right
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, n, visited, a))
    {
        path.push_back('L');
        solve(a, n, ans, path, visited, newx, newy);

        // normal back
        path.pop_back();
    }


    // upper
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, n, visited, a))
    {
        path.push_back('L');
        solve(a, n, ans, path, visited, newx, newy);

        // normal back
        path.pop_back();
    }



    // back to normal to later work
    visited[x][y] = 0;


}


int main()
{
   int a[4][4] = {{1, 0, 0, 0},
                   {1, 1, 0, 1},
                    {1, 1, 0, 0},
                     {0, 1, 1, 1}
                    };


        // if the first index maze not standable then
        if(a[0][0] == 0)
        {
            return 0;
        }
        int srcx = 0;
        int srcy = 0;

        int visited[4][4];

        // initialise with 0
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                visited[i][j] = 0;
            }
        }

        vector< string > ans;
        string path = "";

        solve(a, 4, ans, path, visited, srcx, srcy);

        // print
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;

    return 0;
}
