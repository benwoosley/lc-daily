#include <iostream>
#include <vector>
template <typename T>
void print_vector(std::vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

}
class Solution
{
public:
    int lastStoneWeight(std::vector<int>& stones)
    {
        while (stones.size() > 2)
        {
            sort(stones.begin(), stones.end());
            int x = stones[stones.size() - 2];
            int y = stones[stones.size() - 1];
            if (x == y)
            {
                stones.resize(stones.size() - 2);
            }
            else
            {
                stones[stones.size() - 2] = y - x;
                stones.resize(stones.size() - 1);
            }
        }
        if (stones.size() > 0)
        {
            return stones[0];
        }
        return 0;
    }
};
std::vector<int> create_vector()
{
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(11);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(11);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(11);
    vec.push_back(8);
    vec.push_back(9);
    return vec;
}
int main(int argc, char *argv[])
{
    Solution s;
    std::vector<int> stones = create_vector();
    std::cout << s.lastStoneWeight(stones) << std::endl;
    return 0;
}
