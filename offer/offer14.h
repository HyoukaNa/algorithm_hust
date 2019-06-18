//
// Created by Sanfuh on 2019/6/17.
//

#ifndef ALGORITHM_OFFER14_H
#define ALGORITHM_OFFER14_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../tools/print.h"

using namespace std;
class Offer14 {
public:
    void reOrderArray(vector<int> &array) {

        int len = array.size();
        if(len < 2)
            return;

        int index_last_odd = 0;
        if((array[0] & 0x1) == 0) {
            index_last_odd = -1;
        }
        cout << "index_last_odd : " << index_last_odd << endl;
        for (int i = 1; i < len; ++i) {

            if((array[0] & 0x1) == 0x1) {
                cout << "j = " << i << ", j > " << index_last_odd + 1 << endl;
                for (int j = i; j > index_last_odd + 1; --j) {
                    int temp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = temp;
                    print(array);
                }
                index_last_odd = index_last_odd + 1;
            }
        }

    }

    void run() {

        vector<int> input = {2,4,6,1,3,5,7}; // 17 5 5 2 10 14 12

        reOrderArray(input);

        print(input);

    }
};

#endif //ALGORITHM_OFFER14_H
