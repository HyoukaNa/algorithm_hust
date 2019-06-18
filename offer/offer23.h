//
// Created by Sanfuh on 2019/5/28.
//

#ifndef DEMO_OFFER23_H
#define DEMO_OFFER23_H

#include <iostream>
#include <vector>
#include <queue>
#include "../tools/print.h"

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {
    }
};


class Offer23 {

public:

    vector<int> PrintFromTopToBottom(TreeNode* root) {

        vector<int> ans;

        if(root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int nums = q.size();
            for (int i = 0; i < nums; ++i) {

                TreeNode* treenode = q.front();
                ans.push_back(treenode->val);
                q.pop();

                if(treenode->left != nullptr) {
                    q.push(treenode->left);
                }
                if(treenode->right != nullptr) {
                    q.push(treenode->right);
                }
            }
        }


        print(ans);
        return ans;
    }


    void run() {

        TreeNode* root = new TreeNode(8);

        TreeNode* sub1_1 = new TreeNode(6);
        TreeNode* sub1_2 = new TreeNode(10);

        TreeNode* sub2_1 = new TreeNode(5);
        TreeNode* sub2_2 = new TreeNode(7);
        TreeNode* sub2_3 = new TreeNode(9);
        TreeNode* sub2_4 = new TreeNode(11);

        root->left = sub1_1;
        root->right = sub1_2;

        sub1_1->left = sub2_1;
        sub1_1->right = sub2_2;
        //sub1_2->left = sub2_3;
        sub1_2->right = sub2_4;

        PrintFromTopToBottom(root);

    };



};

#endif //DEMO_OFFER23_H
