//
// Created by Sanfuh on 2019/6/14.
//

#ifndef ALGORITHM_OFFER46_H
#define ALGORITHM_OFFER46_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../tools/print.h"

using namespace std;

class Sum {
public:
    Sum() {
        n++;
        sum += n;
    }

    static int get_sum() {
        return sum;
    }

    static void Reset() {
        n = 0;
        sum = 0;
    }

private:
    static int n;
    static int sum;
};

int Sum::n = 0;
int Sum::sum = 0;

class Offer46 {
public:
    int Sum_Solution(int n) {



        Sum::Reset();
        Sum* a = new Sum[n];
        int ans = Sum::get_sum();
        delete [] a;
        return ans;
    }

    void run() {

        cout << Sum_Solution(100) << endl;

    }
};

#endif //ALGORITHM_OFFER46_H
