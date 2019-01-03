#include <gtest.h>
#include "Queue.h"

TEST(TQueue, can_create_with_positive_size)
{
  ASSERT_NO_THROW(TQueue<int> s(3));
}

TEST(TQueue, can_create_with_zero_size)
{
  ASSERT_NO_THROW(TQueue<int> s(0));
}

TEST(TQueue, throw_when_create_with_negative_size)
{
  ASSERT_ANY_THROW(TQueue<int> s(-3));
}

TEST(TQueue, can_get_size)
{
  TQueue<int> st(50);

  EXPECT_EQ(50, st.GetSize());
}

TEST(TQueue, IsEmpty_when_empty)
{
  TQueue<int> st(1);

  EXPECT_EQ(1, st.IsEmpty());
}

TEST(TQueue, IsEmpty_when_full)
{
  TQueue<int> st(1);
  st.Put(1);

  EXPECT_EQ(0, st.IsEmpty());
}

TEST(TQueue, IsFull_when_empty)
{
  TQueue<int> st(1);
  EXPECT_EQ(0, st.IsFull());
}

TEST(TQueue, IsFull_when_full)
{
  TQueue<int> st(1);
  st.Put(1);
  EXPECT_EQ(1, st.IsFull());
}

TEST(TQueue, throw_when_put_in_full_stack)
{
  TQueue<int> st(2);
  for (int i = 0; i < 2; i++)
   st.Put(3);
  ASSERT_ANY_THROW(st.Put(3));
}

TEST(TQueue, can_put_and_get_multyply_times)
{
  TQueue<int> st(10);
  int res = -1;
  for (int i = 0; i < 10; i++)
    st.Put(i);
  for (int i = 0; i < 5; i++)
    res = st.Get();
  st.Put(99);
  res = st.Get();
  EXPECT_EQ(5, res);
}


TEST(TQueue, throw_when_get_from_empty_stack)
{
  TQueue<int> st(1);
  ASSERT_ANY_THROW(st.Get());
}