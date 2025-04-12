#include <stdio.h>
#include <gtest/gtest.h>
#include "pow.h"

TEST(PowerOfNumber , xEqualOneOutputShouldBeOne1)
{
    int result = { 1 };
    int x = {1};
    int n = {2};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqualOneOutputShouldBeOne2)
{
    int result = { 1 };
    int x = {1};
    int n = {5};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqualOneOutputShouldBeOne3)
{
    int result = { 1 };
    int x = {1};
    int n = {10000000};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqual2nEqual1OutputShouldBeSame1)
{
    int result = { 2 };
    int x = {2};
    int n = {1};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqual7nEqual1OutputShouldBeSame2)
{
    int result = { 7 };
    int x = {7};
    int n = {1};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqual100000nEqual1OutputShouldBeSame3)
{
    int result = { 100000 };
    int x = {100000};
    int n = {1};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqual2nEqual2OutputShouldBe4)
{
    int result = { 4 };
    int x = {2};
    int n = {2};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqual5nEqual2OutputShouldBe)
{
    int result = { 25 };
    int x = {5};
    int n = {2};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqual2nEqual3OutputShouldBe8)
{
    int result = { 8 };
    int x = {2};
    int n = {3};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqual5nEqual3OutputShouldBe125)
{
    int result = { 125 };
    int x = {5};
    int n = {3};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqual12nEqual2OutputShouldBe144)
{
    int result = { 144 };
    int x = {12};
    int n = {2};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqual0nEqual2OutputShouldBe0)
{
    int result = { 0 };
    int x = {0};
    int n = {2};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqual125nEqual4OutputShouldBeHuge)
{
    int result = { 244140625 };
    int x = {125};
    int n = {4};
    EXPECT_EQ(power(x , n) , result );
}

TEST(PowerOfNumber , xEqualNegative7nEqual3OutputShouldBeMinus343)
{
    int result = { -343 };
    int x = {-7};
    int n = {3};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqualNEagtive7nEqual2OutputShouldBe49)
{
    int result = { 49 };
    int x = {-7};
    int n = {2};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqualN2nEqualNegative3OutputShouldBe0125)
{
    double result = { 0.125 };
    int x = {2};
    int n = {-3};
    EXPECT_EQ(power(x , n) , result );
}
TEST(PowerOfNumber , xEqualNEagtive7nEqualNegatie3OutputShouldBesmth)
{
    double result = { -0.0029154518950437313 };
    int x = {-7};
    int n = {-3};
    EXPECT_EQ(power(x , n) , result );
}










