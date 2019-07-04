//
// Created by lhq on 2019/7/4.
//

#ifndef ALGORITHM_LEETCODE148_H
#define ALGORITHM_LEETCODE148_H


#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <bitset>
#include "../tools/print.h"
#include "../tools/ListNode.h"

// O(nlogn) S(1)

class LeetCode148 {
public:
    ListNode* sortList(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;

        int length = 0;
        for (ListNode* p = head; p != nullptr ; p=p->next) {
            length++;
        }

        for (int step = 1; step < length; step = step << 1) {

            ListNode* current = dummy.next;
            ListNode* tail = &dummy;

            while(current) {
                ListNode* left = current;
                ListNode* right = split(left, step);
                current = split(right, step);

                cout << "left ";
                print_list(left);
                cout << "right ";
                print_list(right);
                cout << "current ";
                print_list(current);


                tail->next = merge(left,right);
                while(tail->next) {
                    tail = tail->next;
                }
            }
        }

        return dummy.next;
    }

    // o(max(n1 + n2))
    ListNode* merge(ListNode* l1, ListNode* l2) {

        ListNode head_node(0);
        ListNode* head = &head_node;
        ListNode* current = head;

        while(l1 != nullptr && l2 != nullptr) {

            if(l1->val <= l2->val) {
                current->next = l1;
                current = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                current = l2;
                l2 = l2->next;
            }

        }

        current->next = l1?l1:l2;
        return head->next;
    }

    ListNode* split(ListNode* list, int length) {

        ListNode node(0);
        ListNode* dummy = &node;
        dummy->next = list;

        ListNode* prev = dummy;
        ListNode* right = list;

        for (int i = 0; i < length && right != nullptr; ++i) {
            prev = prev->next;
            right = right->next;
        }

        prev->next = nullptr;
        return right;
    }

    void run() {

        vector<int> old_array = {8,5,4,6,1,7,3,2,9};
        ListNode* old_list = array_to_list(old_array);
        print_list(old_list);

        ListNode* new_list = sortList(old_list);
        print_list(new_list);
    }
};

#endif //ALGORITHM_LEETCODE148_H
