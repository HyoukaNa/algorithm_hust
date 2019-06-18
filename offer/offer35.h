//
// Created by Sanfuh on 2019/6/4.
//

#ifndef ALGORITHM_OFFER35_H
#define ALGORITHM_OFFER35_H

#include <iostream>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

struct INFO_LIST {
    char key;
    int index;
    int number;
    bool is_alive;
    struct INFO_LIST* prev;
    struct INFO_LIST* next;
    INFO_LIST(char x, int y, int z) :
        key(x), index(y), number(z),is_alive(true), prev(nullptr), next(nullptr) {
    }
};

class Offer35 {
public:
    int FirstNotRepeatingChar(string str) {

        // LRU
        int ans = -1;

        if(str.size() == 0) {
            return ans;
        }

        unordered_map<char, INFO_LIST*> umap;
        struct INFO_LIST* head = new INFO_LIST('a', -1, -1);
        head->prev = head;
        head->next = head;

        for (int i = 0; i < str.size(); ++i) {
            char key = str[i];
            if(umap.find(key) == umap.end()) {
                INFO_LIST* node = new INFO_LIST(key, i, 1);

                // add node to list tail
                INFO_LIST* prev = head->prev;
                //INFO_LIST* next = head->next;
                prev->next = node;
                node->prev = prev;
                node->next = head;
                head->prev = node;

                umap[key] = node;
            } else {
                INFO_LIST* node = umap[key];

                // delete node from list
                if(node->is_alive == true) {
                    INFO_LIST* prev = node->prev;
                    INFO_LIST* next = node->next;
                    prev->next = next;
                    next->prev = prev;
                }

                node->is_alive = false;
            }
            printlist(head);
        }

        ans = head->next->index;

        return ans;
    }

    void run() {
        cout << FirstNotRepeatingChar("google") << endl;
    }

    void printlist(struct INFO_LIST* head) {

        static int count = 0;

        cout << ++count << " : " ;
        for(INFO_LIST* p = head->next; p != head; p = p->next) {
            cout << p->key << " ";
        }
        cout << endl;
    }
};
#endif //ALGORITHM_OFFER35_H