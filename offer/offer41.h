//
// Created by Sanfuh on 2019/6/14.
//

#ifndef ALGORITHM_OFFER41_H
#define ALGORITHM_OFFER41_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../tools/print.h"

using namespace std;

class Offer41 {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {

        vector<int> ans;

        int len = array.size();
        if(len < 2)
            return ans;

        int small = 0, big = len - 1;
        int last_small = -1, last_big = -1;
        while(small < big) {

            if(array[small] + array[big] < sum) {
                small++;
            } else if (array[small] + array[big] > sum) {
                big--;
            } else if(last_small == -1 || last_big == -1) {
                last_small = small;
                last_big = big;
                big--;
                small++;
            } else {
                if(array[last_small] * array[last_big]
                    > array[small] * array[big]) {
                    last_small = small;
                    last_big = big;
                }
                big--;
                small++;
            }
        }

        if(last_small == -1 || last_big == -1)
            return ans;

        ans.push_back(array[last_small]);
        ans.push_back(array[last_big]);

        return ans;
    }

    void run() {

        vector<int> data = {1,2,4,7,11,16};

        vector<int> ans = FindNumbersWithSum(data, 10);

        print(ans);
    }
};

#endif //ALGORITHM_OFFER41_H
