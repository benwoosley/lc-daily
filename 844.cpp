#include <string>
#include <iostream>
#include <vector>
#include <stack>

// STACK
std::stack<char> parse_string(std::string s)
{
    std::stack<char> stack;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#' && !stack.empty())
            stack.pop();
        else if (s[i] != '#')
            stack.push(s[i]);
    }
    return stack;
}
class Solution
{
public:
    bool backspaceCompare(std::string s, std::string t)
    {
        std::stack<char> s_stack = parse_string(s);
        std::stack<char> t_stack = parse_string(t);
        return s_stack == t_stack;
    }
};

int main(int argc, char *argv[])
{
    std::string s;
    std::string t;
    std::cin >> s;
    std::cin >> t;
    Solution sol;
    std::cout << sol.backspaceCompare(s, t) << std::endl;
    return 0;
}
