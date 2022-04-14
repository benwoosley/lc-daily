#include <iostream>
#include <pthread.h>
#include <vector>
void print_board(std::vector<std::vector<int> > board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void need_to_swap(int num_neighbors, bool is_live, std::vector<std::string> &swap_list, int i, int j)
{
    if (is_live)
    {
        if (num_neighbors < 2)
        {
            swap_list.push_back(std::to_string(i) + std::to_string(j));
        }
        else if (num_neighbors == 2 || num_neighbors == 3)
        {
            return;
        }
        else
        {
            swap_list.push_back(std::to_string(i) + std::to_string(j));
        }
    }
    else
    {
        if (num_neighbors == 3)
        {
            swap_list.push_back(std::to_string(i) + std::to_string(j));
        }
    }
}
// FIXME: treat out of bounds cells as 0
// TODO: complete this
class Solution
{
public:
    void gameOfLife(std::vector<std::vector<int> >& board)
    {
        int m = board.size();
        int n = board[0].size();
        int num_neighbors = 0;
        std::vector<std::string> to_change;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                num_neighbors = 0;
                if (i == 0)
                {
                    // top left
                    if (j == 0)
                    {
                        num_neighbors += board[i + 1][j] + board[i][j + 1] +  board[i + 1][j + 1];
                        need_to_swap(num_neighbors, board[i][j], to_change, i, j);
                    }
                    // top right
                    else if (j == n - 1)
                    {
                        num_neighbors += board[i][j - 1] + board[i + 1][j - 1] + board[i + 1][j];
                        need_to_swap(num_neighbors, board[i][j], to_change, i, j);
                    }
                    // top mid
                    else
                    {
                        num_neighbors += board[i][j - 1] + board[i][j + 1] + board[i + 1][j - 1] + board[i + 1][j] + board[i + 1][j + 1];
                        need_to_swap(num_neighbors, board[i][j], to_change, i, j);
                    }
                }
                // end
                else if (i == m - 1)
                {
                    // end left
                    if (j == 0)
                    {
                        num_neighbors += board[i - 1][j] + board[i - 1][j + 1] + board[i][j + 1];
                        need_to_swap(num_neighbors, board[i][j], to_change, i, j);
                    }
                    // end right
                    else if (j == n - 1)
                    {
                        num_neighbors = board[i][j - 1] + board[i - 1][j - 1] + board[i - 1][j];
                        need_to_swap(num_neighbors, board[i][j], to_change, i, j);
                    }
                    // end mid
                    else
                    {
                        num_neighbors = board[i][j - 1] + board[i - 1][j - 1] + board[i - 1][j] + board[i - 1][j + 1] + board[i][j + 1];
                        need_to_swap(num_neighbors, board[i][j], to_change, i, j);
                    }
                }
                // mid
                else
                {
                    // mid left
                    if (j == 0)
                    {
                        num_neighbors = board[i - 1][j] + board[i - 1][j + 1] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j];
                        need_to_swap(num_neighbors, board[i][j], to_change, i, j);
                    }
                    // mid right
                    else if (j == n - 1)
                    {
                        num_neighbors = board[i - 1][j] + board[i - 1][j - 1] + board[i][j - 1] + board[i + 1][j - 1] + board[i + 1][j];
                        need_to_swap(num_neighbors, board[i][j], to_change, i, j);
                    }
                    // mid mid
                    else
                    {
                        num_neighbors = board[i - 1][j] + board[i - 1][j - 1] + board[i][j - 1] + board[i + 1][j - 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i][j + 1] + board[i - 1][j + 1];
                        need_to_swap(num_neighbors, board[i][j], to_change, i, j);
                    }
                }
            }
        }
        // iterate through vector
        for (int i = 0; i < to_change.size(); i++)
        {
            int arr_i = to_change[i][0] - '0';
            int arr_j = to_change[i][1] - '0';
            board[arr_i][arr_j] = !board[arr_i][arr_j];
        }
    }
};

std::vector<std::vector<int> > create_board()
{
    std::vector<std::vector<int> > board;
    std::vector<int> row_1;
    row_1.push_back(0);
    row_1.push_back(1);
    row_1.push_back(0);
    std::vector<int> row_2;
    row_2.push_back(0);
    row_2.push_back(0);
    row_2.push_back(1);
    std::vector<int> row_3;
    row_3.push_back(1);
    row_3.push_back(1);
    row_3.push_back(1);
    std::vector<int> row_4;
    row_4.push_back(0);
    row_4.push_back(0);
    row_4.push_back(0);
    board.push_back(row_1);
    board.push_back(row_2);
    board.push_back(row_3);
    board.push_back(row_4);
    return board;
}
int main(int argc, char *argv[])
{
    std::vector<std::vector<int> > board = create_board();
    Solution s;
    s.gameOfLife(board);
    print_board(board);
    return 0;
}
