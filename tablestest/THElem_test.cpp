#include <gtest.h>
#include "THElem.h"

TEST(THElem, can_create)
{
	ASSERT_NO_THROW(THElem<int> A);
}

TEST(THElem, can_get_value)
{
	THElem<int> A("aa", 10);
	EXPECT_EQ(A.GetValue(), 10);
}

TEST(THElem, can_get_key)
{
	THElem<int> A("aa", 10);
	mString d("aa");
	EXPECT_EQ(A.GetKey() == d, 1);
}

TEST(THElem, can_copy_value)
{
	THElem<int> A("aa", 10);
	THElem<int> B(A);
	EXPECT_EQ(B.GetValue(), 10);
}

TEST(THElem, can_copy_key)
{
	THElem<int> A("aa", 10);
	THElem<int> B(A);
	mString d("aa");
	EXPECT_EQ(B.GetKey() == d, 1);
}

TEST(THElem, eq_key)
{
	THElem<int> A("aa", 10);
	THElem<int> B;
	B = A;
	EXPECT_EQ(B.GetKey() == "aa", 1);
}

TEST(THElem, eq_value)
{
	THElem<int> A("aa", 10);
	THElem<int> B;
	B = A;
	EXPECT_EQ(B.GetValue() == 10, 1);
}

TEST(THElem, neq_key)
{
	THElem<int> A("aa", 10);
	THElem<int> B;
	B = A;
	EXPECT_EQ(B.GetKey() == "a", 0);
}

TEST(THElem, neq_value)
{
	THElem<int> A("aa", 10);
	THElem<int> B;
	B = A;
	EXPECT_EQ(B.GetValue() == 1, 0);
}

TEST(THElem, can_set_value)
{
	THElem<int> A("aa", 10);
	A.SetValue(100);
	EXPECT_EQ(A.GetValue(), 100);
}

TEST(THElem, can_set_key)
{
	THElem<int> A("aa", 10);
	A.SetKey("bbc");
	EXPECT_EQ(A.GetKey() == "bbc", 1);
}