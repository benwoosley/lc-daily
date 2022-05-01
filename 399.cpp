#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>

void dfs_visit(std::map<std::string, std::map<std::string, double> > adj_list, std::string start, std::map<std::string, std::string>& color, std::map<std::string, std::vector<std::string> >& pi)
{
    color[start] = "grey";
    for (std::map<std::string, double>::const_iterator it = adj_list[start].begin(); it != adj_list[start].end(); ++it)
    {
        if (color[it->first] == "white")
        {
            pi[it->first] = pi[start];
            pi[it->first].push_back(start);
            dfs_visit(adj_list, it->first, color, pi);
        }
    }
    color[start] = "black";
}

double dfs(std::map<std::string, std::map<std::string, double> > adj_list, std::string start, std::string end)
{
    std::map<std::string, std::string> color;
    std::map<std::string, std::vector<std::string> > pi;
    for (std::map<std::string, std::map<std::string, double> >::const_iterator it = adj_list.begin(); it != adj_list.end(); ++it)
    {
        color[it->first] = "white";
        std::vector<std::string> vec;
        pi[it->first] = vec;
    }
    int time = 0;
    for (std::map<std::string, std::map<std::string, double> >::const_iterator it = adj_list.begin(); it != adj_list.end(); ++it)
    {
        if (color[it->first] == "white")
        {
            dfs_visit(adj_list, it->first, color, pi);
        }
    }
    double val = 1;
    if (pi[end].size() > 0)
    {
        std::string temp = pi[end][1];
        val *= adj_list[start][temp];
        for (int i = 1; i < pi[end].size() - 1; i++)
        {
            val *= adj_list[temp][pi[end][i]];
            temp = pi[end][i];
        }
        val *= adj_list[pi[end][1]][end];
    }
    else
    {
        val = adj_list[start][end];
    }
    return val;
}

class Solution
{
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string> >& equations, std::vector<double>& values, std::vector<std::vector<std::string> >& queries)
    {
        std::map<std::string, std::map<std::string, double> > adj_list;
        for (int i = 0; i < equations.size(); i++)
        {
            adj_list[equations[i][0]][equations[i][1]] = values[i];
            adj_list[equations[i][1]][equations[i][0]] = pow(values[i], -1);
        }
        std::vector<double> results;
        std::set<std::string> vars;
        for (int i = 0; i < equations.size(); i++)
        {
            vars.insert(equations[i][0]);
            vars.insert(equations[i][1]);
        }
        for (int i = 0; i < queries.size(); i++)
        {
            if (vars.count(queries[i][0]) == 0 || vars.count(queries[i][1]) == 0)
            {
                results.push_back(-1);
            }
            else if (queries[i][0] == queries[i][1])
            {
                results.push_back(1);
            }
            else
            {
                // run DFS and when we have found the node return each edge in the math multiplied together
                results.push_back(dfs(adj_list, queries[i][0], queries[i][1]));
            }
        }
        return results;
    }
};

std::vector<std::vector<std::string> > create_equations()
{
    std::vector<std::vector<std::string> > equations;
    std::vector<std::string> eq_1;
    std::vector<std::string> eq_2;
    eq_1.push_back("a");
    eq_1.push_back("b");
    eq_2.push_back("b");
    eq_2.push_back("c");
    equations.push_back(eq_1);
    equations.push_back(eq_2);
    return equations;
}

std::vector<double> create_values()
{
    std::vector<double> values;
    values.push_back(2.0);
    values.push_back(3.0);
    return values;
}

std::vector<std::vector<std::string> > create_queries()
{
    std::vector<std::vector<std::string> > queries;
    std::vector<std::string> quer_1;
    std::vector<std::string> quer_2;
    std::vector<std::string> quer_3;
    std::vector<std::string> quer_4;
    std::vector<std::string> quer_5;
    quer_1.push_back("a");
    quer_1.push_back("c");
    quer_2.push_back("b");
    quer_2.push_back("a");
    quer_3.push_back("a");
    quer_3.push_back("e");
    quer_4.push_back("a");
    quer_4.push_back("a");
    quer_5.push_back("x");
    quer_5.push_back("x");
    queries.push_back(quer_1);
    queries.push_back(quer_2);
    queries.push_back(quer_3);
    queries.push_back(quer_4);
    queries.push_back(quer_5);
    return queries;
}

template <typename T>
void print_vector(std::vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
int main(int argc, char *argv[])
{
    std::vector<std::vector<std::string> > equations = create_equations();
    std::vector<double> values = create_values();
    std::vector<std::vector<std::string> > queries = create_queries();
    Solution sol;
    print_vector(sol.calcEquation(equations, values, queries));
    return 0;
}
