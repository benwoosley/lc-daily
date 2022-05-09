#include <string>
#include <iostream>
#include <stack>
#include <vector>

/* Maintain a continuous frequency count of items
 * Use a stack, push each element in the stack while maintaining continuous frequency count.
 * If after pushing an element in the stack continuousFreqCount[indexOfLastPushedElement] == k pop stack k times.
 * Finally, all of the elements left in the stack will be combined to form our final solution. Concatenate them into a string and reverse the string for obvious reasons.
 * TC: O(N) because each element will be pushed and popped from the stack only once.
 */
class Solution
{
public:
    std::string removeDuplicates(std::string s, int k)
    {
        int n = s.length();
        std::vector<int> continuousFreqCount(n, 1);
        std::stack<int> st;
        std::string ans;
        st.push(0);
        for (int i = 1; i < n; i++)
        {
            if (!st.empty() && s[st.top()] == s[i])
            {
                continuousFreqCount[i] = continuousFreqCount[st.top()] + 1;
            }
            st.push(i);

            if (continuousFreqCount[st.top()] == k)
            {
                for (int i = 0; i < k; i++)
                {
                    st.pop();
                }
            }
        }
        while (!st.empty())
        {
            ans += s[st.top()];
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    std::cout << sol.removeDuplicates("deeedbbcccbdaa", 3) << std::endl;
    return 0;
}
