#include "MatrixClass.h"
#include <gtest/gtest.h>
#include <utility>


//Step 1:At();
TEST(Matrix, At_OutOfRange_Throws) {
    MatrixClass<int> m(2, 2);
    try 
        {
            m.at(2, 0);
            FAIL() << "Expected IndexOutOfBoundsException";
        } 
    catch (const MatrixClassBase<int>::IndexOutOfBoundsException& e) 
        {
            EXPECT_STREQ(e.what(), "Index out of bounds");
        }
    try     
        {
            m.at(0, 2);
            FAIL() << "Expected IndexOutOfBoundsException";
        }   
    catch (const MatrixClassBase<int>::IndexOutOfBoundsException& e) 
        {
            EXPECT_STREQ(e.what(), "Index out of bounds");
        }
}

TEST(Matrix, At_SetAndGet) 
{
    MatrixClass<int> m(2, 2);
    m.at(0, 0) = 1;
    m.at(0, 1) = 2;
    m.at(1, 0) = 3;
    m.at(1, 1) = 4;
    EXPECT_EQ(m.at(0, 0), 1);
    EXPECT_EQ(m.at(0, 1), 2);
    EXPECT_EQ(m.at(1, 0), 3);
    EXPECT_EQ(m.at(1, 1), 4);
}

TEST(Matrix, AtConst_NormalAccess) 
{
    const MatrixClass<int> m(2, 2);
    EXPECT_EQ(m.at(0, 0), 0); // Since matrix is initialized with default T(), all values are 0
}

//Step 2:Addition

TEST(Matrix, Addition_SizeMismatch_Throws) 
{
    MatrixClass<int> a(2, 2);
    MatrixClass<int> b(3, 3);

    try 
        {
            auto c = a + b;
            FAIL() << "Expected SizeMismatchException";
        } 
    catch (const MatrixClassBase<int>::SizeMismatchException& e) 
        {
            EXPECT_STREQ(e.what(), "Matrix size mismatch");
    }      
}
TEST(Matrix, Addition) {
    MatrixClass<int> a(2, 2);
    MatrixClass<int> b(2, 2);

    a.at(0,0) = 1; a.at(0,1) = 2;
    a.at(1,0) = 3; a.at(1,1) = 4;

    b.at(0,0) = 5; b.at(0,1) = 6;
    b.at(1,0) = 7; b.at(1,1) = 8;

    MatrixClass<int> c = a + b;

    EXPECT_EQ(c.at(0,0), 6);
    EXPECT_EQ(c.at(0,1), 8);
    EXPECT_EQ(c.at(1,0), 10);
    EXPECT_EQ(c.at(1,1), 12);
}

//Step 3:Substruction
TEST(Matrix, Subtraction_SizeMismatch_Throws) {
    MatrixClass<int> a(2, 2);
    MatrixClass<int> b(3, 3);

    try {
        auto c = a - b;
        FAIL() << "Expected SizeMismatchException";
    } catch (const MatrixClassBase<int>::SizeMismatchException& e) {
        EXPECT_STREQ(e.what(), "Matrix size mismatch");
    }
}

TEST(Matrix, Subtraction) {
    MatrixClass<int> a(2, 2);
    MatrixClass<int> b(2, 2);

    a.at(0,0) = 5; a.at(0,1) = 7;
    a.at(1,0) = 9; a.at(1,1) = 11;

    b.at(0,0) = 1; b.at(0,1) = 2;
    b.at(1,0) = 3; b.at(1,1) = 4;

    MatrixClass<int> c = a - b;

    EXPECT_EQ(c.at(0,0), 4);
    EXPECT_EQ(c.at(0,1), 5);
    EXPECT_EQ(c.at(1,0), 6);
    EXPECT_EQ(c.at(1,1), 7);
}

//Step 4:Multiplication
TEST(Matrix, Multiplication_SizeMismatch_Throws) 
{
    MatrixClass<int> a(2, 2);
    MatrixClass<int> b(3, 3);

    try 
        {
            auto c = a * b;
            FAIL() << "Expected InvalidMultiplicationException";
        } 
    catch (const MatrixClassBase<int>::InvalidMultiplicationException& e) 
        {
            EXPECT_STREQ(e.what(), "Invalid matrix multiplication dimensions");
        }
}
TEST(Matrix, Multiplication_Simple) 
{
    MatrixClass<int> a(2, 3);
    MatrixClass<int> b(3, 2);

    int val = 1;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            a.at(i, j) = val++;

    val = 1;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 2; ++j)
            b.at(i, j) = val++;

    MatrixClass<int> c = a * b;

    EXPECT_EQ(c.at(0,0), 22);
    EXPECT_EQ(c.at(0,1), 28);
    EXPECT_EQ(c.at(1,0), 49);
    EXPECT_EQ(c.at(1,1), 64);
}

//Step 5: Transpose

TEST(Matrix, Transpose_Simple) 
{
    MatrixClass<int> m(2, 3);
    m.at(0,0) = 1; m.at(0,1) = 2; m.at(0,2) = 3;
    m.at(1,0) = 4; m.at(1,1) = 5; m.at(1,2) = 6;

    MatrixClass<int> t = m.transpose();

    EXPECT_EQ(t.at(0,0), 1);
    EXPECT_EQ(t.at(1,0), 2);
    EXPECT_EQ(t.at(2,0), 3);
    EXPECT_EQ(t.at(0,1), 4);
    EXPECT_EQ(t.at(1,1), 5);
    EXPECT_EQ(t.at(2,1), 6);
}

//Step 6:Copy semantic
TEST(Matrix, Transpose) 
{
    MatrixClass<int> m(2, 3);
    m.at(0,0) = 1; m.at(0,1) = 2; m.at(0,2) = 3;
    m.at(1,0) = 4; m.at(1,1) = 5; m.at(1,2) = 6;

    MatrixClass<int> t = m.transpose();

    EXPECT_EQ(t.at(0,0), 1);
    EXPECT_EQ(t.at(1,0), 2);
    EXPECT_EQ(t.at(2,0), 3);
    EXPECT_EQ(t.at(0,1), 4);
    EXPECT_EQ(t.at(1,1), 5);
    EXPECT_EQ(t.at(2,1), 6);
}

TEST(Matrix, CopyAssignment) 
{
    MatrixClass<int> m(2, 2);
    m.at(0,0) = 1;
    m.at(0,1) = 2;
    m.at(1,0) = 3;
    m.at(1,1) = 4;

    MatrixClass<int> m2(2, 2);
    m2 = m;

    EXPECT_EQ(m2.at(0,0), 1);
    EXPECT_EQ(m2.at(1,1), 4);
}

//Step 7:Move semantic

TEST(Matrix, MoveConstructor) {
    MatrixClass<int> m1(2, 2);
    m1.at(0,0) = 10;
    m1.at(0,1) = 20;
    m1.at(1,0) = 30;
    m1.at(1,1) = 40;

    MatrixClass<int> moved = std::move(m1); 

    EXPECT_EQ(moved.at(0,0), 10);
    EXPECT_EQ(moved.at(0,1), 20);
    EXPECT_EQ(moved.at(1,0), 30);
    EXPECT_EQ(moved.at(1,1), 40);

    
}

TEST(Matrix, MoveAssignment) {
    MatrixClass<int> m1(2, 2);
    m1.at(0,0) = 5;
    m1.at(0,1) = 15;
    m1.at(1,0) = 25;
    m1.at(1,1) = 35;

    MatrixClass<int> m2(2, 2);
    m2 = std::move(m1); 

    EXPECT_EQ(m2.at(0,0), 5);
    EXPECT_EQ(m2.at(0,1), 15);
    EXPECT_EQ(m2.at(1,0), 25);
    EXPECT_EQ(m2.at(1,1), 35);
}
