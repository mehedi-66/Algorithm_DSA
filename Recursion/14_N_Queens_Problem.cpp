/*
    ***************** N Queens Problem ************

    Leetcode: 51

    The n-queens puzzle is the problem of placing n queens on an N x N chessboard such that no two queens attack each other
    given an integer n, return all distinct solutions to the n-queens puzzle.
    Each solution contains a distinct board configuration of the queens placement where "Q" and "." both indicate a queen and an empty space, respacetively

    Rules:
     1) Every Row have Q
     2) Every coll have Q
     3) none of the Q attack each other

    * Queen can be attack => 8 direction

    Example: 4 x 4

             4 queens have to place

        Here we see each Q attack diagonally

        -----------------
        [ Q |   |   |   ]
        -----------------
        [   | Q |   |   ]
        -----------------
        [   |   | Q |   ]
        -----------------
        [   |   |   | Q ]
        ----------------

_______________________________

        No Queen attack each other Check 8 direction
        8 direction like magnetic field

        -----------------
        [   | Q |   |   ]
        -----------------
        [   |   |   | Q ]
        -----------------
        [ Q |   |   |   ]
        -----------------
        [   |   | Q |   ]
        ----------------

_______________________________

        Another way we can place a N queens no one attack each other

        -----------------
        [   |   | Q |   ]
        -----------------
        [ Q |   |   |   ]
        -----------------
        [   |   |   | Q ]
        -----------------
        [   | Q |   |   ]
        ----------------
_________________________________________________________________________________________________________________
                Solution Approach:
                                    1) put queen in the first coll 0 th row
                                    2) then then second row ... and so on
                                    3) call recursion and try to put queen on the next coll
                                    4) so that not queen attack each other
                                    5) if it is not possible to put any coll then ... => backtrack
                                    6) and remove the previous queen where we put the last queen
                                    7) this way run
                                    8) when find any successfully place N queen then store it



                                                                [][][][]
                                                                [][][][]
                                                                [][][][]
                            ----------------------------------------------------------------------------
                           /                           |                     |                          \
                          /                            |                     |                           \
                         /                             |                     |                            \
                        /                              |                     |                             \

                  [Q][][][]                        [][][][]                 [][][][]                      [][][][]
                  [][][][]                         [Q][][][]                [][][][]                      [][][][]
                  [][][][]                         [][][][]                 [Q][][][]                     [][][][]
                  [][][][]                         [][][][]                 [][][][]                      [Q][][][]
       ----------------------------
     /
    /
  [Q][][][]
  [][][][]
  [][Q][][]
  [][][][]
------------
     |
[Q][ ][*][ ]
[ ][ ][*][ ]
[ ][Q][*][ ]
[ ][ ][*][ ]

    X

in the third coll it is not possible to put Queen that time => backtrack Happened with removing previous Q as well


************ left 3 side check
  \
-- Q
  /

only check ... when we check .. the queen attack each other or not


*/

// ******************** START not efficient solution *********

#include<bits/stdc++.h>
using namespace std;

// check 3 side of Q

int isSafe(int row, int col, vector<string> &board, int n)
{

    // check upper diagonal
    int duprow = row;
    int dupcol = col;

    while(row >= 0 && col >= 0)
    {
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    // check left row
    col = dupcol;
    row = duprow;

    while(col >= 0)
    {
        if(board[row][col] == 'Q') return false;
         col--;
    }


    // check down diagonal
    row = duprow;
    col = dupcol;

    while(row < n && col >= 0)
    {
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }


    return true;

}
void solve(int col, vector<string> &board, vector< vector<string> > &ans, int n)
{
    if(col == n)
    {
        ans.push_back(board);
        return ;
    }
    //cout << "Hi Mehedi" << endl;
    // one by one row put
    for(int row = 0; row < n; row++)
    {
        // here we check is it safe place for put Q or not
        // O(n) x (O(n) + O(n) + O(n))
        // + for 3 direction check
        if(isSafe(row, col, board, n) == 1)
        {
            // if it is safe place then put Q and go next coll
            board[row][col] = 'Q';

            solve(col+1, board, ans, n);

            // if it not safe place then remove Q
            board[row][col] = '.';
        }
    }
}
int main()
{
    int n = 4;
    vector< vector<string> > ans;
    vector<string> board(n);

    // take string and push into => board
    string S(n, '.');
    for(int i = 0; i < n; i++)
    {
        board[i] = S;
    }

    solve(0, board, ans, n);

    // print board
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            //cout << "Mehedi" << endl;
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}

// ******************** END not efficient solution *********


// ############### Optimize the code ############


// ******************* START efficient Solution ************
    /*
        using Hashing we can be avoid (o(n) + o(n) + o(n))
        \
       --Q
        /


            left side of  --Q
        1) if any row has already one queen then not put possible to make N queen place in this way


        Q  lower diagonal
       /
        2) take (2n-1) Hash and when we put any queen that time mark its => (row + col) => 1  remember row + col in case equal for lower diagonal times


      \
       Q  upper diagonal

       3) take (2n-1) Hash and apply this formula => [ (n-1) + (col-row)] => 1 hash mark it is one

    */
#include<bits/stdc++.h>
using namespace std;


void solve(int col, vector<string> &board, vector< vector<string> > &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
{
    if(col == n)
    {
        ans.push_back(board);
        return ;
    }

    // run through row
    for(int row = 0; row < n; row++)
    {
        // check the put queen could be attacking position or not
        if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n-1 + col-row] == 0)
        {
            // all are 0 means none of Q attack this putting Q
            // place queue  and mark => 1
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n-1 + col - row] = 1;

            // call recursion
            solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

            // in this way not possible then return back => backtracking
            board[row][col] = '.';
             leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n-1 + col - row] = 0;
        }
    }
}

int main()
{
    int n = 4;

    vector< vector<string> > ans;
    vector<string> board(n);
    string S(n, '.');
    for(int i = 0; i < n; i++)
    {
        board[i] = S;
    }

    // create three Hashing
    vector<int> leftRow(n, 0), upperDiagonal(2*n - 1, 0), lowerDiagonal(2*n-1, 0);

    // call recursion
    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

    // print ans
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }


    return 0;
}

// **************** END efficient Solution **************

