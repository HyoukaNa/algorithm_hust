//
// Created by lhq46 on 2019/6/20.
//

#ifndef ALGORITHM_LEETCODE4_H
#define ALGORITHM_LEETCODE4_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../tools/print.h"

class LeetCode4 {

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int len1 = nums1.size();
        int len2 = nums2.size();

        if(len1 > len2)
            return findMedianSortedArrays(nums2, nums1);

        int iMin = 0, iMax = len1;
        while(iMin <= iMax) {
            int i = (iMin + iMax)/2;
            int j = (len1 + len2 + 1)/2 - i;
            // nums1[i-1] <= nums2[j]
            // nums2[j-1] <= nums2[i]
            if(j > 0 && i < len1  && nums2[j-1] > nums1[i]) {
                iMin = i + 1;
            } else if(i > 0 && j < len2 && nums1[i - 1] > nums2[j]) {
                iMax = i - 1;
            } else {

                int maxLeft = 0;
                if(i == 0) {
                    maxLeft = nums2[j-1];
                } else if(j == 0) {
                    maxLeft = nums1[i-1];
                } else {
                    maxLeft = max(nums1[i-1], nums2[j-1]);
                }
                if(((len1 + len2) & 0x01) == 1) {
                    return maxLeft;
                }

                int minRight = 0;
                if(i == len1) {
                    minRight = nums2[j];
                } else if(j == len2) {
                    minRight = nums1[i];
                } else {
                    minRight = min(nums1[i], nums2[j]);
                }
                return (maxLeft + minRight)/2.0;
            }
        }
        return -1.0;
    }

    void run() {

        vector<int> nums1 = {3};
        vector<int> nums2 = {1, 2, 4};
        double mid = findMedianSortedArrays(nums1, nums2);
        cout << mid << endl;

    }


};

#endif //ALGORITHM_LEETCODE4_H
