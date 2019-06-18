//
// Created by Sanfuh on 2019/6/14.
//

#ifndef ALGORITHM_OFFER44_H
#define ALGORITHM_OFFER44_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../tools/print.h"

using namespace std;

class Offer44 {
public:
    bool IsContinuous( vector<int> numbers ) {

        int len = numbers.size();
        if(len == 0)
            return false;

        sort(numbers.begin(), numbers.end());
        print(numbers);
        int index_of_first_not0 = 0;
        while(numbers[index_of_first_not0] == 0 && index_of_first_not0 < len) {
            index_of_first_not0++;
        }

        cout << index_of_first_not0 << endl;
        if(index_of_first_not0 > 4) {
            return false;
        } if(index_of_first_not0 == numbers.size()) {
            return true;
        } else if(numbers[index_of_first_not0] == 0) {
            return true;
        }
        cout << numbers[index_of_first_not0] << endl;

        int count = *numbers.rbegin() - numbers[index_of_first_not0] + 1;
        cout << count << endl;
        cout << "from " << *numbers.rbegin() << " to " << numbers[index_of_first_not0] << endl;
        int* hash = new int[count];
        for (int i = 0; i < count; ++i) {
            hash[i] = 0;
        }
        for (int i = index_of_first_not0; i < numbers.size(); ++i) {
            hash[numbers[i] - numbers[index_of_first_not0]]++;
        }

        int lack = 0;
        for (int i = 0; i < count; ++i) {
            if(hash[i] == 0)
                lack++;
            else if(hash[i] > 1)
                return false;
        }

        delete hash;

        cout << "lack: " << lack << " '0': " << index_of_first_not0 << endl;

        if(lack > index_of_first_not0)
            return false;
        else
            return true;
    }

    void run() {

        vector<int> data = {1,0,0,1,0};

        cout << (IsContinuous(data)?"true":"false") << endl;

    }
};

#endif //ALGORITHM_OFFER44_H
