#include <stdio.h>
#include <gtest/gtest.h>
#include "fortesst.h"
TEST(Matrix,MatrixHasOneValue5_OutputShouldBeSame)
{    
    
    int element = {5};
    int array[1] ={element};
    EXPECT_EQ( MatrixMaxValue( array, 1),element);
    
}
TEST(Matrix,MatrixHasOneValue0_OutputShouldBeSame)
{    
    int element = {0};
    int array[1] ={element};
    EXPECT_EQ( MatrixMaxValue( array, 1),element);
    
}
TEST(Matrix,MatrixHasOneValue15_OutputShouldBeSame)
{    
    int element = {15};
    int array[1] ={element};
    EXPECT_EQ( MatrixMaxValue( array, 1),element);
    
}
TEST(Matrix,MatrixHasOneValue8_OutputShouldBeSame)
{    
    int element = {8};
    int array[1] ={element};
    EXPECT_EQ( MatrixMaxValue( array, 1),element);
    
}
TEST(Matrix,MatrixHastwoValues1an2_OutputShouldBe2)
{    
    int element = {2};
    int array[2] ={1 , 2};
    EXPECT_EQ( MatrixMaxValue( array, 2),element);
    
}
TEST(Matrix,MatrixHastwoValues2and1_OutputShouldBe2)
{    
    int element = {2};
    int array[2] ={2 , 1};
    EXPECT_EQ( MatrixMaxValue( array, 2),element);
    
}
TEST(Matrix,MatrixHastwoValues8and11_OutputShouldBe11)
{    
    int element = {11};
    int array[2] ={8 , 11};
    EXPECT_EQ( MatrixMaxValue( array, 2),element);
    
}
TEST(Matrix,MatrixHastwoValues11and8_OutputShouldBe11)
{    
    int element = {11};
    int array[2] ={11 , 8};
    EXPECT_EQ( MatrixMaxValue( array, 2),element);
    
}
TEST(Matrix,MatrixHastwoValues1_2and3_OutputShouldBe3)
{    
    int element = {3};
    int array[3] ={1 , 2, 3};
    EXPECT_EQ( MatrixMaxValue( array, 3),element);
    
}
TEST(Matrix,MatrixHastwoValues3_1and2_OutputShouldBe3)
{    
    int element = {3};
    int array[3] ={3 , 1, 2};
    EXPECT_EQ( MatrixMaxValue( array, 3),element);
    
}
TEST(Matrix,MatrixHastwoValues2_3and1_OutputShouldBe3)
{    
    int element = {3};
    int array[3] ={2 , 3, 1};
    EXPECT_EQ( MatrixMaxValue( array, 3),element);
    
}
TEST(Matrix,MatrixHaslotsofValues_OutputShouldBeMax)
{    
    int element = {24124};
    int array[15] ={12 , 2351, 12412,241,1241,1424,63,213,634,23,24124,722,2143,2134,2134};
    EXPECT_EQ( MatrixMaxValue( array, 15),element);
    
}
TEST(Matrix,MatrixHasNegativeValues)
{    
    int element = {-1};
    int array[11] ={-1 , -2, -3,-4,-5,-6,-7,-8,-9,-10,-11};
    EXPECT_EQ( MatrixMaxValue( array, 11),element);
    
}
TEST(Matrix,MatrixHassomeNegativeValuesAndOnePositive)
{    
    int element = {1};
    int array[11] ={-1 , -2, -3,-4,-5,-6,1,-8,-9,-10,-11};
    EXPECT_EQ( MatrixMaxValue( array, 11),element);
    
}

