#include "treenode.h"
#include "vectorstuff.h"

class Solution
{
public:
    void recoverTree(TreeNode* root)
    {
        std::vector<TreeNode*> values = inorder(root);
        std::vector<int> sort_values;
        for (int i = 0; i < values.size(); i++)
        {
            sort_values.push_back(values[i]->val);
        }
        sort(sort_values.begin(), sort_values.end());
        for (int i = 0; i < values.size(); i++)
        {
            if (values[i]->val != sort_values[i])
            {
                values[i]->val = sort_values[i];
            }
        }
    }
};

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3};
    TreeNode* root = create_tree(create_vector(arr, 3));
    swap_nodes(tree_search(root, 3), tree_search(root, 1));
    print_traversal(inorder(root));
    Solution s;
    s.recoverTree(root);
    print_traversal(inorder(root));
    return 0;
}
