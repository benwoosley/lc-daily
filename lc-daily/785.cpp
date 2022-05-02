#include <vector>
#include <iostream>
#include <queue>

/* Bipartite means no two adjacent nodes have same colour.
 * Idea: Color each node with 1 or -1 and if two adjacent nodes have the same color then we simply return false and if we traverse all nodes
 * and not found any two adjacent nodes of the same color then we return true.
 * Here we are using a breadth first search to traverse the graph.
 */
class Solution
{
public:
    bool isBipartite(std::vector<std::vector<int> >& graph)
    {
        int n = graph.size();
        std::vector<int> color(n, 0);
        for (int i = 0; i < n; i++) // traverse each component
        {
            if (color[i]) // if already colored then continue
                continue;
            std::queue<int> q;
            q.push(i);
            color[i] = 1;
            while (!q.empty())
            {
                int parent = q.front();
                q.pop();
                for (int child : graph[parent])
                {
                    if (color[child] == 0)
                    {
                        color[child] = -color[parent];
                        q.push(child);
                    }
                    else
                    {
                        // if parent and child have same colour then return false.
                        if (color[parent] == color[child])
                            return false;
                    }

                }
            }
        }
        return true;
    }
};

std::vector<std::vector<int> > create_graph()
{
    std::vector<std::vector<int> > return_graph;
    std::vector<int> node_0;
    std::vector<int> node_1;
    std::vector<int> node_2;
    std::vector<int> node_3;
    node_0.push_back(1);
    node_0.push_back(2);
    node_0.push_back(3);
    node_1.push_back(0);
    node_1.push_back(2);
    node_2.push_back(0);
    node_2.push_back(1);
    node_2.push_back(3);
    node_3.push_back(0);
    node_3.push_back(2);
    return return_graph;
}


int main(int argc, char *argv[])
{
    Solution sol;
    std::vector<std::vector<int> > graph = create_graph();
    sol.isBipartite(graph);
    return 0;
}
