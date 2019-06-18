//
// Created by Sanfuh on 2019/6/13.
//

#ifndef ALGORITHM_OFFER40_H
#define ALGORITHM_OFFER40_H

#include <iostream>
#include <vector>

using namespace std;

class Offer40 {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {

        int len = data.size();
        if(len == 0 || len%2 == 1) {
            return ;
        }

        int resultXOR = 0;
        for (int i = 0; i < len; ++i) {
            resultXOR ^= data[i];
        }

        int first_xor_bit = IndexOfFirstBitIs1(resultXOR);

        *num1 = 0;
        *num2 = 0;

        for (int i = 0; i < len; ++i) {
            if(IsIndexBit1(data[i], first_xor_bit)) {
                *num1 ^= data[i];
            } else {
                *num2 ^= data[i];
            }
        }

        return;
    }

    unsigned int IndexOfFirstBitIs1(int number) {

        int index = 0;

        for (int i = 0; i < sizeof(int)*8-1; ++i) {

            if( (number & 0x1) == 1) {
                return index;
            } else {
                number = number >> 1;
                index++;
            }
        }

        return index;
    }

    bool IsIndexBit1(int number, int index) {

        number = number >> index;
        if((number & 1) == 1)
            return true;
        else
            return false;
    }

    void run() {

        vector<int> data = {2,4,3,6,3,2,5,5};
        int num1, num2;

        FindNumsAppearOnce(data, &num1, &num2);

        cout << num1 << " " << num2 << endl;

        cout << (1 << 5) << " " << IndexOfFirstBitIs1(1 << 5) << endl;
    }
};

#endif //ALGORITHM_OFFER40_H
