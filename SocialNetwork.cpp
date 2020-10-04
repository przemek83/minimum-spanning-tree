#include "SocialNetwork.h"

#include <algorithm>
#include <climits>

SocialNetwork::SocialNetwork(unsigned int peopleCount)
    : graph_(peopleCount), weights_(peopleCount)
{
    for (auto& elem : graph_)
        elem.resize(peopleCount);
}

void SocialNetwork::addPerson(const std::string& personName,
                              unsigned int accountTakenOverCost)
{
    const unsigned int nextIndex{
        static_cast<unsigned int>(nodeNamesMap_.size())};
    nodeNamesMap_.insert({personName, nextIndex});
    weights_[nextIndex] = accountTakenOverCost;
}

void SocialNetwork::addConnection(const std::string& from,
                                  const std::string& to)
{
    const unsigned int fromId{nodeNamesMap_.at(from)};
    const unsigned int toId{nodeNamesMap_.at(to)};
    graph_[fromId][toId] = weights_[toId];
    graph_[toId][fromId] = weights_[fromId];
}

std::pair<std::unordered_set<std::string>, unsigned int>
SocialNetwork::getMSTAndWeight() const
{
    const uint64_t size{graph_.size()};
    std::unordered_set<std::string> nodes{};
    if (size <= 0)
        return {nodes, 0U};

    if (size == 1)
        return {{nodeIdToName(0U)}, weights_[0]};

    std::vector<unsigned int> minEdges(size, INT_MAX);
    minEdges[0] = 0;
    std::vector<bool> selected(size, false);

    for (uint64_t i = 0; i < size; ++i)
    {
        const unsigned int u{getMinEdgeIndex(minEdges, selected)};
        selected[u] = true;
        for (uint64_t v = 0; v < size; ++v)
            if (graph_[u][v] != 0 && !selected[v] && graph_[u][v] < minEdges[v])
            {
                nodes.insert(nodeIdToName(u));
                minEdges[v] = graph_[u][v];
            }
    }
    return {nodes, getWeight(nodes)};
}

unsigned int SocialNetwork::getMinEdgeIndex(
    const std::vector<unsigned int>& minEdges,
    const std::vector<bool>& selected)
{
    unsigned int minEdge{INT_MAX};
    unsigned int minEdgeIndex{0};

    for (unsigned int i = 0; i < selected.size(); ++i)
        if (!selected[i] && minEdges[i] < minEdge)
        {
            minEdge = minEdges[i];
            minEdgeIndex = i;
        }
    return minEdgeIndex;
}

std::string SocialNetwork::nodeIdToName(unsigned int nodeId) const
{
    const auto it =
        std::find_if(std::begin(nodeNamesMap_), std::end(nodeNamesMap_),
                     [&](auto&& p) { return p.second == nodeId; });
    return it->first;
}

unsigned int SocialNetwork::getWeight(
    const std::unordered_set<std::string>& nodes) const
{
    unsigned int sum{0};
    for (const auto& node : nodes)
        sum += weights_[nodeNamesMap_.at(node)];

    return sum;
}
