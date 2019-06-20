//
// Created by lhq46 on 2019/3/29.
//

#ifndef ALGORITHM_TREENODE_H
#define ALGORITHM_TREENODE_H

#include "../std.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorder_traversal(TreeNode* root);
vector<int> inorder_traversal(TreeNode* root);
vector<int> postorder_traversal(TreeNode* root);

TreeNode* getSampleTree();

void delByRoot(TreeNode* root);

#endif //ALGORITHM_TREENODE_H
