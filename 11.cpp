#include <iostream>
#include <vector>

class Solution
{
public:
    //TODO: finish this
    int maxArea(std::vector<int>& height)
    {
        return -1;
    }
};
std::vector<int> create_vector()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(8);
    vec.push_back(6);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(3);
    vec.push_back(7);
    return vec;
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
    Solution s;
    std::vector<int> height = create_vector();
    print_vector(height);
    std::cout << s.maxArea(height) << std::endl;
    return 0;
}
