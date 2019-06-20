//
// Created by lhq46 on 2019/6/20.
//

#ifndef ALGORITHM_LEETCODE88_H
#define ALGORITHM_LEETCODE88_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../tools/print.h"

class LeetCode88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int p1 = m - 1;
        int p2 = n - 1;
        int p3 = m + n - 1;

        print(nums1);
        for(; p1 >= 0 && p2 >= 0; p3--) {

            if(nums1[p1] > nums2[p2]) {
                nums1[p3] = nums1[p1];
                p1--;
            } else {
                nums1[p3] = nums2[p2];
                p2--;
            }
            print(nums1);
        }

        if(p1 >= 0) {
            cout << "return" << endl;
            return;
        }

        while(p2 >= 0) {
            nums1[p3] = nums2[p2];
            p3--;
            p2--;
        }

    }

    void run() {

        vector<int> nums1 = {1,2,3,0,0,0};
        vector<int> nums2 = {2,5,6};
        int m = 3;
        int n = 3;
        merge(nums1, m, nums2, n);
        print(nums1);
    }
};

#endif //ALGORITHM_LEETCODE88_H
