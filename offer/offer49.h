//
// Created by Sanfuh on 2019/6/17.
//

#ifndef ALGORITHM_OFFER49_H
#define ALGORITHM_OFFER49_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bitset>
#include "../tools/print.h"

using namespace std;

class Offer49 {
public:
    int StrToInt(string str) {

        if(str.size() == 0)
            return 0;

        string::iterator iter = str.begin();
        int lag = 1;
        while(*iter == '+' || *iter == '-') {
            cout << "[-,+] *iter = " << *iter << endl;
            if(*iter == '-') {
                lag = -1;
            } else {
                lag = 1;
            }
            iter++;
        }

        int num = 0;
        int flag = 1 << (sizeof(int)*8-1);
        cout<<"bin:flag="<<bitset<sizeof(unsigned int)*8>(flag)<<endl;
        cout<<"bin:~flag="<<bitset<sizeof(unsigned int)*8>(~flag)<<endl;
        cout << "before[0~9] *iter = " << *iter << endl;
        while(*iter >= '0' && *iter <= '9' && iter != str.end()) {
            cout << "[0~9] *iter = " << *iter << endl;
            num = num*10 + (*iter - '0')*lag;
//            if((num & flag) != 0) {
//                cout<<"bin:&="<<bitset<sizeof(unsigned int)*8>(num & flag)<<endl;
//                cout << "overstack " << num << endl;
//                cout<<"bin:num="<<bitset<sizeof(unsigned int)*8>(num)<<endl;
//                return 0;
//            }

            iter++;
        }
        cout << num << endl;

        if(iter != str.end())
            return 0;

        return num;


    }

    void run() {

        cout << (1 << 31) << endl;
        string str = "-2147483647";
        cout<<"bin:2147483647="<<bitset<sizeof(int)*8>(-2147483647)<<endl;
        int integer = StrToInt(str);

        cout<<"---------------------------" << endl;
        cout<<"bin:-5="<<bitset<sizeof(int)*8>(-5)<<endl;

        cout << str << " -> " << integer << endl;
    }
};
#endif //ALGORITHM_OFFER49_H
