#include <iostream>
#include <vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void push_front(ListNode* head)
{
    return;
}

ListNode* pop_back(ListNode* head)
{
    ListNode* node_popped = nullptr;
    return node_popped;
}

class Solution
{
public:
    //FIXME: 1
    ListNode* rotateRight(ListNode* head, int k)
    {
        for (int i = 0; i < k; i++)
        {
            push_front(pop_back(head));
        }
        return head;
    }
};
std::vector<int> create_vector()
{
    std::vector<int> return_value;
    return_value.push_back(1);
    return_value.push_back(2);
    return_value.push_back(3);
    return_value.push_back(4);
    return_value.push_back(5);
    return return_value;
}
void push_back(ListNode* head, int val)
{
    while (head->next != nullptr)
    {
        head = head->next;
    }
    head->next = new ListNode(val);
}
ListNode* create_list(std::vector<int> vec)
{
    ListNode* head = new ListNode(vec[0]);
    for (int i = 1; i < vec.size(); i++)
        push_back(head, vec[i]);
    return head;
}
void print_list(ListNode* head)
{
    while (head != nullptr)
    {
        std::cout << head->val << "-->";
        head = head->next;
    }
    std::cout << std::endl;
}
int main(int argc, char *argv[])
{
    Solution s;
    ListNode* head = create_list(create_vector());
    print_list(head);
    s.rotateRight(head, 2);
    return 0;
}
