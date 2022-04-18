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

void insert_node(TreeNode* node, int val)
{
    if (val < node->val)
    {
        if (node->left)
        {
            insert_node(node->left, val);
        }
        else
        {
            node->left = new TreeNode(val);
        }
    }
    if (val > node->val)
    {
        if (node->right)
        {
            insert_node(node->right, val);
        }
        else
        {
            node->right = new TreeNode(val);
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
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(2);
    return vec;
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
void print_vector(std::vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int count = 0;
        std::vector<int> vec = in_order_traversal(root);
        return vec[k - 1];
    }
};

int main(int argc, char *argv[])
{
    TreeNode* root = create_tree(create_vector());
    print_vector(in_order_traversal(root));
    Solution s;
    std::cout << s.kthSmallest(root, 1) << std::endl;
    return 0;
}
