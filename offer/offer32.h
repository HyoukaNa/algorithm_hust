//
// Created by Sanfuh on 2019/6/4.
//

#ifndef DEMO_OFFER32_H
#define DEMO_OFFER32_H

#include <iostream>
#include <vector>

using namespace std;

class Offer32 {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n < 1)
            return 0;

        string str;

        str = reverse_itos(n);

        return NumberOf1(str);

    }

    int NumberOf1(string str) {

        if(str.size() == 0)
            return 0;

        int highest_bit = *str.rbegin() - '0';
        str.pop_back();
        if(highest_bit == 0) {
            return NumberOf1(str);
        }

        int highest_bit_of_1 = 0;
        int leave_part_of_1 = 0;
        int leave_num = reverse_stoi(str);

        if(highest_bit == 1) {
            highest_bit_of_1 = leave_num + 1;
        } else {
            highest_bit_of_1 = mult(10, str.size());
        }

        if(str.size() == 0)
            leave_part_of_1 = 0;
        else
            leave_part_of_1 = highest_bit*str.size()*mult(10, str.size() - 1);

        cout << "highest_bit_of_1: " << highest_bit_of_1 << " | leave_part_of_1: " << leave_part_of_1
            << " | left array: " << str << endl;

        return highest_bit_of_1 + leave_part_of_1 + NumberOf1(str);
    }

    int reverse_stoi(string s) {

        int num = 0;

        for (auto it = s.rbegin(); it != s.rend(); it++) {
            num = 10*num + (*it - '0');
        }

        return num;
    }

    string reverse_itos(int num) {

        string s = "";

        while(num > 0) {

            int m = num/10;
            s.push_back(num - m*10 + '0');
            num = m;

        }

        return s;
    }

    int mult(int para, int times) {

        if(times <= 0)
            return 1;
        if(times == 1)
            return para;

        int halftimes = times >> 1;
        if(times & 0x1 == 0x1)
            return mult(para*para, halftimes)*para;
        else
            return mult(para*para, halftimes);
    }

    void run() {

        int num = 10000;
        int ans = NumberOf1Between1AndN_Solution(num);
        cout << num << " : " << ans << endl;
    }
};

#endif //DEMO_OFFER32_H
