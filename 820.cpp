#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool decreasing(string str, string str2)
{
    if (str.length() > str2.length()) return 1;
    return 0;
}

class Solution
{
public:
    int minimumLengthEncoding(std::vector<std::string>& words)
    {
        int size = words.size();
        if (size == 1)
            return words[0].length() + 1;
        sort(words.begin(), words.end(), decreasing);
        string s = words[0] + "#";
        for (int i = 1; i < size; i++)
        {
            if (s.find(words[i] + "#") == string::npos)
                s += words[i] + "#";
        }
        return s.length();
    }
};

std::vector<std::string> create_vector()
{
    std::vector<std::string> vec;
    vec.push_back("time");
    vec.push_back("me");
    vec.push_back("bell");
    return vec;
}

int main(int argc, char *argv[])
{
    Solution sol;
    std::vector<std::string> words = create_vector();
    std::cout << sol.minimumLengthEncoding(words) << std::endl;
    return 0;
}
