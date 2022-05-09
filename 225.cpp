#include <iostream>
#include <queue>

class MyStack
{
public:
    std::queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        std::queue<int> newQueue;
        int curr = q.front();
        int ret_val = q.back();
        while (curr != ret_val)
        {
            newQueue.push(curr);
            q.pop();
            curr = q.front();
        }
        q = newQueue;
        return curr;
    }

    int top()
    {
        return q.back();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main(int argc, char *argv[])
{
    MyStack* myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    std::cout << myStack->top() << std::endl; // return 2
    std::cout << myStack->pop() << std::endl; // return 2
    std::cout << myStack->empty() << std::endl; // return False
    return 0;
}
