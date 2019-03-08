#include <gtest.h>
#include "ArrList.h"

TEST(ArrList, can_create_list)
{
  ASSERT_NO_THROW(ArrList<int> A(3));
}

TEST(ArrList, throw_when_create_list_with_negative_lenhgt)
{
  ASSERT_ANY_THROW(ArrList<int> A(-3));
}

TEST(ArrList, IsEmpty_when_not_empty)
{
  ArrList<int> A(3);
  A.InsFirst(10);
  EXPECT_EQ(A.IsEmpty(), 0);
}

TEST(ArrList, IsEmpty_when_empty)
{
  ArrList<int> A(3);
  EXPECT_EQ(A.IsEmpty(), 1);
}

TEST(ArrList, IsFull_when_not_full)
{
  ArrList<int> A(1);
  EXPECT_EQ(A.IsFull(), 0);
}

TEST(ArrList, IsFull_when_full)
{
  ArrList<int> A(1);
  A.InsFirst(10);
  EXPECT_EQ(A.IsFull(), 1);
}

TEST(ArrList, can_ins_and_get_value_from_first_link)
{
  ArrList<int> A(3);
  A.InsFirst(10);
  A.GetFirst();
  A.InsFirst(19);
  A.InsFirst(9);
  A.GetFirst();
  
  EXPECT_EQ(A.GetFirst(), 19);
}

TEST(ArrList, can_ins_and_get_value_from_last_link)
{
  ArrList<int> A(3);
  A.InsFirst(10);
  A.InsLast(5);
  A.GetFirst();
  A.InsLast(3);

  EXPECT_EQ(A.GetLast(), 3);
}

TEST(ArrList, can_create_list_with_another_list)
{
  ArrList<int> A(1);
  A.InsFirst(10);
  ArrList<int> B(A);
  EXPECT_EQ(B.GetFirst(), 10);
}

TEST(ArrList, throw_when_getFirst_from_emp_List)
{
  ArrList<int> A(1);
  ASSERT_ANY_THROW(A.GetFirst());
}

TEST(ArrList, throw_when_getLast_from_emp_List)
{
  ArrList<int> A(1);
  ASSERT_ANY_THROW(A.GetLast());
}

TEST(ArrList, throw_when_insFirst_in_full_List)
{
  ArrList<int> A(1);
  A.InsFirst(10);
  ASSERT_ANY_THROW(A.InsFirst(10););
}

TEST(ArrList, throw_when_insLast_in_full_List)
{
  ArrList<int> A(1);
  A.InsFirst(10);
  ASSERT_ANY_THROW(A.InsLast(10););
}
