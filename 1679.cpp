#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int maxOperations(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> freq;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = k - nums[i];
            if (freq[complement] > 0)
            {
                ans++;
                freq[complement]--;
            }
            else
                freq[nums[i]]++;
        }
        return ans;
    }
};

std::vector<int> create_nums()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    return vec;
}
int main(int argc, char *argv[])
{
    Solution sol;
    std::vector<int> nums = create_nums();
    int k = 5;
    std::cout << sol.maxOperations(nums, k) << std::endl;
    return 0;
}
