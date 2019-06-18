//
// Created by Sanfuh on 2019/6/3.
//

#ifndef DEMO_OFFER31_H
#define DEMO_OFFER31_H

#include <iostream>
#include <vector>

using namespace std;

class Offer31 {

public:

    int FindGreatestSumOfSubArray(vector<int> array) {

        int len = array.size();
        if(len < 1)
            return 0;

        vector<int> f(len);
        f[0] = array[0];
        int max_f = f[0];

        for (int i = 1; i < array.size(); ++i) {
            if(f[i - 1] < 0) {
                f[i] = array[i];
            } else {
                f[i] = f[i - 1] + array[i];
            }
            max_f = max(max_f, f[i]);
        }

        return max_f;

    }

    void run() {

        vector<int> arr = {6,-3,-2,7,-15,1,2,2};
        vector<int> arr2 = {-10,-1,-2,-9};

        cout << FindGreatestSumOfSubArray(arr2) << endl;
    }
};

#endif //DEMO_OFFER31_H
