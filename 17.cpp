#include <vector>
#include <string>
#include <iostream>
#include <map>

template <typename T>
void print_vector(std::vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

std::map<char, std::vector<char> > create_keypad()
{
    std::map<char, std::vector<char> > keypad;
    keypad['2'].push_back('a');
    keypad['2'].push_back('b');
    keypad['2'].push_back('c');
    keypad['3'].push_back('d');
    keypad['3'].push_back('e');
    keypad['3'].push_back('f');
    keypad['4'].push_back('g');
    keypad['4'].push_back('h');
    keypad['4'].push_back('i');
    keypad['5'].push_back('j');
    keypad['5'].push_back('k');
    keypad['5'].push_back('l');
    keypad['6'].push_back('m');
    keypad['6'].push_back('n');
    keypad['6'].push_back('o');
    keypad['7'].push_back('p');
    keypad['7'].push_back('q');
    keypad['7'].push_back('r');
    keypad['7'].push_back('s');
    keypad['8'].push_back('t');
    keypad['8'].push_back('u');
    keypad['8'].push_back('v');
    keypad['9'].push_back('w');
    keypad['9'].push_back('x');
    keypad['9'].push_back('y');
    keypad['9'].push_back('z');
    return keypad;
}

class Solution
{
public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.empty())
            return {};
        std::vector<std::string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> cur(1, "");
        for (auto digit : digits)
        {
            std::string letters = map[digit - '0'];
            std::vector<std::string> next;
            for (auto ch : letters)
                for (auto elem : cur)
                    next.push_back(elem + ch);
            swap(cur, next);
        }
        return cur;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    print_vector(sol.letterCombinations("23"));
    return 0;
}
