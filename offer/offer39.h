//
// Created by Sanfuh on 2019/6/13.
//

#ifndef ALGORITHM_OFFER39_H
#define ALGORITHM_OFFER39_H

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

class Offer39 {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == nullptr) {
            return 0;
        }

        int depth = 0;
        queue<TreeNode*> q;
        q.push(pRoot);

        while(!q.empty()) {

            int loop = q.size();
            for (int i = 0; i < loop; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr) {
                    q.push(node->left);
                }
                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }

            depth++;
        }

        return depth;
    }

    void run() {

        TreeNode* root = new TreeNode(0);

        TreeNode* l = new TreeNode(1);
        TreeNode* ll = new TreeNode(2);
        TreeNode* lll = new TreeNode(3);

        root->left = l;
        l->left = ll;
        ll->left = lll;

        cout << TreeDepth(root) << endl;

    }
};

#endif //ALGORITHM_OFFER39_H
