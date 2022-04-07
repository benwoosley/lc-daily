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
void print_list(ListNode* head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " --> ";
        head = head->next;
    }
    std::cout << std::endl;
}
ListNode* push_front(ListNode* head, ListNode* new_node)
{
    new_node->next = head;
    return new_node;
}
ListNode* pop_back(ListNode* head)
{
    ListNode* node_popped = nullptr;
    while (head->next->next != nullptr)
    {
        head = head->next;
    }
    ListNode* temp = head->next;
    head->next = nullptr;
    return temp;
}
int get_length(ListNode* head)
{
    int count = 0;
    while (head != nullptr)
    {
        count++;
        head = head->next;
    }
    return count;
}
class Solution
{
public:
    //FIXME: TLE
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head || get_length(head) <= 1)
        {
            return head;
        }
        for (int i = 0; i < k; i++)
        {
            head = push_front(head, pop_back(head));
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
int main(int argc, char *argv[])
{
    Solution s;
    ListNode* head = create_list(create_vector());
    print_list(head);
    head = s.rotateRight(head, 2000000000);
    print_list(head);
    return 0;
}
