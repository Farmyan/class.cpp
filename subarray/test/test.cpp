#include <stdio.h>
#include "subarray.h"
#include <gtest/gtest.h>

TEST(SubArray , MatrixHasTwoNumbersAndTrue0)
{
    int element = {true};
    int arr[2] = { 1 , 2};
    int subarr[2] = { 1 , 2};
    EXPECT_EQ(SubArray(arr , 2 , subarr , 2 )  , element);
}
TEST(SubArray , MatrixHasTwoNumbersAndTrue1)
{
    int element = {true};
    int arr[2] = { 2 , 1};
    int subarr[2] = { 2 , 1};
    EXPECT_EQ(SubArray(arr , 2 , subarr , 2 )  , element);
}
TEST(SubArray , MatrixHasTwoNumbersAndFasle0)
{
    int element = {false};
    int arr[2] = { 2 , 1};
    int subarr[2] = { 1 , 2};
    EXPECT_EQ(SubArray(arr , 2 , subarr , 2 )  , element);
}
TEST(SubArray , MatrixHasTwoNumbersAndFasle1)
{
    int element = {false};
    int arr[2] = { 2 , 5};
    int subarr[2] = { 1 , 2};
    EXPECT_EQ(SubArray(arr , 2 , subarr , 2 )  , element);
}
TEST(SubArray , MatrixHasThreeNumbersAndtrue0)
{
    int element = {true};
    int arr[3] = { 2 , 1 , 3};
    int subarr[3] = { 2 , 1 , 3}  ;
    EXPECT_EQ(SubArray(arr , 3 , subarr , 3 )  , element);
}
TEST(SubArray , MatrixHasThreeNumbersAndfalse1)
{
    int element = {false};
    int arr[6] = { 2 , 1 , 3 , 2 , 1 , 7 };
    int subarr[3] = { 2 , 1 , 5}  ;
    EXPECT_EQ(SubArray(arr , 3 , subarr , 3 )  , element);
}
TEST(SubArray , MatrixHasSomeNumbersAndTrue1)
{
    int element = {true};
    int arr[6] = { 2 , 1 , 3 , 2 , 1 , 5 };
    int subarr[3] = { 2 , 1 , 5}  ;
    EXPECT_EQ(SubArray(arr , 6 , subarr , 3 )  , element);
}
TEST(SubArray , MatrixHasSomeNumbersAndTrue2)
{
    int element = {true};
    int arr[8] = { 2 , 1 , 3 , 2 , 1 , 5 , 22 , 3 };
    int subarr[3] = { 1 , 5 , 22}  ;
    EXPECT_EQ(SubArray(arr , 8 , subarr , 3 )  , element);
}
TEST(SubArray , MatrixHasSomeNumbersAndTrue3)
{
    int element = {true};
    int arr[6] = { 2 , 7 , 9 , 7 , 8 , 5 };
    int subarr[2] = { 7 , 9}  ;
    EXPECT_EQ(SubArray(arr , 6 , subarr , 2 )  , element);
}
TEST(SubArray , MatrixHasSomeNumbersAndTrue4)
{
    int element = {true};
    int arr[11] = { 2 , 1 , 3 , 2 , 1 , 5  , 5 , 6 , 5 , 5 , 5};
    int subarr[6] = { 5 , 5 ,6 , 5 , 5, 5}  ;
    EXPECT_EQ(SubArray(arr , 11 , subarr , 6 )  , element);
}
TEST(SubArray , MatrixHasSomeNumbersAndFalse1)
{
    int element = {false};
    int arr[6] = { 2 , 1 , 3 , 2 , 1 , 8 };
    int subarr[3] = { 2 , 1 , 5}  ;
    EXPECT_EQ(SubArray(arr , 6 , subarr , 3 )  , element);
}
TEST(SubArray , MatrixHasSomeNumbersAndFalse2)
{
    int element = {false};
    int arr[8] = { 6 , 4 , 7 , 1  , 6 , 3 , 6 , 1 };
    int subarr[4] = { 4 , 7 , 6 , 3}  ;
    EXPECT_EQ(SubArray(arr , 8 , subarr , 4 )  , element);
}
TEST(SubArray , MatrixHasSomeNumbersAndFalse3)
{
    int element = {false};
    int arr[15] = { 5 , 7 , 1 , 6 , 2 , 5 , 3 , 54 , 6 , 4, 6, 6 , 5 , 2 ,54  };
    int subarr[7] = { 2 , 1 , 5 , 54 , 7 , 3 , 4}  ;
    EXPECT_EQ(SubArray(arr , 15 , subarr , 7 )  , element);
}
TEST(SubArray , MatrixHasSomeNumbersAndFalse4)
{
    int element = {false};
    int arr[6] = { 2 , 1 , 3 , 2 , 1 , 8 };
    int subarr[3] = { 1 , 3 , 1}  ;
    EXPECT_EQ(SubArray(arr , 6 , subarr , 3 )  , element);
}