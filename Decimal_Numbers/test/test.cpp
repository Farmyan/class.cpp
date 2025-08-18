#include "DecimalBase.h"
#include "FixedDecimal.h"
#include "FloatingDecimal.h"
#include <gtest/gtest.h>

//Step 1: ToString tests 
TEST(Decimal, Fixed_ToString) 
    {
        FixedDecimal d(12.3456, 3);
        EXPECT_EQ(d.ToString(), "12.346");
    }

TEST(Decimal, Floating_ToString) 
    {
        FloatingDecimal d(12.345678);
        EXPECT_EQ(d.ToString(), "12.345678");
    }

TEST(Decimal, Fixed_Zero) 
    {
        FixedDecimal d(0.0, 2);
        EXPECT_EQ(d.ToString(), "0.00");
    }

TEST(Decimal, Floating_Zero) 
    {
        FloatingDecimal d(0.0);
        EXPECT_EQ(d.ToString(), "0.000000");
    }

TEST(Decimal, Fixed_Negative) 
    {
        FixedDecimal d(-5.6789, 3);
        EXPECT_EQ(d.ToString(), "-5.679");
    }

TEST(Decimal, Floating_Negative) 
    {
        FloatingDecimal d(-3.141592);
        EXPECT_EQ(d.ToString(), "-3.141592");
    }

//Step 2: FixedDecimal arithmetic 
TEST(Decimal, Fixed_AddFixed) 
    {
        FixedDecimal d1(10.5, 2);
        FixedDecimal d2(2.25, 2);
        DecimalBase* sum = d1.Add(d2);
        EXPECT_EQ(sum->ToString(), "12.75");
        delete sum;
    }

TEST(Decimal, Fixed_SubtractFixed) 
    {
        FixedDecimal d1(10.5, 2);
        FixedDecimal d2(2.25, 2);
        DecimalBase* diff = d1.Subtract(d2);
        EXPECT_EQ(diff->ToString(), "8.25");
        delete diff;
    }

//Step 3: FloatingDecimal arithmetic 
TEST(Decimal, Floating_AddFloating) 
    {
        FloatingDecimal d1(5.123456);
        FloatingDecimal d2(2.654321);
        DecimalBase* sum = d1.Add(d2);
        EXPECT_EQ(sum->ToString(), "7.777777");
        delete sum;
    }

TEST(Decimal, Floating_SubtractFloating) 
    {
        FloatingDecimal d1(5.123456);
        FloatingDecimal d2(2.654321);
        DecimalBase* diff = d1.Subtract(d2);
        EXPECT_EQ(diff->ToString(), "2.469135");
        delete diff;
    }

//Step 4: Mixed arithmetic (Fixed + Floating) 
TEST(Decimal, Fixed_AddFloating) 
    {
        FixedDecimal f(10.5, 2);
        FloatingDecimal fl(2.345678);
        DecimalBase* sum = f.Add(fl);
        EXPECT_EQ(sum->ToString(), "12.845678");
        delete sum;
    }

TEST(Decimal, Floating_AddFixed) 
    {
        FloatingDecimal fl(2.345678);
        FixedDecimal f(10.5, 2);
        DecimalBase* sum = fl.Add(f);
        EXPECT_EQ(sum->ToString(), "12.845678");
        delete sum;
    }

TEST(Decimal, Fixed_SubtractFloating) 
    {
        FixedDecimal f(10.5, 2);
        FloatingDecimal fl(2.345678);
        DecimalBase* diff = f.Subtract(fl);
        EXPECT_EQ(diff->ToString(), "8.154322");
        delete diff;
    }

TEST(Decimal, Floating_SubtractFixed) 
    {
        FloatingDecimal fl(12.345678);
        FixedDecimal f(10.5, 2);
        DecimalBase* diff = fl.Subtract(f);
        EXPECT_EQ(diff->ToString(), "1.845678");
        delete diff;
    }

//Step 5: Mixed precision 
TEST(Decimal, Fixed_AddDifferentPrecision) 
    {
        FixedDecimal d1(1.2345, 2);
        FixedDecimal d2(0.00678, 4);
        DecimalBase* sum = d1.Add(d2);
        EXPECT_EQ(sum->ToString(), "1.2413");
        delete sum;
    }

//Step 6: Edge cases 
TEST(Decimal, Floating_AddNegative) 
    {
        FloatingDecimal d1(-3.5);
        FloatingDecimal d2(2.5);
        DecimalBase* sum = d1.Add(d2);
        EXPECT_EQ(sum->ToString(), "-1.000000");
        delete sum;
    }

TEST(Decimal, Fixed_SubtractNegative) 
    {
        FixedDecimal d1(-3.5, 2);
        FixedDecimal d2(-2.5, 2);
        DecimalBase* diff = d1.Subtract(d2);
        EXPECT_EQ(diff->ToString(), "-1.00");
        delete diff;
    }

TEST(Decimal, Floating_AddZero) 
    {
        FloatingDecimal d1(1.234);
        FloatingDecimal d2(0.0);
        DecimalBase* sum = d1.Add(d2);
        EXPECT_EQ(sum->ToString(), "1.234000");
        delete sum;
    }

TEST(Decimal, Fixed_SubtractZero) 
    {
        FixedDecimal d1(1.234, 3);
        FixedDecimal d2(0.0, 3);
        DecimalBase* diff = d1.Subtract(d2);
        EXPECT_EQ(diff->ToString(), "1.234");
        delete diff;
    }
