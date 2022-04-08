#include "../Inc/Exam.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class myMock : public intClass
{
public:
    MOCK_METHOD(bool, init, ());
    MOCK_METHOD(bool, login, (string nm, string psw));
};

class TestinitClass : public testing::Test
{
  public:
    myMock *mdb;
    myClass *db;
  
    void SetUp(){
      mdb = new myMock{};
      db = new myClass(*mdb);
      cout << "ALIVE" << endl;
    }

    void TearDown(){
      delete mdb;
      delete db;
      cout << "DEAD" << endl;
    }
};


TEST_F(TestinitClass, LoginTest1)
{
  //Arrange
    
    EXPECT_CALL(*mdb, init()).Times(1).WillOnce(Return(true));
    EXPECT_CALL(*mdb, login("Terminator","I'm back")).Times(1).WillOnce(Return(true));
  //Act
  int retValue = db->Initialization("Terminator", "I'm back");
  
  //Assert
  EXPECT_EQ(retValue, 1);
}

TEST_F(TestinitClass, LoginTest2)
{
  //Arrange
    
    EXPECT_CALL(*mdb, init()).Times(1).WillOnce(Return(true));
    EXPECT_CALL(*mdb, login("Terminator","I'm back")).Times(1).WillOnce(Return(false));
  //Act
  int retValue = db->Initialization("Terminator", "I'm back");
  
  //Assert
  EXPECT_EQ(retValue, -1);
}

TEST_F(TestinitClass, LoginTest3)
{
  //Arrange
    
    EXPECT_CALL(*mdb, init()).Times(1).WillOnce(Return(true));
    EXPECT_CALL(*mdb, login(_,_)).Times(1).WillOnce(Return(false));
  //Act
  int retValue = db->Initialization("Terminator", "I will back");
  
  //Assert
  EXPECT_EQ(retValue, -1);
}

TEST_F(TestinitClass, LoginTest4)
{
  //Arrange
    
    EXPECT_CALL(*mdb, init()).Times(1).WillOnce(Return(false));
    EXPECT_CALL(*mdb, login(_,_)).Times(0);
  //Act
  int retValue = db->Initialization("Terminator", "I'm back");
  
  //Assert
  EXPECT_EQ(retValue, -1);
}


TEST(ExampleTest, FirstTest)
{
    EXPECT_TRUE(true);
}
