//
// Created by lhq on 2019/7/18.
//

#ifndef ALGORITHM_LEETCODE208_H
#define ALGORITHM_LEETCODE208_H

#include <string>
#include <queue>

using namespace std;

typedef struct TrieNode {
    char var;
    bool end;
    struct TrieNode* right;
    struct TrieNode* child;
    TrieNode(char ch) : var(ch), end(false), right(nullptr), child(nullptr){}
} TrieNode;

class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('0');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        TrieNode* dummy = root;
        for (int i = 0; i < word.size(); ++i) {
            TrieNode* p = nullptr;
            for(p = dummy->child; p != nullptr; p = p->right) {
                if(p->var == word[i]) {
                    dummy = p;
                    break;
                }
            }
            if(p) {
                if(i == word.size() - 1)
                    p->end = true;
                continue;
            }

            p = new TrieNode(word[i]);
            if(i == word.size() - 1)
                p->end = true;
            p->right = dummy->child;
            dummy->child = p;
            dummy = p;
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        TrieNode* dummy = root;
        TrieNode* p = nullptr;
        for (int i = 0; i < word.size(); ++i) {
            cout << "find " << word[i] << " in ";
            for(p = dummy->child; p != nullptr; p = p->right) {
                cout << p->var << "  ";
                if(p->var == word[i]) {
                    dummy = p;
                    break;
                }
            }
            cout << endl;
            if(!p) {
                cout << word[i] << endl;

                return false;
            }

        }

        cout << word << " " << p->child << endl;

        return p->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        TrieNode* dummy = root;
        TrieNode* p = nullptr;
        for (int i = 0; i < prefix.size(); ++i) {
            for(p = dummy->child; p != nullptr; p = p->right) {
                cout << p->var << "  ";
                if(p->var == prefix[i]) {
                    dummy = p;
                    break;
                }
            }
            if(!p)
                return false;
            }

        return true;
    }

    void print() {

        queue<TrieNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()) {

            int len = q.size();
            cout << "depth " << depth++ << " : ";
            for (int i = 0; i < len; ++i) {
                TrieNode* node = q.front();
                for (TrieNode* j = node->child; j != nullptr ; j=j->right) {
                    cout << j->var << " ";
                    q.push(j);
                }
                cout << " |";
                q.pop();
            }
            cout << endl;
        }
    }
};

class LeetCode208 {
public:
    void run() {
        Trie* obj = new Trie();
        bool ans = obj->search("a");
        cout << (ans?"true":"false") << endl;
//        obj->insert("apple");
//        obj->insert("app");
//        obj->print();
//        bool p1 = obj->search("apple");
//        bool p2 = obj->search("app");
//        cout << "search apple " << (p1?"true":"false") << endl;
//        cout << "search app " << (p2?"true":"false") << endl;


    }


};
#endif //ALGORITHM_LEETCODE208_H
