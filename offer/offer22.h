//
// Created by Sanfuh on 2019/5/21.
//

#ifndef DEMO_OFFER22_H
#define DEMO_OFFER22_H

#define _DEBUG_

#include <iostream>
#include <vector>
#include "../tools/print.h"

using namespace std;

class Offer22 {

public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {

        if(pushV.size() != popV.size() || pushV.size() == 0 || popV.size() == 0) {
            return false;
        }

        return IsSubPopOrder(pushV, popV, 0, pushV.size()-1, 0, popV.size()-1);
    }

    void run() {

        vector<int> pushV = {1,2,3,4,5}; // 是某栈的压入顺序
        vector<int> popV1 = {4,5,3,2,1}; // 对应的一个弹出序列 true
        vector<int> popV2 = {4,3,5,1,2}; // 对应的一个弹出序列 false
        vector<int> popV3 = {3,5,4,1,2}; // 对应的一个弹出序列 false


        // cout << (IsPopOrder(pushV, popV1)?"true":"false") << endl;
        // cout << (IsPopOrder(pushV, popV2)?"true":"false") << endl;
        cout << (IsPopOrder(pushV, popV3)?"true":"false") << endl;

    }

    bool IsSubPopOrder(vector<int> const pushV, vector<int> const popV,
                        int push_beg, int push_end,
                        int pop_beg,  int pop_end) {
#ifdef _DEBUG_
        cout << "push_beg = " << push_beg << " push_end = " << push_end
             << " pop_beg = " << pop_beg << " pop_end = " << pop_end << endl;
#endif

        if((push_end - push_beg) != (pop_end - pop_beg) ||
                push_beg < 0 || push_end > pushV.size() - 1 ||
                pop_beg < 0 || pop_end > popV.size() - 1) {
#ifdef _DEBUG_
            cout << "error: " << endl
                << " pushV.size() = " << pushV.size() << " popV.size() =  " << popV.size() << endl
                << " push_beg = " << push_beg << " push_end = " << push_end
                << " pop_beg = " << pop_beg << " pop_end = " << pop_end << endl;
#endif
            return false;
        }

        if( (push_end - push_beg) == 0 && (pop_end - pop_beg) == 0) {
            if(pushV[push_beg] == popV[pop_beg]) {
#ifdef _DEBUG_
                cout << "one parameter compare" << endl
                    << " pushV = " << pushV[push_beg] << "  popV = " << pushV[push_beg] << endl;
#endif
                return true;
            }
            else {
#ifdef _DEBUG_
                cout << "one parameter compare" << endl
                     << " pushV = " << pushV[push_beg] << "  popV = " << pushV[push_beg] << endl;
#endif
                return false;
            }
        }

        int pop_first = popV[pop_beg];
        int push_mid_index = -1;
        for(int i = push_beg; i <= push_end; i++) {
            if(pushV[i] == pop_first) {
                push_mid_index = i;
                break;
            }
        }

#ifdef _DEBUG_
        cout << "push_mid_index = " << push_mid_index << endl;
#endif

        if(push_mid_index == -1) {
#ifdef _DEBUG_
            cout << "error: can not find pop beg element." << endl;
            print(pushV, push_beg, push_end);
            print(popV, pop_beg, pop_end);
#endif
            return false;
        }

        int left_len = push_mid_index - push_beg;
        int right_len = push_end - push_mid_index;

        bool ans = false;

        if(right_len == 0) {
            // push_mid_index == pop_beg
            ans = IsSubPopOrder(pushV, popV, push_beg, push_end - 1, pop_beg + 1, pop_end);
        } else if(left_len == 0) {
            ans = false;
        } else {
            ans = IsSubPopOrder(pushV, popV, push_beg, push_mid_index-1, pop_end+1-left_len, pop_end) &&
            IsSubPopOrder(pushV, popV, push_mid_index+1, push_end, pop_beg+1, pop_beg+right_len);
        }

#ifdef _DEBUG_
        cout << (ans?"true":"false") << endl;
#endif

        return ans;
    }



#endif //DEMO_OFFER22_H
