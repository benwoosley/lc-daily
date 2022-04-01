#include <iostream>
#include <vector>
#include <map>

class Solution
{
public:
    //FIXME: Finish
    int splitArray(std::vector<int>& nums, int m)
    {
        return -1;
    }
};



int main(int argc, char *argv[])
{
    std::vector<int>nums;
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(8);

    int m = 2;

    Solution s;
    std::cout << s.splitArray(nums, m) << std::endl;
    return 0;
}
