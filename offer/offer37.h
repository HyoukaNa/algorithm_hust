//
// Created by Sanfuh on 2019/6/12.
//

#ifndef ALGORITHM_OFFER37_H
#define ALGORITHM_OFFER37_H

#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

class Offer37 {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {

        int len1 = 0, len2 = 0;

        for(ListNode* p = pHead1; p != nullptr; p = p->next) {
            len1++;
        }

        for(ListNode* p = pHead2; p != nullptr; p = p->next) {
            len2++;
        }

        ListNode* longlist;
        ListNode* shortlist;
        int longlen, shortlen;
        if(len1 >= len2) {
            longlist = pHead1;
            shortlist = pHead2;
            longlen = len1;
            shortlen = len2;
        } else {
            longlist = pHead2;
            shortlist = pHead1;
            longlen = len2;
            shortlen = len1;
        }

        for (int i = 0; i < (longlen - shortlen); ++i) {
            longlist = longlist->next;
        }

        while(longlist != nullptr && shortlist != nullptr) {
            if(longlist == shortlist) {
                return longlist;
            }
            longlist = longlist->next;
            shortlist = shortlist->next;
        }

        return nullptr;
    }

    void run() {

        int len = 8;
        ListNode** ln = new ListNode*[len];
        for (int i = 0; i < len; ++i) {
            ln[i] = new ListNode(i);
        }

        ln[1]->next = ln[2];
        ln[2]->next = ln[3];
        ln[3]->next = ln[6];

        ln[4]->next = ln[5];
        ln[5]->next = ln[6];

        ln[6]->next = ln[7];

        ListNode* res = FindFirstCommonNode(ln[1], ln[4]);
        cout << res->val << endl;

        for (int i = 0; i < len; ++i) {
            delete ln[i];
        }
        delete ln;

    }
};

#endif //ALGORITHM_OFFER37_H
