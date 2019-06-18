//
// Created by Sanfuh on 2019/6/14.
//

#ifndef ALGORITHM_OFFER42_H
#define ALGORITHM_OFFER42_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../tools/print.h"

using namespace std;

class Offer42 {
public:
    string ReverseSentence(string str) {

        string ans = "";

        string reverse_str(str);
        for (int i = 0; i < str.size(); ++i) {
            reverse_str[i] = str[str.size() - 1 - i];
        }

        reverse_str.push_back(' ');
        int begin = 0, end = 0;
        cout << "|" << reverse_str << "|" << endl;
        while(end < reverse_str.size()) {

            cout << "begin: " << begin << " end: " << end << endl;
            if(begin == end && reverse_str[begin] == ' ') {
                begin++;
                end++;
            } else if(begin == end && reverse_str[begin] != ' ') {
                end++;
            } else if(begin != end && reverse_str[end] != ' ') {
                end++;
            } else if(begin != end && reverse_str[end] == ' ') {
                int i = begin, j = end - 1;
                while(i < j) {
                    char temp = reverse_str[i];
                    reverse_str[i] = reverse_str[j];
                    reverse_str[j] = temp;
                    i++;
                    j--;
                }
                end++;
                begin = end;
            } else {
                cout << "error" << endl;
            }
        }
        reverse_str.pop_back();

        return reverse_str;
    }

    void run() {

        string str = "Wonderful";

        string ans = ReverseSentence(str);

        cout << ans << endl;
    }
};

#endif //ALGORITHM_OFFER42_H
