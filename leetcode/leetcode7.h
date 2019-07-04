//
// Created by lhq on 2019/6/28.
//

#ifndef ALGORITHM_LEETCODE7_H
#define ALGORITHM_LEETCODE7_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <bitset>
#include "../tools/print.h"

class LeetCode7 {
public:
    int reverse(int x) {

        int upper = ~(1 << 31);
        int flag = 1;
        vector<int> sequence;

        if(x == 0x80000000) {
            return 0;
        }


        if(x < 0) {
            flag = -1;
            x = (-1)*x;
        }

        int ans = 0;
        while(x != 0) {
            int ret = x%10;
            x = x/10;
            if(ans > upper/10) {
                return 0;
            }
            ans = ans * 10 + ret;
        }

        return flag * ans;
    }

    void run() {

        //int number = -2147483412;
        int number = -2147483648;
        int reverse_number = reverse(number);

        cout << number << " binary: " << bitset<sizeof(int)*8>(number) << endl;
        cout << reverse_number << " binary: " << bitset<sizeof(int)*8>(reverse_number) << endl;

        cout << "10000000000000000000000000000000 : " << (int)(0x80000000) << endl;

    }
};

#endif //ALGORITHM_LEETCODE7_H
