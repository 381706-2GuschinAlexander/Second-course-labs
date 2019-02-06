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

//add ? test for IF

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
  A.Get(3);
  EXPECT_EQ(A.Get(3), 2);
}

//add ? test for put/get in full_stack&not_full_MS
//add test for resize()

TEST(Multystack, calc_free_in_empty_stack)
{
  TMulStack<int> A(3, 9);
  EXPECT_EQ(A.CalcFree(0), 3);
}