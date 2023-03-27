#include <gtest/gtest.h>
#include "../LinkedList/Doubly.h"

using namespace std;
struct DoublyLinkedListTests:public testing::Test 
{
    DoublyLinkedList* list;

    virtual void SetUp() override { 
        cout << "Setting up test fixture" << endl;
        list = new DoublyLinkedList();
    }

    virtual void TearDown() override{
        cout << "Cleaning up after tests" << endl;
        delete list;
    }

    void AddFirst(int val){
        list->AddFirst(val);
    }

    void AddLast(int val){
        list->AddLast(val);
    }

    void DeleteFirst(){
        list->DeleteFirst();
    }
    
    void DeleteLast(){
        list->DeleteLast();
    }
};


TEST_F(DoublyLinkedListTests, After_First_Add_Head_Eq_Tail){
    
    AddFirst(100);
    EXPECT_EQ(list->GetHead(), list->GetTail());
    EXPECT_EQ(list->GetHead()->Item, list->GetTail()->Item);
};

TEST_F(DoublyLinkedListTests, After_Second_Add_Head_Not_Eq_Tail){
    AddFirst(100);
    AddLast(200);
    EXPECT_FALSE(list->GetHead() == list->GetTail());
    EXPECT_EQ(list->GetHead()->Next, list->GetTail());
    EXPECT_EQ(list->GetHead()->Previous, nullptr);
    EXPECT_EQ(list->GetTail()->Previous, list->GetHead());
    EXPECT_EQ(list->GetTail()->Next, nullptr);

    AddFirst(300);
    EXPECT_EQ(list->GetHead()->Item, 300);
};

TEST_F(DoublyLinkedListTests, Test_Delete_First_Last){ 
   
    AddFirst(100);
    EXPECT_EQ(list->GetHead(), list->GetTail());
    
    AddFirst(200);
    EXPECT_EQ(list->GetHead()->Item, 200);
    EXPECT_EQ(list->GetTail()->Item, 100);

    AddFirst(300);
    EXPECT_EQ(list->GetHead()->Item, 300);

    DeleteFirst();
    EXPECT_EQ(list->GetHead()->Item, 200);

    DeleteLast();
    EXPECT_EQ(list->GetTail()->Item, 200);
    EXPECT_EQ(list->GetHead(), list->GetTail());

    DeleteFirst();
    EXPECT_EQ(list->GetHead(), nullptr);
    EXPECT_EQ(list->GetTail(), nullptr);
};