//
// Created by Sanfuh on 2019/6/4.
//

#ifndef ALGORITHM_OFFER34_H
#define ALGORITHM_OFFER34_H

#include <iostream>
#include <vector>

using namespace std;

class Offer34 {

public:
    int GetUglyNumber_Solution(int index) {

        int paras = 3;
        int ugly[3] = {2, 3, 5};

        if(index < 1)
            return 0;

        vector<int> uglynums(index, 1);
        uglynums[0] = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        for(int i = 1; i < uglynums.size(); i++) {

            uglynums[i] = min(min(uglynums[index2]*2, uglynums[index3]*3), uglynums[index5]*5);

            while(uglynums[index2]*2 <= uglynums[i] ) {
                index2++;
            }
            while(uglynums[index3]*3 <= uglynums[i] ) {
                index3++;
            }
            while(uglynums[index5]*5 <= uglynums[i] ) {
                index5++;
            }
            //cout << index2 << " " << index3 << " " << index5 << endl;
        }

        return *uglynums.rbegin();
    }


    void run() {

        vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        for (int i = 0; i < test.size(); ++i) {
            //cout << test[i] << " : " << GetUglyNumber_Solution(test[i]) << endl;
            //cout << GetUglyNumber_Solution(test[i]) << endl;
        }
        cout << 1500 << " : " << GetUglyNumber_Solution(1500) << endl;

    }
};
#endif //ALGORITHM_OFFER34_H

//                for (int k = 0; k < paras; ++k) {
//
//                    if(j >= quick[k]) {
//
//                        if(uglynums[j]*ugly[k] > uglynums[i - 1] && uglynums[j]*ugly[k] < min_next) {
//                            min_next = uglynums[j]*ugly[k];
//                            cout << min_next << " ";
//                        } else if(uglynums[j]*ugly[k] < uglynums[i - 1]) {
//                            quick[k] = j + 1;
//                        }
//
//                    }
//
//                }

//                if(uglynums[j]*2 > uglynums[i - 1] && uglynums[j]*2 < min_next && ) {
//                    min_next = uglynums[j]*2;
//                    //cout << min_next << " ";
//                }
//                if(uglynums[j]*3 > uglynums[i - 1] && uglynums[j]*3 < min_next) {
//                    min_next = uglynums[j]*3;
//                    //cout << min_next << " ";
//                }
//                if(uglynums[j]*5 > uglynums[i - 1] && uglynums[j]*5 < min_next) {
//                    min_next = uglynums[j]*5;
//                    //cout << min_next << " ";
//                }
