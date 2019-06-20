//
// Created by lhq46 on 2019/6/20.
//

#ifndef ALGORITHM_LEETCODE206_H
#define ALGORITHM_LEETCODE206_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../tools/print.h"
#include "../tools/ListNode.h"

class LeetCode206 {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* current = head;

        ListNode* p = head;
        while(p != nullptr) {

            current = p;
            ListNode* next = p->next;
            p->next = prev;
            prev = current;
            p = next;
        }

        return current;
    }

    void run() {

        vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8};
        ListNode* list = array_to_list(array);
        ListNode* head = reverseList(list);
        print_list(head);

    }
};

#endif //ALGORITHM_LEETCODE206_H
