//
// Created by lhq on 2019/7/4.
//

#ifndef ALGORITHM_LEETCODE46_H
#define ALGORITHM_LEETCODE46_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <bitset>
#include "../tools/print.h"

class LeetCode46 {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> sets;
        vector<int> subset;
        vector<int> left_nums(nums);

        back(sets, subset, left_nums);

        return sets;
    }

    void back(vector<vector<int>>& sets, vector<int> subset, vector<int> left_nums) {

        if(left_nums.size() == 0) {
            sets.push_back(subset);
            return ;
        }

        for (int i = 0; i < left_nums.size(); ++i) {
            vector<int> new_subset(subset);
            vector<int> new_left_nums(left_nums);

            new_subset.push_back(new_left_nums[i]);
            new_left_nums.erase(new_left_nums.begin()+i);
            back(sets, new_subset, new_left_nums);
        }
    }


    void run() {

        vector<int> nums = {1, 2, 3};
        vector<vector<int>> sets = permute(nums);

        for (int i = 0; i < sets.size(); ++i) {
            print(sets[i]);
        }

    }

};

#endif //ALGORITHM_LEETCODE46_H
