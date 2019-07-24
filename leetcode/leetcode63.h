//
// Created by lhq on 2019/7/24.
//

#ifndef ALGORITHM_LEETCODE63_H
#define ALGORITHM_LEETCODE63_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class LeetCode63 {
private:
    int row;
    int col;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        row = obstacleGrid.size();
        if(row == 0)
            return 0;
        col = obstacleGrid[0].size();
        if(col == 0)
            return 0;
        if(obstacleGrid[0][0] == 1 || obstacleGrid[row-1][col-1] == 1)
            return 0;

        vector<vector<int>> ways(row, vector<int>(col,0));
        ways[0][0] = 1;
        for (int i = 1; i < row; ++i) {
            ways[i][0] = (obstacleGrid[i][0] != 1)?ways[i-1][0]:0;
        }
        for (int i = 1; i < col; ++i) {
            ways[0][i] = (obstacleGrid[0][i] != 1)?ways[0][i-1]:0;
        }

        int end = max(row, col);
        for(int i = 1; i < end; i++) {

            // update row : row == i
            for(int j = i; i < row && j < col; j++) {
                ways[i][j] = (obstacleGrid[i][j] != 1)?(ways[i-1][j] + ways[i][j-1]):0;
            }

            // update col : col == i
            for(int j = i; j < row && i < col; j++) {
                ways[j][i] = (obstacleGrid[j][i] != 1)?(ways[j-1][i] + ways[j][i-1]):0;
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << ways[i][j] << " ";
            }
            cout << endl;
        }

        return ways[row-1][col-1];
    }

    void run() {

        vector<vector<int>> array = {
                {0, 0, 0, 0, 0, 0},
                {0, 0, 1, 0, 1, 0},
                {0, 0, 0, 0, 0, 0}
        };

        int ways = uniquePathsWithObstacles(array);
        cout << ways << endl;

    }
};

#endif //ALGORITHM_LEETCODE63_H
