#include <iostream>
#include <vector>
#include <math.h>

class Solution
{
public:
    int threeSumMulti(std::vector<int>& arr, int target)
    {
        return 12412421 % int(pow(10, 9) + 7);
    }
};
std::vector<int> create_vector()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
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
    std::vector<int> arr = create_vector();
    Solution s;
    print_vector(arr);
    //std::cout << s.threeSumMulti(arr, 0) << std::endl;
    return 0;
}
