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

#include <iostream>

#include "SocialNetwork.h"

int main()
{
    unsigned int peopleCount;
    std::cin >> peopleCount;
    SocialNetwork socialNetwork(peopleCount);
    for (unsigned int i = 0; i < peopleCount; ++i)
    {
        std::string personName;
        unsigned int accountTakenOverCost{0};
        std::cin >> personName >> accountTakenOverCost;
        socialNetwork.addPerson(personName, accountTakenOverCost);
    }

    unsigned int connectionsCount{0};
    std::cin >> connectionsCount;
    for (unsigned int i = 0; i < connectionsCount; ++i)
    {
        std::string from;
        std::string to;
        std::cin >> from >> to;
        socialNetwork.addConnection(from, to);
    }

    const auto [nodes, sum] = socialNetwork.getMSTAndWeight();
    std::cout << nodes.size() << std::endl;
    for (const auto& node : nodes)
        std::cout << node << std::endl;

    std::cout << sum << std::endl;

    return 0;
}
