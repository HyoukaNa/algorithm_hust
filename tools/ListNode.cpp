//
// Created by lhq46 on 2019/3/29.
//

#include "ListNode.h"

ListNode* array_to_list(vector<int>& array) {

    int length = array.size();
    ListNode* head = nullptr;

    for (int i = length - 1; i >= 0 ; i--) {
        ListNode* node = new ListNode(array[i]);
        node->next = head;
        head = node;
    }

    return head;
}

void print_list(ListNode* head) {
    for(;head != nullptr;head = head->next) {
        cout << head->val << " ";
    }
    cout << endl;
}


ListNode* ReverseList(ListNode* pHead) {

    ListNode* pPrev = nullptr;
    ListNode* pNext = pHead;
    while(pNext != nullptr) {
        pNext = pHead->next;
        pHead->next = pPrev;
        pPrev = pHead;
        pHead = pNext;
    }

    return pPrev;

}