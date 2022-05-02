#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print_vector(std::vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] <<  ", ";
    }
    std::cout << std::endl;
}

class Solution
{
public:
    int calPoints(std::vector<std::string>& ops)
    {
        std::vector<int> record;
        int sum = 0;
        for (int i = 0; i < ops.size(); i++)
        {
            if (ops[i] == "C")
            {
                record.pop_back();
            }
            else if (ops[i] == "D")
            {
                record.push_back(2 * record[record.size() - 1]);
            }
            else if (ops[i] == "+")
            {
                record.push_back(record[record.size() - 1] + record[record.size() - 2]);
            }
            else
            {
                record.push_back(std::stoi(ops[i]));
            }
        }
        for (int i = 0; i < record.size(); i++)
        {
            sum += record[i];
        }
        print_vector(record);
        return sum;
    }
};

std::vector<std::string> create_vector()
{
    std::vector<std::string> vec;
    vec.push_back("5");
    vec.push_back("2");
    vec.push_back("C");
    vec.push_back("D");
    vec.push_back("+");
    return vec;
}

int main(int argc, char *argv[])
{
    std::vector<std::string> ops = create_vector();
    Solution s;
    std::cout << s.calPoints(ops) << std::endl;
    return 0;
}
