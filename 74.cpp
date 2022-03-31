#include <vector>
#include <iostream>
#include <cmath>

class Solution
{
public:
    //FIXME: works, but could be done with a binary search
    bool searchMatrix(std::vector<std::vector<int> >& matrix, int target)
    {
        int n = matrix[0].size();
        int m = matrix.size();

        if (target < matrix[0][0] || target > matrix[m - 1][n - 1])
        {
            return false;
        }
        if (target == matrix[0][0] || target == matrix[m - 1][n - 1])
        {
            return true;
        }


        int col = 0;
        int row = 0;

        while (col < n && row < m)
        {
            // std::cout << matrix[row][col] << std::endl;
            if (matrix[row][col] == target)
            {
                return true;
            }
            if (target > matrix[row][n - 1])
            {
                col = 0;
                row++;
            }
            else
            {
                col++;
            }
        }
        return false;
    }

    bool binarySearchMatrix(std::vector<std::vector<int> >& matrix, int target)
    {
        int n = matrix[0].size();
        int m = matrix.size();

        if (target < matrix[0][0] || target > matrix[m - 1][n - 1])
        {
            return false;
        }
        if (target == matrix[0][0] || target == matrix[m - 1][n - 1])
        {
            return true;
        }
        int col = floor(m / 2);

        std::cout << col << std::endl;

        return false;
    }

};

std::vector<std::vector<int> > create_vector()
{
    std::vector<int> row_1;
    row_1.push_back(1);
    row_1.push_back(3);
    row_1.push_back(5);
    row_1.push_back(7);

    std::vector<int> row_2;
    row_2.push_back(10);
    row_2.push_back(11);
    row_2.push_back(16);
    row_2.push_back(20);

    std::vector<int> row_3;
    row_3.push_back(23);
    row_3.push_back(30);
    row_3.push_back(34);
    row_3.push_back(60);

    std::vector<std::vector<int> > vec;
    vec.push_back(row_1);
    vec.push_back(row_2);
    vec.push_back(row_3);

    return vec;
}
int main()
{
    Solution* s = new  Solution();

    std::vector<std::vector<int> > vec = create_vector();
    std::cout << s->binarySearchMatrix(vec, 3) << std::endl;
    return 0;
}
