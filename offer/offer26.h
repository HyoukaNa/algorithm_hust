//
// Created by Sanfuh on 2019/5/29.
//

#ifndef DEMO_OFFER26_H
#define DEMO_OFFER26_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};

class Offer26 {

public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* head = nullptr;
        RandomListNode* tail = nullptr;

        unordered_map<RandomListNode*,RandomListNode*> umap;

        int count = 0;
        for (RandomListNode* p = pHead; p != nullptr; p = p->next, count++) {

            if(count != 0) {
                RandomListNode* node = new RandomListNode(p->label);
                tail->next = node;
                tail = node;
            } else {
                head = new RandomListNode(pHead->label);
                tail = head;
            }

            umap[p] = tail;
        }

        for (RandomListNode* p = pHead; p != nullptr; p = p->next) {

            RandomListNode* pNew = umap[p];

            pNew->random = umap[p->random];
        }

        return head;
    }

    void run() {

    }

};

#endif //DEMO_OFFER26_H
