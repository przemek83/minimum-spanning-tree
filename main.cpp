// Given social network (graph) with people as nodes with weight being a cost
// of taking over given person account. Task is to find minimum cost to take
// over network. Network is taken over if each person (node) in network has
// taken over account or is connected to minimum one taken over account.

// In
// In first line number of people in social network.
// In following line names and cost of taking over account.
// After that number of connections and connections (one per line).

// Out
// In first line number of people in minimum spinning tree.
// In following lines names.
// In last line sum of weighs for minimum spinning tree

// Example:
// In
// 5
// Robert 12
// Julia 23
// Adam 1
// Carol 10
// Daniel 4
// 5
// Robert Julia
// Robert Carol
// Adam Robert
// Daniel Adam
// Daniel Julia

// Out
// 2
// Adam
// Robert
// 13

#include <limits.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int getMinEdgeIndex(const std::vector<int>& minEdges,
                    const std::vector<bool>& selected)
{
    int minEdge{INT_MAX};
    int minEdgeIndex{-1};

    for (unsigned int i = 0; i < selected.size(); ++i)
        if (!selected[i] && minEdges[i] < minEdge)
        {
            minEdge = minEdges[i];
            minEdgeIndex = i;
        }
    return minEdgeIndex;
}

std::unordered_set<int> findMSTNodes(const std::vector<std::vector<int>>& graph)
{
    const unsigned long size{graph.size()};
    std::unordered_set<int> foundNodes;

    std::vector<int> minEdges(size, INT_MAX);
    minEdges[0] = 0;
    std::vector<bool> selected(size, false);

    for (unsigned long i = 0; i < size; ++i)
    {
        const int u{getMinEdgeIndex(minEdges, selected)};
        selected[u] = true;
        for (unsigned long v = 0; v < size; ++v)
            if (graph[u][v] != 0 && !selected[v] && graph[u][v] < minEdges[v])
            {
                foundNodes.insert(u);
                minEdges[v] = graph[u][v];
            }
    }

    return foundNodes;
}

int main()
{
    std::unordered_map<std::string, int> nodeNamesMap{};

    unsigned int usersCount;
    std::cin >> usersCount;
    std::vector<std::vector<int>> graph(usersCount);
    for (auto& elem : graph)
        elem.resize(usersCount);
    std::vector<int> weights(usersCount);
    for (unsigned int i = 0; i < usersCount; ++i)
    {
        std::string userName;
        unsigned int userHackCost{0};
        std::cin >> userName >> userHackCost;
        nodeNamesMap.insert({userName, i});
        weights[i] = userHackCost;
    }

    unsigned int connectionsCount{0};
    std::cin >> connectionsCount;
    for (unsigned int i = 0; i < connectionsCount; ++i)
    {
        std::string from;
        std::string to;
        std::cin >> from >> to;
        const int fromId{nodeNamesMap.at(from)};
        const int toId{nodeNamesMap.at(to)};
        graph[fromId][toId] = weights[toId];
        graph[toId][fromId] = weights[fromId];
    }

    auto nodes{findMSTNodes(graph)};
    std::cout << nodes.size() << std::endl;
    int sum{0};
    for (auto node : nodes)
    {
        auto it = std::find_if(std::begin(nodeNamesMap), std::end(nodeNamesMap),
                               [&](auto&& p) { return p.second == node; });
        std::cout << it->first << std::endl;
        sum += weights[node];
    }

    std::cout << sum << std::endl;

    return 0;
}
