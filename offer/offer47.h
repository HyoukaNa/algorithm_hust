//
// Created by Sanfuh on 2019/6/14.
//

#ifndef ALGORITHM_OFFER47_H
#define ALGORITHM_OFFER47_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../tools/print.h"

using namespace std;

class Offer47 {
public:
    int Add(int num1, int num2)
    {
        int sum, carry;
        do {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;

            num1 = sum;
            num2 = carry;
        } while(num2 != 0);

        return num1;
    }

    void run() {

        cout << Add(5, 17) << endl;

        cout << Add(100, 200) << endl;
    }
};

#endif //ALGORITHM_OFFER47_H
