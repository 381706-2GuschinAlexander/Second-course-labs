#include <gtest.h>
#include "StackList.h"

TEST(TStackList, can_create_stack)
{
  ASSERT_NO_THROW(TStackList<int> A);
}

TEST(TStackList, can_put_and_get_from_stack)
{
  TStackList<int> A;
  for (int i = 0; i < 4; i++)
    A.Put(i);

  bool isOkay = 1;
  for (int i = 3; i >= 1; i--)
    if (A.Get() != i)
      isOkay = 0;

  EXPECT_EQ(1, isOkay);
}

TEST(TStackList, IsEmpty_when_empty)
{
  TStackList<int> A;

  EXPECT_EQ(1, A.IsEmpty());
}

TEST(TStackList, IsEmpty_when_not_empty)
{
  TStackList<int> A;
  A.Put(1);
  EXPECT_EQ(0, A.IsEmpty());
}

TEST(TStackList, throw_when_get_from_empty_stack)
{
  TStackList<int> A;
  ASSERT_ANY_THROW(A.Get());
}

