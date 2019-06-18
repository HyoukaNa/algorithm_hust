//
// Created by Sanfuh on 2019/6/3.
//

#ifndef DEMO_OFFER30_H
#define DEMO_OFFER30_H

#include <iostream>
#include <vector>
#include <list>
#include "../tools/print.h"

using namespace std;

class Offer30 {

public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {

        vector<int> ans;

        int len = input.size();
        if( len < k || len == 0 || k <= 0) {
            return ans;
        }

        list<int> kmin;
        for (int i = 0; i < input.size(); ++i) {

            int klen = kmin.size();
            if(kmin.size() == 0) {
                kmin.push_back(input[i]);
            } else if(kmin.size() < k) {
                // insert acs
                for(auto iter = kmin.begin();iter != kmin.end();iter++) {
                    if(*iter > input[i]) {
                        kmin.insert(iter, input[i]);
                        break;
                    }
                }

                if(kmin.size() != (klen + 1)) {
                    kmin.push_back(input[i]);
                }
            } else if(input[i] < *kmin.rbegin()) {

                kmin.pop_back();

                for(auto iter = kmin.begin();iter != kmin.end();iter++) {
                    if(*iter > input[i]) {
                        kmin.insert(iter, input[i]);
                        break;
                    }
                }

                if(kmin.size() != klen) {
                    kmin.push_back(input[i]);
                }

            }
        }

        for (auto iter = kmin.begin(); iter != kmin.end(); iter++) {
            ans.push_back(*iter);
        }

        return ans;
    }


    void run() {

        vector<int> arr = {4,5,1,6,2,7,3,8};

        vector<int> ans = GetLeastNumbers_Solution(arr, 6);

        print(ans);

    }

};

#endif //DEMO_OFFER30_H
