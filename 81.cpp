#include <vector>

class Solution
{
public:
    bool search(std::vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                return true;
            }
        }
        return false;
    }
};
