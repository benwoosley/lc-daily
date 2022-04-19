#pragma once
#include <iostream>
#include <vector>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template <typename T>
void tree_insert(TreeNode* root, T val)
{
    if (val < root->val)
    {
        if (root->left)
            tree_insert(root->left, val);
        else
            root->left = new TreeNode(val);
    }
    if (val > root->val)
    {
        if (root->right)
            tree_insert(root->right, val);
        else
            root->right = new TreeNode(val);
    }
}


template <typename T>
TreeNode* create_tree(std::vector<T> vec)
{
    TreeNode* root = new TreeNode(vec[0]);
    for (int i = 0; i < vec.size(); i++)
    {
        tree_insert(root, vec[i]);
    }
    return root;
}

std::vector<TreeNode*> inorder(TreeNode* root)
{
    std::vector<TreeNode*> values;
    if (root->left)
    {
        std::vector<TreeNode*> left_vec = inorder(root->left);
        for (int i = 0; i < left_vec.size(); i++)
            values.push_back(left_vec[i]);

    }
    values.push_back(root);
    if (root->right)
    {
        std::vector<TreeNode*> right_vec = inorder(root->right);
        for (int i = 0; i < right_vec.size(); i++)
            values.push_back(right_vec[i]);
    }
    return values;
}

void print_traversal(std::vector<TreeNode*> traversal)
{
    for (int i = 0; i < traversal.size(); i++)
    {
        std::cout << traversal[i]->val << " ";
    }
    std::cout << std::endl;
}

TreeNode* tree_search(TreeNode* root, int val)
{
    if (val < root->val)
    {
        if (root->left)
        {
            return tree_search(root->left, val);
        }
        else
        {
            return nullptr;
        }
    }
    if (val > root->val)
    {
        if (root->right)
        {
            return tree_search(root->right, val);
        }
        else
        {
            return nullptr;
        }
    }
    return root;
}

void swap_nodes(TreeNode* node1, TreeNode* node2)
{
    int temp = node1->val;
    node1->val = node2->val;
    node2->val = temp;
}
