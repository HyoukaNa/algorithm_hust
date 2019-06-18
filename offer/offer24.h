//
// Created by Sanfuh on 2019/5/28.
//

#ifndef DEMO_OFFER24_H
#define DEMO_OFFER24_H

#include <iostream>
#include <vector>
#include <queue>
#include "../tools/print.h"

using namespace std;

struct SEQ {
    int begin;
    int end;
    SEQ(int x, int y) : begin(x), end(y) {
    }
};

class Offer24 {

public:
    bool VerifySquenceOfBST(vector<int> sequence) {

        int len = sequence.size();
        if(len == 0)
            return true;

        SEQ* aSeq = new SEQ(0, len - 1);
        queue<SEQ*> q;
        q.push(aSeq);

        while(!q.empty()) {

            int nums = q.size();
            for (int i = 0; i < nums ; ++i) {

                SEQ *seq = q.front();
                q.pop();

                // verify bst
                if( (seq->end - seq->begin) <= 1 ) {
                    continue;
                } else {

                    int left_beg = seq->begin;
                    int right_beg;
                    int mid = seq->end;
                    for (right_beg = left_beg; sequence[right_beg] < sequence[mid] && right_beg < mid; ++right_beg) {

                    }

//                    cout << left_beg << " " << right_beg << " " << mid << endl
//                         << "left : " << left_beg << " " << right_beg - 1
//                         << ", right : " << right_beg << " " << mid - 1 << endl;
                    for (int j = right_beg; j < mid; ++j) {
//                        cout << "compare : " << sequence[j] << ">" << sequence[mid]<< endl;
                        if(sequence[j] <= sequence[mid]) {
                            return false;
                        }
                    }

                    SEQ *seq1 = new SEQ(left_beg, right_beg - 1);
                    SEQ *seq2 = new SEQ(right_beg, mid - 1);
                    if(left_beg < right_beg) {
                        q.push(seq1);
                    }
                    if(right_beg < mid) {
                        q.push(seq2);
                    }


                }
            }
        }

        return true;
    }

    void run() {

        vector<int> vec1 = {5, 7, 6, 9, 11, 10, 8};
        vector<int> vec2 = {7, 4, 6, 5};
        vector<int> vec3 = {5, 4, 3, 2, 1};

        cout << (VerifySquenceOfBST(vec1)?"true":"false") << endl;
        cout << (VerifySquenceOfBST(vec2)?"true":"false") << endl;
        cout << (VerifySquenceOfBST(vec3)?"true":"false") << endl;
    }

};



#endif //DEMO_OFFER24_H
