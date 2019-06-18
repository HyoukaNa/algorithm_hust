//
// Created by Sanfuh on 2019/6/14.
//

#ifndef ALGORITHM_OFFER45_H
#define ALGORITHM_OFFER45_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../tools/print.h"

using namespace std;

class Offer45 {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return 0;

        vector<int> num(n);
        for (int i = 0; i < n; ++i) {
            num[i] = i;
        }

        int len = n;
        int index = 0;
        print(num);
        while(len > 1) {

            index = (index + m -1)%len;
            cout << "delete num[" << index << "] = " << num[index] << "  ===  ";
            num.erase(num.begin() + index);
            len--;
            print(num);
        }

        return num[0];
    }

    void run() {

        int n = 5, m = 3;

        cout << "n = " << n << ", m = " << m << endl;
        cout << LastRemaining_Solution(n, m) << endl;

    }
};

#endif //ALGORITHM_OFFER45_H
