#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int>& nums)
    {
        std::vector<int> vec;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            vec.push_back(sum += nums[i]);
        return vec;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
