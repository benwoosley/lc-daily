#include <iostream>
#include "vectorstuff.h"

class Solution
{
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums)
    {
        std::vector<int> return_vec;
        std::vector<int> odd;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
                return_vec.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 != 0)
                return_vec.push_back(nums[i]);
        }
        return return_vec;
    }
};

int main(int argc, char *argv[])
{
    std::cout << "Hello World!" << std::endl;
    Solution sol;
    int arr[4] = {3, 1, 2, 4};
    std::vector<int> vec = create_vector(arr, 4);
    print_vector(sol.sortArrayByParity(vec));
    return 0;
}
