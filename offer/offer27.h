//
// Created by Sanfuh on 2019/6/2.
//

#ifndef DEMO_OFFER27_H
#define DEMO_OFFER27_H

#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {
    }
};

using namespace std;

class Offer27 {

public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* head = nullptr;
        TreeNode* tail = nullptr;

        Tree2List(pRootOfTree, &head, &tail);

        return head;
    }

    void Tree2List(TreeNode* node, TreeNode** pHead, TreeNode** pTail) {

        if(node == nullptr) {

            *pHead = nullptr;
            *pTail = nullptr;

        } else if(node->left == nullptr && node->right == nullptr) {

            *pHead = node;
            *pTail = node;

        } else if(node->left != nullptr && node->right == nullptr) {

            TreeNode* head = nullptr;
            TreeNode* tail = nullptr;
            Tree2List(node->left, &head, &tail);

            tail->right = node;
            node->left = tail;

            *pHead = head;
            *pTail = node;

        } else if(node->left == nullptr && node->right != nullptr) {

            TreeNode* head = nullptr;
            TreeNode* tail = nullptr;
            Tree2List(node->right, &head, &tail);

            node->right = head;
            head->left = node;

            *pHead = node;
            *pTail = tail;

        } else {

            TreeNode* lHead = nullptr;
            TreeNode* lTail = nullptr;
            TreeNode* rHead = nullptr;
            TreeNode* rTail = nullptr;
            Tree2List(node->left, &lHead, &lTail);
            Tree2List(node->right, &rHead, &rTail);

            lTail->right = node;
            node->left = lTail;
            node->right = rHead;
            rHead->left = node;

            *pHead = lHead;
            *pTail = rTail;
        }

    }

    void run() {

        TreeNode* root = new TreeNode(10);

        TreeNode* child_l = new TreeNode(6);
        TreeNode* child_r = new TreeNode(14);

        TreeNode* child_ll = new TreeNode(4);
        //TreeNode* child_lr = new TreeNode(8);
        //TreeNode* child_rl = new TreeNode(12);
        TreeNode* child_rr = new TreeNode(16);

        root->left = child_l;
        root->right = child_r;

        child_l->left = child_ll;
        //child_l->right = child_lr;
        //child_r->left = child_rl;
        child_r->right = child_rr;

        cout << "convert start" << endl;
        TreeNode* head = Convert(nullptr);
        cout << "convert finished" << endl;

        TreeNode* p = nullptr;
        TreeNode* q = nullptr;
        cout << "->: ";
        for(p = head; p != nullptr; p = p->right) {
            cout << p->val << " ";
            if(p->right == nullptr) {
                q = p;
            }
        }
        cout << endl;

        cout << "<-: ";
        for(; q != nullptr; q = q->left) {
            cout << q->val << " ";
        }
        cout << endl;

    }

};




#endif //DEMO_OFFER27_H
