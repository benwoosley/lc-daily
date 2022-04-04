#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
};

int get_length(ListNode* head)
{
    int count = 1;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}
class Solution
{
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        // O(n)
        int length = 1;
        ListNode* itr = head;
        while (itr)
        {
            length++;
            itr = itr->next;
        }
        // O(n)
        itr = head;
        int count = 0;
        ListNode* a = nullptr;
        ListNode* b = nullptr;
        while (itr != nullptr)
        {
            count++;
            if (count == k)
            {
                a = itr;
            }
            else if (k + count == length)
            {
                b = itr;
            }
            itr = itr->next;
        }
        if (a != nullptr && b != nullptr)
        {
            int temp = a->val;
            a->val = b->val;
            b->val = temp;
        }
        // O(n + n) = O(n)
        return head;
    }
};
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
    {
        push_back(head, vec[i]);
    }
    return head;
}
void print_list(ListNode* head)
{
    ListNode* itr = head;
    while (itr != nullptr)
    {
        std::cout << itr->val << " --> ";
        itr = itr->next;
    }
    std::cout << std::endl;
}

std::vector<int> create_vector()
{
    std::vector<int> return_val;
    /*
    return_val.push_back(7);
    return_val.push_back(9);
    return_val.push_back(6);
    return_val.push_back(6);
    return_val.push_back(7);
    return_val.push_back(8);
    return_val.push_back(3);
    return_val.push_back(0);
    return_val.push_back(9);
    return_val.push_back(5);
    */
    return_val.push_back(1);
    return_val.push_back(2);
    return_val.push_back(3);
    return_val.push_back(4);
    return_val.push_back(5);
    return return_val;
}
int main(int argc, char *argv[])
{
    Solution s;
    ListNode* head = create_list(create_vector());
    print_list(head);
    s.swapNodes(head, 2);
    print_list(head);
    return 0;
}
