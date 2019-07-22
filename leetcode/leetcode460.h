//
// Created by lhq on 2019/7/22.
//

#ifndef ALGORITHM_LEETCODE460_H
#define ALGORITHM_LEETCODE460_H

#include <vector>
#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

struct LFUNode {
    int key;
    int var;
    int used;
    struct LFUNode* prev;
    struct LFUNode* next;
    LFUNode(int key, int var) : key(key), var(var), used(1), prev(nullptr), next(nullptr) {}
};

struct LFUFre {
    int fre;
    list<LFUNode> list;

    LFUFre(int f) : fre(f) {}
};

class LFUCache {
private:
    LFUNode* dummy;
    unordered_map<int, LFUNode*> lfu;
    unordered_map<int, LFUFre*> LFUFre;
    unordered_map<int, int> used_count;
    int size;
    int capacity;

public:
    LFUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        dummy = new LFUNode(-1, -1);
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    int get(int key) {

        if(lfu.find(key) == lfu.end()) {
            return -1;
        }

        LFUNode* node = lfu[key];
        node->used++;
        node->prev->next = node->next;
        node->next->prev = node->prev;

        LFUNode* more_used_node;
        for (more_used_node = node->prev; more_used_node != dummy && more_used_node->used <= node->used;
            more_used_node = more_used_node->prev) ;

        more_used_node->next->prev = node;
        node->next = more_used_node->next;
        node->prev = more_used_node;
        more_used_node->next = node;

        return lfu[key]->var;
    }

    void put(int key, int value) {

        if(get(key) != -1) {
            lfu[key]->var = value;
            return ;
        }

        if( this->capacity <= 0)
            return ;

        if(this->size == this->capacity) {
            LFUNode* lfu_node = dummy->prev;
            lfu_node->prev->next = dummy;
            dummy->prev = lfu_node->prev;
            lfu.erase(lfu_node->key);
            delete lfu_node;
        }
        this->size++;

        LFUNode* node = new LFUNode(key,value);
        lfu[key] = node;
        LFUNode* more_used_node;
        for (more_used_node = dummy->prev; more_used_node != dummy && more_used_node->used <= node->used;
             more_used_node = more_used_node->prev) ;

        more_used_node->next->prev = node;
        node->next = more_used_node->next;
        node->prev = more_used_node;
        more_used_node->next = node;
    }

    void update_frequency(int key, int value) {

    }

    void print() {
        for (LFUNode* node = dummy->next; node != dummy ; node = node->next) {
            cout << "(" << node->key << "," << node->var << "):" << node->used << " ";
        }
        cout << endl;
    }
};

class LeetCode460 {
public:
    void run() {
        LFUCache* obj = new LFUCache(2);

//        obj->print();
//        obj->put(1,1);
//        obj->print();
//        obj->put(2,2);
//        obj->print();
//        cout << obj->get(1) << endl;
//        obj->print();

        obj->put(1,1);obj->print();
        obj->put(2,2);obj->print();
        cout << obj->get(1) << " ";obj->print();
        obj->put(3,3);obj->print();
        cout << obj->get(2) << " ";obj->print();
        cout << obj->get(3) << " ";obj->print();
        obj->put(4,4);obj->print();
        cout << obj->get(1) << " ";obj->print();
        cout << obj->get(3) << " ";obj->print();
        cout << obj->get(4) << " ";obj->print();
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#endif //ALGORITHM_LEETCODE460_H
