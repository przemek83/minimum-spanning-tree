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
