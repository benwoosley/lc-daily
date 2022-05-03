#include <iostream>
#include <stack>
#include <vector>

/* DFS using stack to find connected vertices in the graph */
std::vector<int> getConnComb(std::vector<std::vector<int> >& graph, std::vector<bool>& visit, int u)
{
    std::vector<int> cmb;
    std::stack<int> S;
    S.push(u);
    visit[u] = true;
    cmb.push_back(u);
    while (!S.empty())
    {
        int uu = S.top();
        S.pop();
        for (auto v : graph[uu])
        {
            if (visit[v] == false)
            {
                visit[v] = true;
                S.push(v);
                cmb.push_back(v);
            }
        }
    }
    return cmb;
}

class Solution
{
public:
    /* Consider each char position in the string as a vertex and pairs as edges of the graphs
     *  1. Built the graph from char positions (as vertices) and pairs (as edges)
     *  2. Find all Connected Components
     *  3. Sort chars among connected components and merge to create final output string
     *  (why because, if you look closely at the connected components, pairs exists such way that
     *   there exists a set of swaps using pairs for swapping any 2 chars on the component,
     *   so we can just sort all chars among the connected for getting the lexicographically
     *   smaller one)
     */
    std::string smallestStringWithSwaps(std::string s, std::vector<std::vector<int> >& pairs)
    {
        int V = s.size();
        std::vector<std::vector<int> > graph(V);
        for (auto p : pairs)
        {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        std::vector<bool> visit(V, false);
        std::vector<std::vector<int> > ConnCombs;
        /* finding connected components */
        for (int u = 0; u < V; u++)
        {
            if (visit[u] == false)
            {
                std::vector<int> comb = getConnComb(graph, visit, u);
                ConnCombs.push_back(comb);
            }
        }
        /* Building output string from Computed connected components */
        std::string output(s.size(), ' ');
        for (auto &combPos : ConnCombs)
        {
            std::vector<char> combChars;
            for (auto pos : combPos)
            {
                combChars.push_back(s[pos]);
            }
            sort(combPos.begin(), combPos.end());
            sort(combChars.begin(), combChars.end());
            for (int i = 0; i < combPos.size(); i++)
            {
                output[combPos[i]] = combChars[i];
            }
        }
        return output;
    }
};

std::vector<std::vector<int> > create_pairs()
{
    std::vector<std::vector<int> > ret_val;
    std::vector<int> pair_1;
    std::vector<int> pair_2;
    std::vector<int> pair_3;
    pair_1.push_back(0);
    pair_1.push_back(3);
    pair_2.push_back(1);
    pair_2.push_back(2);
    pair_3.push_back(0);
    pair_3.push_back(2);
    ret_val.push_back(pair_1);
    ret_val.push_back(pair_2);
    ret_val.push_back(pair_3);
    return ret_val;
}

int main(int argc, char *argv[])
{
    Solution sol;
    std::string s = "dcab";
    std::vector<std::vector<int> > pairs = create_pairs();
    std::cout << sol.smallestStringWithSwaps(s, pairs) << std::endl;
    return 0;
}
