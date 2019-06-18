//
// Created by Sanfuh on 2019/6/14.
//

#ifndef ALGORITHM_OFFER42V2_H
#define ALGORITHM_OFFER42V2_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../tools/print.h"

using namespace std;

class Offer42v2 {
public:
    string LeftRotateString(string str, int n) {

        int len = str.size();
        if(len == 0) {
            return "";
        }

        n = n%len;

        string left(str.begin(), str.begin() + n);
        string right(str.begin() + n, str.end());

        return right + left;
    }

    void run() {


        cout << LeftRotateString("abcdefg", 2) << endl;

    }
};

#endif //ALGORITHM_OFFER42V2_H
