//
// Created by Sanfuh on 2019/5/28.
//

#include "print.h"

void print(vector<int> vec)
{
    int len = vec.size();
    if(len == 0) {
        cout << "null vector<int>" << endl;
        return;
    }

    for (int i = 0; i < len; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

}


void print(vector<int> vec, int beg, int end)
{
    int len = vec.size();
    if(len == 0) {
        cout << "null vector<int>" << endl;
        return;
    }

    if(beg < 0 || beg > len-1 ||
        end < 0 || end > len-1 ||
        end < beg) {
        cout << "illegal parameter beg:" << beg << " & end:" << end << " size = " << len << endl;
        return;
    }

    for (int i = beg; i <= end; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}
