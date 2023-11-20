/*

                79. Word Search

      Given an m x n grid of characters board and a string word,
      return true if word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cells,
    where adjacent cells are horizontally or vertically neighboring.
    The same letter cell may not be used more than once.


    Input:
         board

             [

              ["A","B","C","E"],
              ["S","F","C","S"],
              ["A","D","E","E"]

            ]

           word = "ABCCED"



        we need to track a visited array and .... so that no back track happened

       [
       ["A","B","C","E"],
       ["S","F","C","S"],
       ["A","D","E","E"]
       ]

       "ABCB"


       See ABcB    Handel by visited array




*/

#include<bits/stdc++.h>
using namespace std;

 class Solution {
public:

    // matrix checker

    bool helper(int row, int col, int n, int  m)
    {
        if((row >= 0 && row < n)  && ( col >= 0 && col < m) )
        {
            return true;
        }

        return false;
    }
    int solve(vector<vector<char>>& board, string word, int i , int j, int vis, string &ans, int &res, vector<vector<int>> &mp)
    {
       // cout << board[i][j] << " " << i << " " << j << endl;
        if(word == ans)
        {
            return res = 1 ;
        }
        int n = board.size();
        int m = board[0].size();

        int ar[4] = {0, 0, -1, 1};
        int ac[4] = {-1, 1, 0, 0};

        // move 4 side

        for(int k = 0; k < 4; k++)
        {
            int row = i + ar[k];
            int col = j + ac[k];


            if(helper(row, col, n, m) && (board[row][col] == word[vis]) && mp[row][col] == -1)
            {
                //cout << board[row][col] <<  " in " << row << " " << col << endl;
                ans.push_back(word[vis]);
                mp[row][col] = 1;
                solve(board, word, row, col, vis+1, ans, res, mp);
                ans.pop_back();
                mp[row][col] = -1;
            }
        }

        return res;


    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();


        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == word[0])
                {
                    int res = 0;
                    string ans = "";
                    ans.push_back(word[0]);

                     vector<vector<int>> mp(n, vector<int>(m, -1));
                    mp[i][j] = 1;
                    solve(board, word, i, j, 1, ans, res, mp);
                    if(res == 1)
                        return true;
                }
            }
        }

        return false;
    }

};
int main()
{
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

}
