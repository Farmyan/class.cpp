#include <gtest/gtest.h>
#include "LinkedList.h"
#include <utility>

// Step 1: InsertHead and Get
TEST(Linked_List, InsertHead_SingleNode) {
    LinkedList<int> list;
    list.InsertHead(10);
    EXPECT_EQ(list.Get(0), 10);
}   

TEST(Linked_List, InsertHead_TwoNodes) {
    LinkedList<int> list;
    list.InsertHead(10);
    list.InsertHead(20);
    EXPECT_EQ(list.Get(0), 20);
    EXPECT_EQ(list.Get(1), 10);
}   

//Step 2: InsertTail and Get
TEST(Linked_List, InsertTail_OneTail) {
    LinkedList<int> list;
    list.InsertTail(10);
    list.InsertHead(30);
    list.InsertHead(15); //Թեստ գրելու պահին գրված էր միայն այս և Get ֆունկցիաները
    EXPECT_EQ(list.Get(2), 10);
    
}   

//Step 3: Insert at position
TEST(Linked_List, Insert) {
    LinkedList<int> list;
    list.InsertHead(30);
    list.InsertHead(15); 
    list.Insert(1 , 18);
    EXPECT_EQ(list.Get(1), 18);
    
}   

TEST(Linked_List, Insert_Two_Thing) {
    LinkedList<int> list;
    list.InsertHead(30);
    list.InsertHead(15); 
    list.Insert(1 , 18);
    list.Insert(3 , 67);
    EXPECT_EQ(list.Get(3), 67);
}   

TEST(Linked_List, Insert_As_Head) {
    LinkedList<int> list;
    list.InsertHead(30);
    list.InsertHead(15); 
    list.Insert(0 , 18);
    EXPECT_EQ(list.Get(0), 18);
}   

TEST(Linked_List, Insert_As_Tail) {
    LinkedList<int> list;
    list.InsertHead(30);
    list.InsertTail(15); 
    list.Insert(2 , 18);
    EXPECT_EQ(list.Get(2), 18);
}   

//Step 4: Remove

TEST(Linked_List, Remove_Head) {
    LinkedList<int> list;
    list.InsertHead(30);
    list.InsertTail(15); 
    list.Insert(2 , 4);
    list.Remove(0);
    EXPECT_EQ(list.Get(0), 15);
}

TEST(Linked_List, Remove) {
    LinkedList<int> list;
    list.InsertHead(30);
    list.InsertTail(15); 
    list.Insert(1 , 19);
    list.Remove(1);
    EXPECT_EQ(list.Get(1), 15);
}   

TEST(Linked_List, Remove_Two_Thing) {
    LinkedList<int> list;
    list.InsertHead(30);
    list.InsertTail(15); 
    list.Insert(2 , 4);
    list.Insert(1 , 19);
    list.Remove(1);
    list.Remove(2);
    EXPECT_EQ(list.Get(1), 15);
    EXPECT_EQ(list.Get(0) , 30);
}   

//Step 5:Copy semantics
TEST(LinkedList, CopyConstructor)
{
    LinkedList<int> list1;
    list1.InsertHead(10);
    list1.InsertTail(20);
    list1.InsertTail(30);

    LinkedList<int> list2 = list1;  

    
    EXPECT_EQ(list2.Get(0), list1.Get(0));
    EXPECT_EQ(list2.Get(1), list1.Get(1));
    EXPECT_EQ(list2.Get(2), list1.Get(2));
}

TEST(LinkedList, CopyConstructor_Remove)
{
    LinkedList<int> list1;
    list1.InsertHead(10);
    list1.InsertTail(20);
    list1.InsertTail(30);

    LinkedList<int> list2 = list1;  

    list2.Remove(1);
    EXPECT_EQ(list2.Get(1), 30);
    EXPECT_EQ(list1.Get(1), 20);
}


TEST(LinkedList, CopyAssignment)
{
    LinkedList<int> list1;
    list1.InsertHead(5);
    list1.InsertTail(15);

    LinkedList<int> list2;
    list2 = list1; 

    EXPECT_EQ(list2.Get(0), list1.Get(0));
    EXPECT_EQ(list2.Get(1), list1.Get(1));

   
}

TEST(LinkedList, CopyAssignment_Remove)
{
    LinkedList<int> list1;
    list1.InsertHead(5);
    list1.InsertTail(15);

    LinkedList<int> list2;
    list2 = list1;  

    list2.Remove(0);
    EXPECT_EQ(list2.Get(0), 15);
    EXPECT_EQ(list1.Get(0), 5);
}

//Step 6: Move semantic


TEST(LinkedList, MoveConstructor)
{
    LinkedList<int> list1;
    list1.InsertHead(1);
    list1.InsertTail(2);

    LinkedList<int> list2 = std::move(list1);  

    EXPECT_EQ(list2.Get(0), 1);
    EXPECT_EQ(list2.Get(1), 2);
}

TEST(LinkedList, MoveAssignment_1)
{
    LinkedList<int> list1;
    list1.InsertHead(100);
    list1.InsertTail(200);

    LinkedList<int> list2;
    list2 = std::move(list1);  

    EXPECT_EQ(list2.Get(0), 100);
    EXPECT_EQ(list2.Get(1), 200);
}

//Step 7: Exceptions

TEST(LinkedList, Insert_InvalidPosition) {
    LinkedList<int> list;
    list.InsertHead(1);
    list.InsertTail(2);

    try {
        list.Insert(5, 10);
        FAIL() << "Expected IndexOutOfBoundsException";
    } catch (const LinkedListBase<int>::IndexOutOfBoundsException& e) {
        EXPECT_EQ(e.what(), "Index out of bounds");
    } 
}

TEST(LinkedList, Get_InvalidPosition) {
    LinkedList<int> list;
    list.InsertHead(10);
    list.InsertTail(20);

    try {
        list.Get(5);
        FAIL() << "Expected IndexOutOfBoundsException";
    } catch (const LinkedListBase<int>::IndexOutOfBoundsException& e) {
        EXPECT_EQ(e.what(), "Index out of bounds");
    } 
}

TEST(LinkedList, Remove_EmptyList) {
    LinkedList<int> list;

    try {
        list.Remove(0);
        FAIL() << "Expected ListEmptyException";
    } catch (const LinkedListBase<int>::ListEmptyException& e) {
        EXPECT_EQ(e.what(), "List is empty");
    } 
}

TEST(LinkedList, Remove_InvalidPosition) {
    LinkedList<int> list;
    list.InsertHead(1);
    list.InsertTail(2);

    try {
        list.Remove(5);
        FAIL() << "Expected OutOfLineException";
    } catch (const LinkedListBase<int>::OutOfLineException& e) {
        EXPECT_EQ(e.what(), "Out of line");
    } 
}

//ForEach
TEST(LinkedList, ForEach_ModifyElements)
{
    LinkedList<int> list;
    list.InsertTail(1);
    list.InsertTail(2);
    list.InsertTail(3);

    list.ForEach([](int &x) { x += 10; });

    EXPECT_EQ(list.Get(0), 11);
    EXPECT_EQ(list.Get(1), 12);
    EXPECT_EQ(list.Get(2), 13);
}

TEST(LinkedList, ForEach_SumValues)
{
    LinkedList<int> list;
    list.InsertTail(1);
    list.InsertTail(2);
    list.InsertTail(3);

    int sum = 0;
    list.ForEach([&sum](int value) {
        sum += value;
    });

    EXPECT_EQ(sum, 6);
}

TEST(LinkedList, ForEach_ModifyValues)
{
    LinkedList<int> list;
    list.InsertTail(5);
    list.InsertTail(10);

    list.ForEach([](int& value) {
        value += 1; 
    });

    EXPECT_EQ(list.Get(0), 6);
    EXPECT_EQ(list.Get(1), 11);
}

TEST(LinkedList, ForEach_EmptyList)
{
    LinkedList<int> list;
    int count = 0;

    list.ForEach([&count](int) {
        count++;
    });

    EXPECT_EQ(count, 0); 
}


// Iterator

TEST(LinkedList, Iterator_IterateValues)
{
    LinkedList<int> list;
    list.InsertTail(1);
    list.InsertTail(2);
    list.InsertTail(3);

    std::vector<int> values;
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        values.push_back(*it);
    }

    EXPECT_EQ(values.size(), 3);
    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 2);
    EXPECT_EQ(values[2], 3);
}

TEST(LinkedList, Iterator_ModifyValues)
{
    LinkedList<int> list;
    list.InsertTail(10);
    list.InsertTail(20);

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        *it += 5;
    }

    EXPECT_EQ(list.Get(0), 15);
    EXPECT_EQ(list.Get(1), 25);
}

TEST(LinkedList, Iterator_EmptyList)
{
    LinkedList<int> list;
    int count = 0;

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        count++;
    }

    EXPECT_EQ(count, 0);
}

