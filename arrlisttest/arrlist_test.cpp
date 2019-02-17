#include <gtest.h>
#include "List.h"

TEST(List, can_create_list)
{
  ASSERT_NO_THROW(List<int> A);
}

TEST(List, can_ins_and_get_value_from_first_link)
{
  List<int> A;
  A.InsFirst(10);
  EXPECT_EQ(A.GetValue(0), 10);
}

TEST(List, can_ins_and_get_value_from_last_link)
{
  List<int> A;
  A.InsFirst(10);
  A.InsLast(5);
  EXPECT_EQ(A.GetValue(1), 5);
}

TEST(List, can_ins_and_get_value_from_custom_link)
{
  List<int> A;
  A.InsFirst(10);
  A.InsLast(5);
  A.InsCustom(3, 1);
  A.InsCustom(2, 2);
  EXPECT_EQ(A.GetValue(2), 2);
}

TEST(List, throw_when_wrong_pos)
{
  List<int> A;
  A.InsFirst(10);
  A.InsLast(5);
  ASSERT_ANY_THROW(A.GetValue(100));
}

TEST(List, can_delete_first_link)
{
  List<int> A;
  A.InsFirst(10);
  A.InsLast(5);
  A.DelFirst();
  EXPECT_EQ(A.GetValue(0), 5);
}

TEST(List, can_delete_custom_link)
{
  List<int> A;
  A.InsFirst(10);
  A.InsCustom(12, 1);
  A.InsLast(5);
  A.DelCustom(1);
  EXPECT_EQ(A.GetValue(1), 5);
}

TEST(List, can_delete_last_link)
{
  List<int> A;
  A.InsFirst(10);
  A.InsCustom(12, 1);
  A.InsLast(5);
  A.DelCustom(2);
  EXPECT_EQ(A.GetValue(1), 12);
}
