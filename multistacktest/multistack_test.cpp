#include <gtest.h>
#include "Multistack.h"

TEST(Multystack, can_create_MS)
{
  ASSERT_NO_THROW(TMulStack<int> A(3, 10));
}

TEST(Multystack, throw_when_create_MS_with_count_bigger_then_l)
{
  ASSERT_ANY_THROW(TMulStack<int> A(3, 1));
}

TEST(Multystack, throw_when_create_MS_with_negative_l)
{
  ASSERT_ANY_THROW(TMulStack<int> A(3, -10));
}

TEST(Multystack, throw_when_create_MS_with_negative_count)
{
  ASSERT_ANY_THROW(TMulStack<int> A(-3, 10));
}

TEST(Multystack, IsEmpty_when_MS_is_empty)
{
  TMulStack<int> A(3, 10);
  EXPECT_EQ(A.IsEmpty(0), 1);
}

TEST(Multystack, IsEmpty_when_MS_is_not_empty)
{
  TMulStack<int> A(3, 10);
  A.Put(1, 0);
  EXPECT_EQ(A.IsEmpty(0), 0);
}

TEST(Multystack, IsFull_when_MS_is_empty)
{
  TMulStack<int> A(3, 10);
  EXPECT_EQ(A.IsFull(0), 0);
}

TEST(Multystack, IsFull_when_MS_is_full)
{
  TMulStack<int> A(3, 3);
  A.Put(1, 0);
  EXPECT_EQ(A.IsFull(0), 1);
}

TEST(Multystack, throw_when_get_from_empty_stack)
{
  TMulStack<int> A(3, 10);
  ASSERT_ANY_THROW(A.Get(0));
}

TEST(Multystack, can_put_and_get_from_stack)
{
  TMulStack<int> A(3, 10);
  A.Put(2, 0);
  EXPECT_EQ(A.Get(0), 2);
}

TEST(Multystack, can_put_and_get_from_not_full_MS_stack)
{
  TMulStack<int> A(6, 6);
  A.Put(1, 3);
  A.Put(2, 3);
  A.Put(3, 3);
  A.Put(4, 3);
  A.Put(5, 3);
  A.Put(6, 3);
  A.Get(3);
  A.Get(3);
  A.Put(-1, 2);
  A.Put(-2, 2);
  EXPECT_EQ(A.Get(2), -2);
}

TEST(Multystack, throw_when_put_in_full_MS)
{
  TMulStack<int> A(2, 4);
  A.Put(1, 0);
  A.Put(2, 0);
  A.Put(2, 0);
  A.Put(2, 0);
  ASSERT_ANY_THROW(A.Put(3, 0));
}

TEST(Multystack, resize_with_empty_stacks)
{
  TMulStack<int> A(2, 4);
  A.Put(1, 0);
  A.Put(2, 0);
  A.Put(2, 0);
  A.Put(2, 0);
  EXPECT_EQ(A.GetSize(0), 4);
}

TEST(Multystack, resize_with_another_stack)
{
  TMulStack<int> A(3, 9);
  A.Put(1, 0);
  A.Put(2, 0);

  A.Put(3, 1);
  A.Put(4, 1);
  A.Put(5, 1);

  A.Put(6, 2);
  A.Put(7, 2);

  A.Put(8, 1);
  A.Put(9, 1);

  bool ifEq = true;

  for (int i = 0; i < 2; i++)
    if (A.Get(0) != 2 - i)
      ifEq = false;

  for (int i = 0; i < 2; i++)
    if (A.Get(2) != 7 - i)
      ifEq = false;

  for (int i = 0; i < 2; i++)
    if (A.Get(1) != 9 - i)
      ifEq = false;

  for (int i = 0; i < 3; i++)
    if (A.Get(1) != 5 - i)
      ifEq = false;

  EXPECT_EQ(ifEq, 1);
}

TEST(Multystack, calc_free_in_empty_stack)
{
  TMulStack<int> A(3, 9);
  EXPECT_EQ(A.CalcFree(0), 3);
}