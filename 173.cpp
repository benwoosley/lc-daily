#include "vectorstuff.h"
#include "treenode.h"

class BSTIterator
{
public:
    std::vector<TreeNode*> inorder_nodes;
    int i;
    BSTIterator(TreeNode* root)
    {
        i = 0;
        inorder_nodes = inorder(root);
    }

    int next()
    {
        if (i != 0)
            i++;
        return inorder_nodes[i]->val;
    }

    bool hasNext()
    {
        return (i < inorder_nodes.size());
    }
};


int main(int argc, char *argv[])
{
    int arr[] = {7, 3, 15, 9, 20};
    TreeNode* root = create_tree(create_vector(arr, 5));
    BSTIterator * obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();
    return 0;
}
