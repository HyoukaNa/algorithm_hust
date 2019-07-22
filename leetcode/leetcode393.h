//
// Created by lhq on 2019/7/22.
//

#ifndef ALGORITHM_LEETCODE393_H
#define ALGORITHM_LEETCODE393_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../tools/print.h"

class LeetCode393 {
public:
    bool validUtf8(vector<int>& data) {

        int utf8[4] = {0x7f, 0xcf,0xef, 0xf7};
        int tail = 0xaf;

        for(int i = 0; i < data.size(); i++) {

            int type = -1;
            for(int j = 0; j < 4; j++) {
                data[i] = data[i] & 0x000000ff;
                if(data[i] & utf8[j] == data[i]) {
                    type = j;
                    break;
                }
            }
            if(type == -1)
                return false;

            for(int j = 0; j < type; j++) {
                i++;
                data[i] = data[i] & 0x000000ff;
                if(data[i] & tail != data[i]) {
                    return false;
                }
            }
        }

        return true;
    }

    void run() {

        vector<int> data = {197,130,1};
        bool ans = validUtf8(data);

        cout << (ans?"true":"false") << endl;
    }
};

#endif //ALGORITHM_LEETCODE393_H
