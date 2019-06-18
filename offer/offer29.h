//
// Created by Sanfuh on 2019/6/2.
//

#ifndef DEMO_OFFER29_H
#define DEMO_OFFER29_H

#include <iostream>
#include <vector>

using namespace std;

class Offer29 {

public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {

        if(numbers.size() == 0)
            return 0;

        int more_than_half_num = numbers[0];
        int times = 1;

        for (int i = 1; i < numbers.size(); ++i) {
            if(times == 0) {
                more_than_half_num = numbers[i];
                times++;
            } else if(numbers[i] != more_than_half_num) {
                times--;
            } else {
                times++;
            }
        }

        cout << "more_than_half_num : " << more_than_half_num << " times : " << times << endl;

        int count = 0;
        for (int j = 0; j < numbers.size(); ++j) {
            if(more_than_half_num == numbers[j])
                count++;
        }
        count *= 2;

        if(count > numbers.size()) {
            return more_than_half_num;
        } else {
            return 0;
        }

    }

    void run() {

        vector<int> arr = {2,2,2,2,2,1,3,4,5};

        cout << MoreThanHalfNum_Solution(arr) << endl;
    }
};

#endif //DEMO_OFFER29_H
