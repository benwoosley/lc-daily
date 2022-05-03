#include <algorithm>
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
class Solution
{
public:
    TreeNode* trimBST(TreeNode* root, int low, int high);
};
void tree_insert(TreeNode* node, int val)
{
    if (val > node->val)
    {
        if (node->right)
        {
            tree_insert(node->right, val);
        }
        else
        {
            node->right = new TreeNode(val);
        }
    }
    if (val < node->val)
    {
        if (node->left)
        {
            tree_insert(node->left, val);
        }
        else
        {
            node->left = new TreeNode(val);
        }
    }
}
TreeNode* create_tree(std::vector<int> vec)
{
    TreeNode* root = new TreeNode(vec[0]);
    for (int i = 0; i < vec.size(); i++)
    {
        tree_insert(root, vec[i]);
    }
    return root;
}
std::vector<int> in_order_traversal(TreeNode* root)
{
    std::vector<int> vec;
    if (root->left)
    {
        std::vector<int> left_vec = in_order_traversal(root->left);
        for (int i = 0; i < left_vec.size(); i++)
        {
            vec.push_back(left_vec[i]);
        }
    }
    vec.push_back(root->val);
    if (root->right)
    {
        std::vector<int> right_vec = in_order_traversal(root->right);
        for (int i = 0; i < right_vec.size(); i++)
        {
            vec.push_back(right_vec[i]);
        }
    }
    return vec;
}
template <typename T>
void print_vec(std::vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
std::vector<int> create_vec()
{
    std::vector<int> val;
    val.push_back(3);
    val.push_back(0);
    val.push_back(4);
    val.push_back(2);
    val.push_back(1);
    return val;
}

TreeNode* Solution::trimBST(TreeNode* root, int low, int high)
{
    if (!root)
    {
        return root;
    }
    if (root->val < low)
    {
        return trimBST(root->right, low, high);
    }
    else if (root->val > high)
    {
        return trimBST(root->left, low, high);
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

int main(int argc, char *argv[])
{
    std::vector<int> vec = create_vec();
    TreeNode* root = create_tree(vec);
    print_vec(in_order_traversal(root));
    Solution s;
    s.trimBST(root, 1, 3);
    print_vec(in_order_traversal(root));
    return 0;
}
