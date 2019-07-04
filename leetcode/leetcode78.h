//
// Created by lhq on 2019/7/4.
//

#ifndef ALGORITHM_LEETCODE78_H
#define ALGORITHM_LEETCODE78_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <bitset>
#include "../tools/print.h"

class LeetCode78 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> sets;
        vector<int> subset;

        int length = nums.size();
        if(length == 0) {
            sets.push_back(subset);
            return sets;
        }
        add_all_subset(sets, nums, subset, 0);

        return sets;
    }

    void add_all_subset(vector<vector<int>> &sets, vector<int>& nums, vector<int> subset, int num) {

        if(num == nums.size() - 1) {
            sets.push_back(subset);
            subset.push_back(nums[num]);
            sets.push_back(subset);
            return;
        }

        add_all_subset(sets, nums, subset, num + 1);
        subset.push_back(nums[num]);
        add_all_subset(sets, nums, subset, num + 1);
    }

    void run() {

        vector<int> nums = {1, 2, 3};
        vector<vector<int>> sets = subsets(nums);

        for (int i = 0; i < sets.size(); ++i) {
            print(sets[i]);
        }

    }

};



#endif //ALGORITHM_LEETCODE78_H
