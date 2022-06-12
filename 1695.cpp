#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    /*
     * Keep a frequency map of the numbers in the window
     * while the count of the latest number in the window is greater than 1, shrink the window
     * record the best answer
     */
    int maximumUniqueSubarray(std::vector<int>& nums)
    {
        int n = nums.size();
        int L = 0;
        int R = 0;

        std::unordered_map<int, int> freqMap;
        int sum = 0;
        int ans = 0;
        while (R < n)
        {
            int right = nums[R++];
            sum += right;
            freqMap[right]++;
            while (freqMap[right] > 1)
            {
                int left = nums[L++];
                freqMap[left]--;
                sum -= left;
            }
            ans = std::max(ans, sum);
        }
        return ans;
    }
};

std::vector<int> create_vector()
{
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    return vec;
}

int main(int argc, char *argv[])
{
    Solution sol;
    std::vector<int> nums = create_vector();
    sol.maximumUniqueSubarray(nums);
    return 0;
}
