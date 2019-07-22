//
// Created by lhq on 2019/7/18.
//

#ifndef ALGORITHM_LEETCODE79_H
#define ALGORITHM_LEETCODE79_H

#include "leetcode5.h"
#include "leetcode7.h"
#include "leetcode46.h"
#include "leetcode78.h"
#include "leetcode88.h"
#include "leetcode148.h"
#include "leetcode206.h"
#include "leetcode315.h"
#include "leetcode493.h"

class LeetCode79 {
public:
    const int dir[4][2] = {
            {0, -1}, // up
            {0, 1}, // down
            {-1, 0}, // left
            {1, 0}  // right
    };

    bool exist(vector<vector<char>>& board, string word) {

        int row = board.size();
        if(row == 0)
            return false;
        int col = board[0].size();
        if(col == 0)
            return false;
        vector<vector<bool>> flag(row, vector<bool>(col, true));


        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if(find_str(board, flag, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool find_str(vector<vector<char>>& board, vector<vector<bool>>& flag, string& word, int i, int j, int index) {

        if(index == word.size() - 1)
            return board[i][j] == word[index];

        cout << "board[" << i << "][" << j << "] = " << board[i][j]
             << " word[" << index << "] = " << word[index] << endl;
        if(board[i][j] == word[index]) {

            flag[i][j] = false;
            for (int k = 0; k < 4; ++k) {
                int ii = i + dir[k][0];
                int jj = j + dir[k][1];
                if(ii >= 0 && ii < board.size() && jj >= 0 && jj < board[0].size() && flag[ii][jj]) {
                    cout << "(ii,jj) = " << ii << "," << jj << endl;
                    if(find_str(board, flag, word, ii, jj, index+1))
                        return true;
                }
            }
            flag[i][j] = true;
        }

        return false;
    }

    void run() {
        vector<vector<char>> board =
                {
                    {'a', 'a', 'a', 'a'},
                    {'a', 'a', 'a', 'a'},
                    {'a', 'a', 'a', 'a'},
                    {'a', 'a', 'a', 'a'},
                    {'a', 'a', 'a', 'b'}
                };
        string word = "aaaaaaaaaaaaaaaaaaaa";

        string ans = (exist(board,word))?"true":"false";
        cout << ans << endl;
    }
};

#endif //ALGORITHM_LEETCODE79_H
