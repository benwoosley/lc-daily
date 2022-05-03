#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <queue>
#include <tuple>
#include "vectorstuff.h"
#include <limits>

/* Create i nodes with edges pointing to every other points
 * Edge weights should be the distance between the nodes
 * run prim's on this adjacency list
 */

// FIXME: run prim's on the adjacency list
int prims(std::map<int, std::map<int, int> > vec)
{
    std::priority_queue<int, std::vector<int>, std::greater<int> > q;
    int curr_node = 0;
    int sum = 0;
    std::map<int, bool> visited;
    for (int i = 0; i < vec.size(); i++)
    {
        visited[i] = false;
    }
    q.push(vec[curr_node][curr_node]);
    while (!q.empty())
    {
        int min = std::numeric_limits<int>::max();
        int min_index = -1;
        for (int i = 0; i < vec[curr_node].size(); i++)
        {
            if (!visited[i])
            {
                if (vec[curr_node][i] < min && vec[curr_node][i] != 0)
                {
                    min = vec[curr_node][i];
                    min_index = i;
                    q.push(vec[curr_node][min_index]);
                }
            }
        }
        int pop_q = q.top();
        q.pop();
        if (!visited[curr_node] && curr_node != -1)
        {
            sum += pop_q;
        }
        visited[curr_node] = true;
        curr_node = min_index;
    }
    return sum;
}

void print_adj_list(std::map<int, std::map<int, int> > vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << i << std::endl;
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << " " << vec[i][j] << std::endl;
        }
    }
}

class Solution
{
public:
    int minCostConnectPoints(std::vector<std::vector<int> >& points)
    {
        std::map<int, std::map<int, int> > vec;
        for (int i = 0; i < points.size(); i++)
        {
            std::map<int, int> list;
            vec[i] = list;
        }
        // create i nodes with edges O(n^2)
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                vec[i][j] = dist;
                vec[j][i] = dist;
            }
        }
        return prims(vec);
    }
};

std::vector<std::vector<int> > create_points()
{
    std::vector<int> point_1;
    std::vector<int> point_2;
    std::vector<int> point_3;
    std::vector<int> point_4;
    std::vector<int> point_5;
    std::vector<std::vector<int> > ret_val;
    point_1.push_back(0);
    point_1.push_back(0);
    point_2.push_back(2);
    point_2.push_back(2);
    point_3.push_back(3);
    point_3.push_back(10);
    point_4.push_back(5);
    point_4.push_back(2);
    point_5.push_back(7);
    point_5.push_back(0);
    ret_val.push_back(point_1);
    ret_val.push_back(point_2);
    ret_val.push_back(point_3);
    ret_val.push_back(point_4);
    ret_val.push_back(point_5);
    return ret_val;
}

int main(int argc, char *argv[])
{
    Solution s;
    std::vector<std::vector<int> > vec = create_points();
    std::cout << s.minCostConnectPoints(vec) << std::endl;
    return 0;
}
