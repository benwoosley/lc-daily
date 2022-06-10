#include <iostream>
#include <string.h>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        return -1;
    }
};

int main()
{
    Solution sol;
    std::string val = "abcabcbb";
    std::cout << sol.lengthOfLongestSubstring(val) << std::endl;
    return 0;
}
