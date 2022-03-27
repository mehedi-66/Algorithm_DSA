/*
    **************** Sudoko Solver using Recursion and BackTracking *************

    9 x 9  board

    Rules:
        1) Every row have to have 1-9 unique elements
        2) Every col have to have 1-9 unique elements
        3) And 3 x 3 have to have 1-9 unique elements



*/
#include<bits/stdc++.h>
using namespace std;

bool solve(vector< vector<char> > &board)
{
    // traverse two 2D array
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            // if board cell is empty then call the recursion
            if(board[i][j] == '.')
            {
                for(char ch = '1'; ch <= '9'; ch++)
                {
                    if(isValid(board, i, j, ch))
                    {
                        board[i][j] = ch;

                        if(solve(board) == true)
                        {
                            return true;
                        }
                        else{
                            board[i][j] = '.';
                        }
                    }
                }
                return false;

            }
        }
    }

    return true;
}


bool isValid(vector< vector<char> > &board, int row, int col, char c)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[i][col] == c)
        {
            return false;
        }
        if(board[row][i] == c)
        {
            return false;
        }
        if(board[3*(row/3) + i][3*(col/3) + i % 3] == c)
        {
            return false;
        }
    }

    return true;
}
int main()
{
    // given board data
    vector< vector<char> > board;

    solve(board);



    return 0;
}
