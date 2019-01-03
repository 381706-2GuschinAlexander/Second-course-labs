#include <gtest.h>
#include "Stack.h"

TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> s(3));
}


TEST(TStack, can_create_stack_with_zero_size)
{
  ASSERT_NO_THROW(TStack<int> s(0));
}

TEST(TStack, throw_when_create_with_negative_size)
{
  ASSERT_ANY_THROW(TStack<int> s(-3));
}

TEST(TStack, can_get_size)
{
  TStack<int> st(50);

  EXPECT_EQ(50, st.GetSize());
}

TEST(TStack, IsEmpty_when_empty)
{
  TStack<int> st(1);

  EXPECT_EQ(1, st.IsEmpty());
}

TEST(TStack, IsEmpty_when_full)
{
  TStack<int> st(1);
  st.Put(1);

  EXPECT_EQ(0, st.IsEmpty());
}

TEST(TStack, IsFull_when_empty)
{
  TStack<int> st(1);
  EXPECT_EQ(0, st.IsFull());
}

TEST(TStack, IsFull_when_full)
{
  TStack<int> st(1);
  st.Put(1);
  EXPECT_EQ(1, st.IsFull());
}

TEST(TStack, throw_when_put_in_full_stack)
{
  TStack<int> st(2);
  for (int i = 0; i < 2; i++)
   st.Put(3);
  ASSERT_ANY_THROW(st.Put(3));
}

TEST(TStack, can_put_value)
{
  TStack<int> st(10);

  ASSERT_NO_THROW(st.Put(3));
}

TEST(TStack, can_put_multyply_times)
{
  TStack<int> st(10);
  st.Put(6);
  st.Put(5);
  EXPECT_EQ(5, st.Get());
}

TEST(TStack, can_get_value)
{
  TStack<int> st(10);
  st.Put(77);
  EXPECT_EQ(77, st.Get());
}

TEST(TStack, throw_when_get_from_empty_stack)
{
  TStack<int> st(1);
  ASSERT_ANY_THROW(st.Get());
}