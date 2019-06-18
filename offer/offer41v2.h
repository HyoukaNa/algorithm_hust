//
// Created by Sanfuh on 2019/6/13.
//

#ifndef ALGORITHM_OFFER41V2_H
#define ALGORITHM_OFFER41V2_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../tools/print.h"

using namespace std;

class Offer41v2 {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {

        vector<vector<int>> ans;

        int small = 1, big = 2;
        int current = small + big;

        //cout << small << " " << big << " " << current << endl;
        //cout << " -*-*-*-*-*-*- " << endl;

        while(small <= (1 + sum)/2) {

            if(current < sum) {
                big++;
                current += big;
            } else if(current > sum) {
                current -= small;
                small++;
            } else if(current == sum) {
                vector<int> sequence(big - small + 1);
                for(int i = 0; i <= big - small; i++) {
                    sequence[i] = i + small;
                }
                ans.push_back(sequence);
                big++;
                current += big;
            }

            //cout << small << " " << big << " " << current << endl;
        }

        return ans;
    }

    void run() {

        vector<vector<int>> ans = FindContinuousSequence(100);

        for(int i = 0; i < ans.size(); i++) {
            print(ans[i]);
        }

    }
};

#endif //ALGORITHM_OFFER41V2_H
