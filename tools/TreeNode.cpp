//
// Created by lhq46 on 2019/3/29.
//

#include "TreeNode.h"

vector<int> preorder_traversal(TreeNode* root)
{
    stack<TreeNode*> stack;
    stack.push(root);
    vector<int> ans;

    while(stack.size() != 0) {
        TreeNode* _root = stack.top();

        ans.push_back(_root->val);
        stack.pop();

        if(_root->right != nullptr) {
            stack.push(_root->right);
        }
        if(_root->left != nullptr) {
            stack.push(_root->left);
        }
    }
    return ans;
}

vector<int> inorder_traversal(TreeNode* root)
{
    stack<TreeNode*> stack;
    stack.push(root);
    vector<int> ans;
    vector<TreeNode*> junk;

    while(stack.size() != 0) {
        TreeNode* _root = stack.top();
        stack.pop();

        if(_root->right != nullptr) {
            stack.push(_root->right);
        }
        if (_root->left == nullptr && _root->right == nullptr) {
            ans.push_back(_root->val);
        } else {
            TreeNode* node = new TreeNode(_root->val);
            junk.push_back(node);
            stack.push(node);
        }

        if(_root->left != nullptr) {
            stack.push(_root->left);
        }
    }
    for (int i = junk.size() - 1; i >= 0; i--) {
        delete junk[i];
    }

    return ans;
}

vector<int> postorder_traversal(TreeNode* root)
{
    stack<TreeNode*> stack;
    stack.push(root);
    vector<int> ans;
    vector<TreeNode*> junk;

    while(stack.size() != 0) {
        TreeNode* _root = stack.top();
        stack.pop();

        if (_root->left == nullptr && _root->right == nullptr) {
            ans.push_back(_root->val);
        } else {
            TreeNode* node = new TreeNode(_root->val);
            junk.push_back(node);
            stack.push(node);
        }
        if(_root->right != nullptr) {
            stack.push(_root->right);
        }
        if(_root->left != nullptr) {
            stack.push(_root->left);
        }


    }
    for (int i = junk.size() - 1; i >= 0; i--) {
        delete junk[i];
    }

    return ans;
}

void delByRoot(TreeNode* root)
{
    if(root->left != nullptr)
        delByRoot(root->left);
    if(root->right != nullptr)
        delByRoot(root->right);
    delete root;
}

TreeNode* getSampleTree()
{
    /**
     *      1
     *     / \
     *   2     3
     *  / \   / \
     * 4   7 5   6
     *          /
     *         8
     */

    TreeNode* root;

    root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);

    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    root->right->right->left = new TreeNode(8);

    return root;
}