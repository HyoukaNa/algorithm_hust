//
// Created by Sanfuh on 2019/6/2.
//

#ifndef DEMO_OFFER28_H
#define DEMO_OFFER28_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Offer28 {

public:
    vector<string> Permutation(string str) {

        vector<string> ans;

        if(str.size() == 0)
            return ans;

        ans = permutation(str, str);
        sort(ans.begin(),ans.end());
        ans.erase( unique( ans.begin(), ans.end() ), ans.end() );

        return ans;
    }

    vector<string> permutation(string str, string current_str) {

        vector<string> ans;

        if(current_str.size() == 0)
            return ans;

        if(current_str.size() == 1) {
            ans.push_back(current_str);
        }

        string one_short_str(current_str);
        char last_char = *(one_short_str.end()-1);
        one_short_str.pop_back();
        vector<string> one_short_ans = permutation(str, one_short_str);

        for (int i = 0; i < one_short_ans.size(); ++i) {

            string old_str = one_short_ans[i];
            for (int j = 0; j < old_str.size(); ++j) {
                string s(old_str);
                s.insert(s.begin()+j, last_char);
                ans.push_back(s);
            }
            string s(old_str);
            s.insert(s.end(), last_char);
            ans.push_back(s);
        }

        return ans;
    }

    void run() {

        string str = "aab";

        vector<string> ans = Permutation(str);

        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << endl;
        }

        cout << "total size : " << ans.size() << endl;

    }
};
#endif //DEMO_OFFER28_H
