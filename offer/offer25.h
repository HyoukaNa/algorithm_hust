//
// Created by Sanfuh on 2019/5/29.
//

#ifndef DEMO_OFFER25_H
#define DEMO_OFFER25_H

#include <iostream>
#include <vector>
#include <algorithm>
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

class Offer25 {

public:

    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {

        vector<vector<int>> ans;
        vector<int> path;
        int currentSum = 0;

        if(root == nullptr) {
            return ans;
        }

        findPath(root, expectNumber, ans, path, currentSum);

        sort(ans.begin(), ans.end(), [](const vector<int> &vec1, const vector<int> &vec2)
        {
            if (vec1.size() < vec2.size())
            {
                return true;
            } else
                return false;
        }   );

        return ans;
    }

    void findPath(TreeNode* node,const int& expectNumber, vector<vector<int>>& ans, vector<int>& path, int& currentSum) {

        currentSum += node->val;
        path.push_back(node->val);

        if(node->left == nullptr && node->right == nullptr) {
            if( currentSum == expectNumber) {
                ans.push_back(path);
            }
        }

        if(node->left != nullptr) {
            findPath(node->left, expectNumber, ans, path, currentSum);
        }

        if(node->right != nullptr) {
            findPath(node->right, expectNumber, ans, path, currentSum);
        }

        currentSum -= node->val;
        path.pop_back();

        return ;
    }

    void run() {

        TreeNode* root = new TreeNode(10);

        TreeNode* sub_1 = new TreeNode(5);
        TreeNode* sub_2 = new TreeNode(12);

        TreeNode* sub_11 = new TreeNode(4);
        TreeNode* sub_12 = new TreeNode(7);

        root->left = sub_1;
        root->right = sub_2;

        sub_1->left = sub_11;
        sub_1->right = sub_12;

        vector<vector<int>> ans;
        ans = FindPath(root, 22);

        for (int i = 0; i < ans.size(); ++i) {
            print(ans[i]);
        }

    }
};

#endif //DEMO_OFFER25_H
