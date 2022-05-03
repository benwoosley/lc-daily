#include <iostream>
#include <string>
#include <map>
#include <time.h>

class Solution
{
public:
    // Encodes a URL to a shortened URL.
    std::map<std::string, std::string> m;
    std::map<std::string, std::string> n;
    std::string encode(std::string longUrl)
    {
        srand (time(NULL));
        std::string shortUrl = "http://tinyurl.com/" + longUrl.substr(0, 4) + std::to_string(rand() % 1000);
        m[longUrl] = shortUrl;
        n[shortUrl] = longUrl;
        return m[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    std::string decode(std::string shortUrl)
    {
        return n[shortUrl];
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    std::string val = s.encode("asdfasdf");
    std::cout << val << std::endl;
    std::cout << s.decode(val) << std::endl;
    return 0;
}
