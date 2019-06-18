//
// Created by Sanfuh on 2019/6/4.
//

#ifndef DEMO_OFFER33_H
#define DEMO_OFFER33_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

class Offer33 {

public:
    string PrintMinNumber(vector<int> numbers) {

        if(numbers.size() == 0)
            return "";
        else if(numbers.size() == 1)
            return "" + to_string(numbers[0]);

        int total_char = 0;
        vector<string> strs(numbers.size());
        for (int i = 0; i < numbers.size(); ++i) {
            strs[i] = to_string(numbers[i]);
            total_char += strs[i].size();
        }

        cout << "total_char : " << total_char << endl;

        sort(strs.begin(), strs.end(),[](string &a, string &b){

            cout << "compare " << a << " and " << b << endl;

            string::iterator iter_a = a.begin();
            string::iterator iter_b = b.begin();

            while(iter_a != a.end() && iter_b != b.end()) {

                if(*iter_a < *iter_b)
                    return true;
                else if(*iter_a > *iter_b)
                    return false;

                iter_a++;
                iter_b++;
            }

            cout << " not equal length " << endl;

            if(iter_a != a.end() && iter_b == b.end()) {
                while(iter_a != a.end()) {
                    cout << "compare " << *iter_a << " and " << *b.begin() << endl;
                    if(*iter_a < *b.begin())
                        return true;
                    else if (*iter_a > *b.begin())
                        return false;
                    iter_a++;
                }
            } else if(iter_a == a.end() && iter_b != b.end()) {
                while(iter_b != b.end()) {
                    cout << "compare " << *iter_b << " and " << *a.begin() << endl;
                    if(*iter_b < *a.begin())
                        return false;
                    else if(*iter_b > *a.begin())
                        return true;
                    iter_b++;
                }
            }

            return true;
        });

        cout << "sort complete" << endl;

        string s = "";
        for (int i = 0; i < numbers.size(); ++i) {
            s += strs[i];
            cout << "|" << strs[i];
        }
        cout << "|" << endl;

        return s;
    }

    void run() {

        vector<int> arr1 = {3334,3,3333332};
        string result = PrintMinNumber(arr1);

        cout << result << endl;
    }



};

#endif //DEMO_OFFER33_H
