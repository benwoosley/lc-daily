#include <iostream>
#include <vector>
class Solution
{
public:
    void nextPermutation(std::vector<int>& nums)
    {
        std::next_permutation(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            std::cout << nums[i] << std::endl;
    }
};

std::vector<int> create_vector()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    return vec;
}

int main(int argc, char *argv[])
{
    std::vector<int> nums = create_vector();
    Solution s;
    s.nextPermutation(nums);
    std::cout << "Hello World!" << std::endl;
    return 0;
}
