#include <iostream>
#include <vector>
class Solution
{
public:
    std::vector<std::vector<int> > generateMatrix(int n)
    {
        std::vector<std::vector<int> > vec;
        return vec;
    }
};

template <typename T>
void print_grid(std::vector<std::vector<T> > grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[])
{
    Solution s;
    print_grid(s.generateMatrix(3));
    return 0;
}
