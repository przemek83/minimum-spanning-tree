#include "gtest/gtest.h"

#include "../SocialNetwork.h"

TEST(SocialNetworkTest, emptyNetwork)
{
    SocialNetwork socialNetwork(0);
    std::pair<std::unordered_set<std::string>, unsigned int> expectedResult{{},
                                                                            0};
    EXPECT_EQ(socialNetwork.getMSTAndWeight(), expectedResult);
}
