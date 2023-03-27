#include <gtest/gtest.h>
#include "../LinkedList/LinkedList.h"

using namespace std;
struct LinkedListTests:public testing::Test 
{
    LinkedList* list;

    virtual void SetUp() override { 
        cout << "Setting up test fixture" << endl;
        list = new LinkedList();
    }

    virtual void TearDown() override{
        cout << "Cleaning up after tests" << endl;
        delete list;
    }

    void Add(int val){
        list->AddNode(val);
    }

    int DeleteFirst(){
        return list->DeleteFirst();
    }
    
    int DeleteLast(){
        return list->DeleteLast();
    }
};


TEST_F(LinkedListTests, After_First_Add_Head_Eq_Tail){
    
    Add(100);
    EXPECT_EQ(list->GetHead(), list->GetTail());
    EXPECT_EQ(list->GetHead()->Item, list->GetTail()->Item);
};

TEST_F(LinkedListTests, After_Second_Add_Head_Not_Eq_Tail){
    Add(100);
    Add(100);
    EXPECT_FALSE(list->GetHead() == list->GetTail());
    EXPECT_EQ(list->GetHead()->Next, list->GetTail());
    EXPECT_EQ(list->GetTail()->Next, nullptr);
};

TEST_F(LinkedListTests, Can_Not_Delete_From_Empty_List){
   
    EXPECT_EQ (DeleteFirst(), 0);
};

TEST_F(LinkedListTests, Test_Delete_First_Last_Empty){
   
    
    Add(100);
    EXPECT_EQ(list->GetHead(), list->GetTail());
    EXPECT_EQ(list->GetHead()->Item, 100);
    
    Add(200);
    EXPECT_EQ(list->GetTail()->Item, 200);

    Add(300);
    EXPECT_EQ(list->GetTail()->Item, 300);

    EXPECT_EQ(DeleteFirst(), 100);
    EXPECT_EQ(list->GetHead()->Item, 200);

    EXPECT_EQ(DeleteLast(), 300);
    EXPECT_EQ(list->GetHead(), list->GetTail());
    EXPECT_EQ(list->GetHead()->Item, 200);
    EXPECT_EQ(list->GetTail()->Item, 200);

    int var = DeleteFirst();
    EXPECT_EQ(var, 200) << "Value = " << var;
    EXPECT_EQ(list->GetHead(), nullptr);
    EXPECT_EQ(list->GetTail(), nullptr);
};