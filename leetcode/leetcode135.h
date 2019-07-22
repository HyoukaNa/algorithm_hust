//
// Created by lhq on 2019/7/19.
//

#ifndef ALGORITHM_LEETCODE135_H
#define ALGORITHM_LEETCODE135_H

#include <iostream>
#include <vector>
using namespace std;

class LeetCode135 {
public:
    int candy(vector<int>& ratings) {

        int len = ratings.size();
        if(len <= 1)
            return len;

        int sum = 0;
        vector<int> num(len, 1);
        for(int i = 1; i < len; i++) {
            if(ratings[i] > ratings[i - 1])
                num[i] = num[i - 1] + 1;
        }
        sum += num[len - 1];
        for(int i = len - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1] && num[i] <= num[i + 1])
                num[i] = num[i + 1] + 1;
            sum += num[i];
        }


        for(int i = 0; i < len; i++) {
            cout << ratings[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < len; i++) {
            cout << num[i] << " ";
        }
        cout << endl;
        return sum;
    }

    void run() {

        vector<int> input = {1,2,2,2,5,4,3,3,7,6,1,2};
        int sum = candy(input);
        cout << sum << endl;
    }
};

#endif //ALGORITHM_LEETCODE135_H
