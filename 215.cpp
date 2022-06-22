#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return nums[k - 1];
    }
};

vector<int> create_vector()
{
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(4);
    return vec;
}

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> vec = create_vector();
    std::cout << sol.findKthLargest(vec, 2) << std::endl;
    return 0;
}
