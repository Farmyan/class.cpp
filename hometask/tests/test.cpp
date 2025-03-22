#include <stdio.h>
#include "factors.h"
#include <gtest/gtest.h>


TEST(FactorsTest,InputIs2OutputShouldBe2)

{
    std::vector<int>shouldbe = {2};
    EXPECT_EQ( FactorsTest(2),shouldbe);
}

TEST(FactorsTest,InputIs3OutputShouldBe3)

{
    std::vector<int>shouldbe = {3};
    EXPECT_EQ( FactorsTest(3),shouldbe);
}

TEST(FactorsTest,InputIs4OutputShouldBe2and2)

{
    std::vector<int>shouldbe = {2,2};
    EXPECT_EQ( FactorsTest(4),shouldbe);
}

TEST(FactorsTest,InputIs5OutputShouldBe5)

{
    std::vector<int>shouldbe = {5};
    EXPECT_EQ( FactorsTest(5),shouldbe);
}
TEST(FactorsTest,InputIs6OutputShouldBe2and3)

{
    std::vector<int>shouldbe = {2,3};
    EXPECT_EQ( FactorsTest(6),shouldbe);
}
TEST(FactorsTest,InputIs7OutputShouldBe7)

{
    std::vector<int>shouldbe = {7};
    EXPECT_EQ( FactorsTest(7),shouldbe);
}
TEST(FactorsTest,InputIs8OutputShouldBe2_2_2)

{
    std::vector<int>shouldbe = {2,2,2};
    EXPECT_EQ( FactorsTest(8),shouldbe);
}
TEST(FactorsTest,InputIs9OutputShouldBe3_3)

{
    std::vector<int>shouldbe = {3,3};
    EXPECT_EQ( FactorsTest(9),shouldbe);
}
TEST(FactorsTest,InputIs10OutputShouldBe2_2_2_2_2)

{
    std::vector<int>shouldbe = {2,5};
    EXPECT_EQ( FactorsTest(10),shouldbe);
}
//  TEST(FactorsTest,InputIs351923131997OutputShouldBethesame)

{
    std::vector<int>shouldbe = {3,5,19,23,131,997};
    EXPECT_EQ( FactorsTest(3*5*19*23*131*997),shouldbe);
}
TEST(FactorsTest,InputIs125OutputShouldBe555)

{
    std::vector<int>shouldbe = {5,5,5};
    EXPECT_EQ( FactorsTest(125),shouldbe);
}
TEST(FactorsTest,InputIs60OutputShouldBe2235)

{
    std::vector<int>shouldbe = {2,2,3,5};
    EXPECT_EQ( FactorsTest(60),shouldbe);
}
