#include <gtest.h>
#include "Stack.h"

TEST(Stack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(Stack<int> s(3));
}


TEST(Stack, can_create_stack_with_zero_size)
{
  ASSERT_NO_THROW(Stack<int> s(0));
}

TEST(Stack, cannot_create_with_negative_size)
{
  ASSERT_ANY_THROW(Stack<int> s(-3));
}

TEST(Stack, can_get_size)
{
  Stack<int> st(50);

  EXPECT_EQ(50, st.GetSize());
}

TEST(Stack, IsEmpty_when_empty)
{
  Stack<int> st(1);

  EXPECT_EQ(1, st.IsEmpty());
}

TEST(Stack, IsEmpty_when_full)
{
  Stack<int> st(1);
  st.Put(1);

  EXPECT_EQ(0, st.IsEmpty());
}

TEST(Stack, IsFull_when_empty)
{
  Stack<int> st(1);
  EXPECT_EQ(0, st.IsFull());
}

TEST(Stack, IsFull_when_full)
{
  Stack<int> st(1);
  st.Put(1);
  EXPECT_EQ(1, st.IsFull());
}

TEST(Stack, cannot_put_in_full_stack)
{
  Stack<int> st(2);
  for (int i = 0; i < 2; i++)
   st.Put(3);
  ASSERT_ANY_THROW(st.Put(3));
}

TEST(Stack, can_put_value)
{
  Stack<int> st(10);

  ASSERT_NO_THROW(st.Put(3));
}

TEST(Stack, can_put_multyply_times)
{
  Stack<int> st(10);
  st.Put(6);
  st.Put(5);
  EXPECT_EQ(5, st.Get());
}

TEST(Stack, can_get_value)
{
  Stack<int> st(10);
  st.Put(77);
  EXPECT_EQ(77, st.Get());
}

TEST(Stack, cannot_get_from_empty_stack)
{
  Stack<int> st(1);
  ASSERT_ANY_THROW(st.Get());
}