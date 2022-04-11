#include <iostream>
#include <vector>
class Solution
{
public:
    std::vector<std::vector<int> > shiftGrid(std::vector<std::vector<int> >& grid, int k)
    {
        if (k == 0)
            return grid;
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int> > vec;
        for (int i = 0; i < m; i++)
        {
            std::vector<int> row;
            if (i > 0)
            {
                row.push_back(grid[i - 1][n - 1]);
            }
            else
            {
                row.push_back(grid[m - 1][n - 1]);
            }
            for (int j = 0; j < n - 1; j++)
            {
                row.push_back(grid[i][j]);
            }
            vec.push_back(row);
        }
        return shiftGrid(vec, k - 1);
    }
};
std::vector<std::vector<int> > create_grid()
{
    std::vector<std::vector<int> > vec;
    std::vector<int> row_1;
    row_1.push_back(1);
    row_1.push_back(2);
    row_1.push_back(3);
    std::vector<int> row_2;
    row_2.push_back(4);
    row_2.push_back(5);
    row_2.push_back(6);
    std::vector<int> row_3;
    row_3.push_back(7);
    row_3.push_back(8);
    row_3.push_back(9);
    vec.push_back(row_1);
    vec.push_back(row_2);
    vec.push_back(row_3);
    return vec;
}
void print_grid(std::vector<std::vector<int> > grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j  = 0; j < grid[i].size(); j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
int main(int argc, char *argv[])
{
    std::vector<std::vector<int> > grid = create_grid();
    return 0;
}
