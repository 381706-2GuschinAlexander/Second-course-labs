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

TEST(ArrList, can_ins_and_get_value_from_first_link)
{
  ArrList<int> A(3);
  A.InsFirst(10);
  A.InsFirst(9);
  A.GetFirst();
  A.GetFirst();
  EXPECT_EQ(A.GetFirst(), 10);
}

TEST(ArrList, can_ins_and_get_value_from_last_link)
{
  ArrList<int> A;
  A.InsFirst(10);
  A.InsLast(5);
  EXPECT_EQ(A.GetLast(), 5);
}
