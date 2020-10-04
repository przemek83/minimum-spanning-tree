#include "gtest/gtest.h"

#include "../SocialNetwork.h"

TEST(SocialNetworkTest, emptyNetwork)
{
    SocialNetwork socialNetwork(0);
    std::pair<std::unordered_set<std::string>, unsigned int> expectedResult{{},
                                                                            0};
    EXPECT_EQ(socialNetwork.getMSTAndWeight(), expectedResult);
}

TEST(SocialNetworkTest, oneNodeNetwork)
{
    SocialNetwork socialNetwork(1U);
    socialNetwork.addPerson("Tim", 10U);
    std::pair<std::unordered_set<std::string>, unsigned int> expectedResult{
        {"Tim"}, 10U};
    EXPECT_EQ(socialNetwork.getMSTAndWeight(), expectedResult);
}

TEST(SocialNetworkTest, complexNetwork)
{
    SocialNetwork socialNetwork(5U);

    socialNetwork.addPerson("Robert", 12U);
    socialNetwork.addPerson("Julia", 23U);
    socialNetwork.addPerson("Adam", 1U);
    socialNetwork.addPerson("Carol", 10U);
    socialNetwork.addPerson("Daniel", 4U);

    socialNetwork.addConnection("Robert", "Julia");
    socialNetwork.addConnection("Robert", "Carol");
    socialNetwork.addConnection("Adam", "Robert");
    socialNetwork.addConnection("Daniel", "Adam");
    socialNetwork.addConnection("Daniel", "Julia");

    std::pair<std::unordered_set<std::string>, unsigned int> expectedResult{
        {"Adam", "Robert"}, 13U};
    EXPECT_EQ(socialNetwork.getMSTAndWeight(), expectedResult);
}
