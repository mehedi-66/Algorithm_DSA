/*
    ************************ Rat in A Maze ***************

    consider a rat placed at (0, 0) in a square matrix of N x N. It has to reach the destination at (N-1, N-1).
    Find all possible paths that rat can take to reach from source to destination.

    => 0 is block
    => 1 is open

    => Direction => UDLR up, down, left, right

    Not that: In a path, no cell can be visited more than one time

    (0,0) => (N-1, N-1)

    Lexicographical order => DLRU

    Input:
        N = 4
        m[][] = {{1, 0, 0, 0},
                 {1, 1, 0, 1},
                 {1, 1, 0, 0},
                 {0, 1, 1, 1}
               }


     output:
        DDRDRR  DRDDRR


    Approach :
            1) take a visited matrix N x N fill with 0
            2) take f(row, col, ds => string) and call
            3) if D L R U try to check is possible to go
            4) if it can be possible to go then mark its => (row, col) visited => 1 and put String = "D" or some thing
            5) it is not right part then back track and unmark and remove the Direction whatever you put one the string
            6) this way find all possible path and print them


            function goes and come back ...

            f()
            {
             down
              f() goes & back
             left
              f()
             right
              f()
             up
              f()

            }

*/

#include<bits/stdc++.h>
using namespace std;


void solve(int i, int j, vector< vector<int> > &Matrix, int n, vector<string> &ans, string Move, vector< vector<int> > &vis)
{
    if(i == n-1 && j == n-1)
    {
        ans.push_back(Move);
        return ;
    }

    // down
    if(i+1 < n && vis[i+1][j] == 0 && Matrix[i+1][j] == 1)
    {
        vis[i][j] = 1;
        solve(i+1, j, Matrix, n, ans, Move + "D", vis);
        // return back if move it not go to destination
        vis[i][j] = 0;
    }

    // left
    if(j-1 >= 0 && vis[i][j-1] == 0 && Matrix[i][j-1] == 1)
    {
        vis[i][j] = 1;
        solve(i, j-1, Matrix, n, ans, Move+"L", vis);
        //return back
        vis[i][j-1] = 0;
    }

    // right
    if(j+1 < n && vis[i][j+1] == 0 && Matrix[i][j+1] == 1)
    {
        vis[i][j] = 1;
        solve(i, j+1, Matrix, n, ans, Move + "R", vis);
        // return back
        vis[i][j] = 0;
    }

    // up
    if(i-1 >= 0 && vis[i-1][j] == 0 && Matrix[i-1][j] == 1)
    {
        vis[i][j] = 1;
        solve(i-1, j, Matrix, n, ans, Move + "U", vis);
        // return back
        vis[i][j] = 0;
    }
}


int main()
{

     int n = 4;
    vector< vector<int> > Matrix({{1, 0, 0, 0},
                 {1, 1, 0, 1},
                 {1, 1, 0, 0},
                 {0, 1, 1, 1}
               });

     vector<string> ans;
     // take visited array
     vector< vector<int> > vis(n, vector<int>(n, 0));

     if(Matrix[0][0])
     {
         // n x n ,
         solve(0, 0, Matrix, n, ans, "", vis);

     }

     // print

     for(int i = 0;  i < ans.size(); i++)
     {
         cout << ans[i] << endl;
     }

    return 0;
}



// ***************************** Efficient Solution only one loop run and dynamically call DLRU sides ******************************
/*

    Possible Direction
     D | L | R | U


         (i-1, j)
            |
 (i, j-1) --O-- (i, j+1)
            |
         (i+1, j)


         D  |  L   |   R  |  U
  i =>  +1  | +0   |  +0  | -1
  j =>  +0  | -1   |  +1  | +0

  di[]
  dj[]

  // make a rule

    i + di[index]
    j + dj[index]

*/
#include<bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector< vector<int> > &Matrix, int n, vector<string> &ans, string Move, vector< vector<int> > &vis, int di[], int dj[])
{
    if(i == n-1 && j == n-1)
    {
        ans.push_back(Move);
        return ;
    }

    string dir = "DLRU";

    // loop for call and check it have any path or not
    for(int index = 0; index < n; index++)
    {
        int nexti = i + di[index];
        int nextj = j + dj[index];

        // check condition direction has or not
        if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && vis[nexti][nextj] == 0 && Matrix[nexti][nextj]== 1)
        {
            vis[i][j] = 1;
            solve(nexti, nextj, Matrix, n, ans, Move+dir[index], vis, di, dj);
            vis[i][j] = 0;
        }
    }

}


int main()
{
    int n = 4;
    vector< vector<int> > Matrix({{1, 0, 0, 0},
                 {1, 1, 0, 1},
                 {1, 1, 0, 0},
                 {0, 1, 1, 1}
               });

    // direction D  L  R   U
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, +1, 0};

    vector<string> ans;
    vector< vector<int> > vis(n, vector<int>(n, 0));

    if(Matrix[0][0] == 1)
    {
        solve(0, 0, Matrix, n, ans, "", vis, di, dj);
    }

    // print ans
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }


    return 0;
}

