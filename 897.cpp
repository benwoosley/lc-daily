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

void insert_node(TreeNode* root, int val)
{
    if (val < root->val)
    {
        if (root->left)
        {
            insert_node(root->left, val);
        }
        else
        {
            root->left = new TreeNode(val);
        }
    }
    if (val > root->val)
    {
        if (root->right)
        {
            insert_node(root->right, val);
        }
        else
        {
            root->left = new TreeNode(val);
        }
    }
}

TreeNode* create_tree(std::vector<int> vec)
{
    TreeNode* root = new TreeNode(vec[0]);
    for (int i = 1; i < vec.size(); i++)
    {
        insert_node(root, vec[i]);
    }
    return root;
}

std::vector<int> create_vector()
{
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);
    vec.push_back(7);
    vec.push_back(9);
    return vec;
}

std::vector<TreeNode*> in_order_traversal(TreeNode* root)
{
    std::vector<TreeNode*> nodes;
    if (root->left)
    {
        std::vector<TreeNode*> left_vec = in_order_traversal(root->left);
        for (int i = 0; i < left_vec.size(); i++)
        {
            nodes.push_back(left_vec[i]);
        }
    }
    nodes.push_back(root);
    if (root->right)
    {
        std::vector<TreeNode*> right_vec = in_order_traversal(root->right);
        for (int i = 0; i < right_vec.size(); i++)
        {
            nodes.push_back(right_vec[i]);
        }
    }
    return nodes;
}

class Solution
{
public:
    TreeNode* increasingBST(TreeNode* root)
    {
        if (!root)
        {
            return root;
        }
        std::vector<TreeNode*> nodes = in_order_traversal(root);
        for (int i = 0; i < nodes.size() - 1; i++)
        {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
        nodes[nodes.size() - 1]->left = nullptr;
        root = nodes[0];
        return root;
    }
};

int main(int argc, char *argv[])
{
    TreeNode* root = create_tree(create_vector());
    Solution s;
    s.increasingBST(root);
    return 0;
}
