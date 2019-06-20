//
// Created by lhq46 on 2019/6/20.
//

#ifndef ALGORITHM_LEETCODE5_H
#define ALGORITHM_LEETCODE5_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../tools/print.h"

class LeetCode5 {
    // 最长回文子串
public:
    string longestPalindrome(string s) {

        int len = s.size();
        if(len <= 1)
            return s;

        vector<vector<int>> array(len, vector<int>(len, 0));
        int max_length = 0;
        int begin = 0, end = 0;

        for(int i = 0; i < len; i++) {
            array[i][i] = 1;
        }
        for(int i = 1; i < len; i++) {
            if(s[i-1] == s[i]) {
                array[i-1][i] = 2;
                if(array[i-1][i] > max_length) {
                    max_length = array[i-1][i];
                    begin = i - 1;
                    end = i;
                }
            }
        }

        for (int i = 2; i < len; ++i) {
            for (int j = 0; j < len - i; ++j) {

                if(array[j+1][j+i-1] != 0 && s[j] == s[j+i]) {
                    array[j][j+i] = array[j+1][j+i-1] + 2;
                }

                if(array[j][j+i] > max_length) {
                    max_length = array[j][j+i];
                    begin = j;
                    end = j + i;
                    string newstr(s.begin() + begin, s.begin() + end + 1);
                    cout << "new : " << newstr << endl;
                }
            }
        }

        string str(s.begin() + begin, s.begin() + end + 1);
        return str;
    }

    void run() {

        string s = "cbbd";
        string ans = longestPalindrome(s);

        cout << ans << endl;

    }
};

#endif //ALGORITHM_LEETCODE5_H
