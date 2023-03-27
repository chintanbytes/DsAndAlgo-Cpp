#include <gtest/gtest.h>
#include "../LinkedList/circular.h"

using namespace std;
struct CircularLinkedListTests:public testing::Test 
{
    CircularLinkedList* list;

    virtual void SetUp() override { 
        cout << "Setting up test fixture" << endl;
        list = new CircularLinkedList();
    }

    virtual void TearDown() override{
        cout << "Cleaning up after tests" << endl;
        delete list;
    }

    void Add(int val){
        list->Add(val);
    }

    void Delete(){
        list->Delete();
    }
};

TEST_F(CircularLinkedListTests, Test_Add){
    Add(100);
    EXPECT_EQ(list->GetHead()->Item, 100);
}

TEST_F(CircularLinkedListTests, Test_Add_Two_Then_Delete){
    Add(100);
    EXPECT_EQ(list->GetHead()->Item, 100);

    Add(200);
    EXPECT_EQ(list->GetHead()->Item, 100);

    Delete();
    EXPECT_EQ(list->GetHead()->Item, 100);
}

TEST_F(CircularLinkedListTests, Test_Add_Two_Then_Empty){
    Add(100);
    EXPECT_EQ(list->GetHead()->Item, 100);

    Add(200);
    EXPECT_EQ(list->GetHead()->Item, 100);

    Delete();
    EXPECT_EQ(list->GetHead()->Item, 100);

    Delete();
    EXPECT_EQ(list->GetHead(), nullptr);
}