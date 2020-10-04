#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

class SocialNetwork final
{
public:
    explicit SocialNetwork(unsigned int peopleCount);

    ~SocialNetwork() = default;

    void addPerson(const std::string& personName,
                   unsigned int accountTakenOverCost);

    void addConnection(const std::string& from, const std::string& to);

    std::pair<std::unordered_set<std::string>, unsigned int> getMSTAndWeight();

private:
    unsigned int getMinEdgeIndex(const std::vector<unsigned int>& minEdges,
                                 const std::vector<bool>& selected);

    std::string nodeIdToName(unsigned int nodeId);

    std::unordered_map<std::string, unsigned int> nodeNamesMap_{};
    std::vector<std::vector<unsigned int>> graph_;
    std::vector<unsigned int> weights_;
};
