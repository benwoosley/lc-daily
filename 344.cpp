#include <iostream>
#include <vector>

class Solution
{
public:
    void reverseString(std::vector<char>& s)
    {
        std::reverse(s.begin(), s.end());
    }
};


std::vector<char> create_vector()
{
    std::vector<char> vec;
    vec.push_back('h');
    vec.push_back('e');
    vec.push_back('l');
    vec.push_back('l');
    vec.push_back('o');
    return vec;
}

template <typename T>
void print_vector(std::vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    Solution s;
    std::vector<char> test = create_vector();
    print_vector(test);
    s.reverseString(test);
    print_vector(test);
    return 0;
}
