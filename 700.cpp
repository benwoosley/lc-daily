#include <ios>
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
    void insert(int x);
};
class Solution
{
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if (val < root->val)
        {
            if (root->left)
            {
                return searchBST(root->left, val);
            }
            else
            {
                return NULL;
            }
        }
        else if (val > root->val)
        {
            if (root->right)
            {
                return searchBST(root->right, val);
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            return root;
        }
    }
};
void TreeNode::insert(int x)
{
    if (x < this->val)
    {
        if (this->left)
        {
            this->left->insert(x);
        }
        else
        {
            this->left = new TreeNode(x);
        }
    }
    if (x > this->val)
    {
        if (this->right)
        {
            this->right->insert(x);
        }
        else
        {
            this->right = new TreeNode(x);
        }
    }
    else
        return;
}
TreeNode* create_tree(std::vector<int> vec)
{
    TreeNode* head = new TreeNode(vec[0]);
    for (int i = 1; i < vec.size(); i++)
    {
        head->insert(vec[i]);
    }
    return head;
}
std::vector<int> create_vector()
{
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(1);
    vec.push_back(3);
    return vec;
}
std::vector<int> in_order_traversal(TreeNode* head)
{
    std::vector<int> values;
    if (head->left)
    {
        std::vector<int> left_vec = in_order_traversal(head->left);
        for (int i = 0; i < left_vec.size(); i++)
        {
            values.push_back(left_vec[i]);
        }
    }
    values.push_back(head->val);
    if (head->right)
    {
        std::vector<int> right_vec = in_order_traversal(head->right);
        for (int i = 0; i < right_vec.size(); i++)
        {
            values.push_back(right_vec[i]);
        }
    }
    return values;
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
int main(int argc, char *argv[])
{
    TreeNode* head = create_tree(create_vector());
    print_vector(in_order_traversal(head));
    Solution s;
    std::cout << s.searchBST(head, 2)->val << std::endl;
    print_vector(in_order_traversal(s.searchBST(head, 2)));
    return 0;
}
