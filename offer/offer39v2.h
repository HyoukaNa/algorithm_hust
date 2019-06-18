//
// Created by Sanfuh on 2019/6/13.
//

#ifndef ALGORITHM_OFFER39V2_H
#define ALGORITHM_OFFER39V2_H

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class Offer39v2 {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {

        if(pRoot == nullptr)
            return true;

        bool res = true;
        TreeDepth(pRoot, &res);

        return res;
    }

    int TreeDepth(TreeNode* pRoot, bool* res)
    {
        if(pRoot == nullptr)
            return 0;

        int left = TreeDepth(pRoot->left, res);
        int right = TreeDepth(pRoot->right, res);
        int diff = left - right;

        if(diff > 1 || diff < -1) {
            *res = false;
        }

        return (left > right)?(left + 1):(right + 1);
    }

    void run() {

        TreeNode* root = new TreeNode(0);

        TreeNode* l = new TreeNode(1);
        TreeNode* ll = new TreeNode(2);
        TreeNode* lll = new TreeNode(3);

        root->left = l;
        l->left = ll;
        ll->left = lll;

        cout << (IsBalanced_Solution(root)?"true":"false") << endl;

    }
};

#endif //ALGORITHM_OFFER39V2_H
