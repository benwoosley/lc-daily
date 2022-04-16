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

void tree_insert(TreeNode* root, int val)
{
    if (val > root->val)
    {
        if (root->right)
        {
            tree_insert(root->right, val);
        }
        else
        {
            root->right = new TreeNode(val);
        }
    }
    if (val < root->val)
    {
        if (root->left)
        {
            tree_insert(root->left, val);
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
        tree_insert(root, vec[i]);
    }
    return root;
}

std::vector<int> create_vector()
{
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(8);
    return vec;
}

std::vector<TreeNode*> in_order_traversal(TreeNode* root)
{
    std::vector<TreeNode*> values;
    if (root->left)
    {
        std::vector<TreeNode*> left_vec = in_order_traversal(root->left);
        for (int i = 0; i < left_vec.size(); i++)
        {
            values.push_back(left_vec[i]);
        }
    }
    values.push_back(root);
    if (root->right)
    {
        std::vector<TreeNode*> right_vec = in_order_traversal(root->right);
        for (int i = 0; i < right_vec.size(); i++)
        {
            values.push_back(right_vec[i]);
        }
    }
    return values;
}

void print_vector(std::vector<TreeNode*> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i]->val << " ";
    }
    std::cout << std::endl;
}

class Solution
{
public:
    //FIXME: iterate through every node in the tree (BFS or DFS) and subtract every value in that nodes left subree from the sum and update curr->val
    TreeNode* convertBST(TreeNode* root)
    {
        if (!root)
        {
            return root;
        }
        int sum = 0;
        std::vector<TreeNode*> nodes = in_order_traversal(root);
        for (int i = 0; i < nodes.size(); i++)
        {
            sum += nodes[i]->val;
        }
        int previous_val = 0;
        for (int i = 0; i < nodes.size(); i++)
        {
            int temp = nodes[i]->val;
            nodes[i]->val = sum;
            nodes[i]->val -= previous_val;
            previous_val += temp;
        }
        std::cout << sum << std::endl;
        return root;
    }
};

int main(int argc, char *argv[])
{
    TreeNode* root = create_tree(create_vector());
    Solution s;
    s.convertBST(root);
    print_vector(in_order_traversal(root));
    return 0;
}
