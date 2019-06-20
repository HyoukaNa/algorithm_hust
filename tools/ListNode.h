//
// Created by lhq46 on 2019/3/29.
//

#ifndef ALGORITHM_LISTNODE_H
#define ALGORITHM_LISTNODE_H

#include "../std.h"

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
}ListNode;

ListNode* array_to_list(vector<int>& array);
void print_list(ListNode* head);
ListNode* ReverseList(ListNode* head);

#endif //ALGORITHM_LISTNODE_H
