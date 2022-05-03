#include <iostream>
#include <vector>


/* Brute Force O(n^3)
 *
 */

class Solution
{
public:
    int findUnsortedSubarray(std::vector<int>& nums)
    {
        int start = nums.size();
        int end = 0;
        if (std::is_sorted(nums.begin(), nums.end()))
        {
            return 0;
        }
        std::vector<int> sorted = nums;
        std::sort(sorted.begin(), sorted.end());
        for (int i = 0; i < sorted.size(); i++)
        {
            if (sorted[i] != nums[i])
            {
                start = std::min(start, i);
                end = std::max(end, i);
            }
        }
        return (end - start >= 0 ? end - start + 1 : 0);
    }
};

std::vector<int> create_vector()
{
    std::vector<int> vec;
    vec.push_back(2);
    vec.push_back(1);
    return vec;
}
int main(int argc, char *argv[])
{
    Solution sol;
    std::vector<int> vec = create_vector();
    std::cout << sol.findUnsortedSubarray(vec) << std::endl;
    return 0;
}
