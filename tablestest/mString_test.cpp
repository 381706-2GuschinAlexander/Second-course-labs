#include <gtest.h>
#include "mString.h"

TEST(mString, can_create)
{
	ASSERT_NO_THROW(mString A);
}

TEST(mString, can_create_with_char_arr)
{
	char a[] = { "a" };
	mString A(a);
	EXPECT_EQ(A.GetCStr()[0] == a[0], 1);
}

TEST(mString, can_create_with_another_string)
{
	char a[] = { "a" };
	mString A(a);
	mString B(A);
	EXPECT_EQ(A.GetCStr()[0] == B.GetCStr()[0], 1);
}

TEST(mString, can_eq_with_another_string)
{
	char a[] = { "a" };
	mString A(a);
	mString B = A;
	EXPECT_EQ(A.GetCStr()[0] == B.GetCStr()[0], 1);
}

TEST(mString, can_create_with_another_char_arr)
{
	char a[] = { "a" };
	mString A(a);
	mString B = a;
	EXPECT_EQ(A.GetCStr()[0] == B.GetCStr()[0], 1);
}

TEST(mString, can_bigger_or_eq)
{
	char a[] = { "aaa" };
	char b[] = { "zz" };
	mString A(a);
	mString B(b);
	EXPECT_EQ(A >= B, 1);
}

TEST(mString, can_smaller_or_eq)
{
	char a[] = { "aaaa" };
	char b[] = { "zzz" };
	mString A(a);
	mString B(b);
	EXPECT_EQ(B <= A, 1);
}

TEST(mString, eq_when_eq)
{
	char a[] = { "aaa" };
	char b[] = { "aaa" };
	mString A(a);
	mString B(b);
	EXPECT_EQ(B == A, 1);
}

TEST(mString, eq_when_not_eq)
{
	char a[] = { "abc" };
	char b[] = { "aaa" };
	mString A(a);
	mString B(b);
	EXPECT_EQ(B == A, 0);
}

TEST(mString, nEq_when_eq)
{
	char a[] = { "aaa" };
	char b[] = { "aaa" };
	mString A(a);
	mString B(b);
	EXPECT_EQ(B != A, 0);
}

TEST(mString, nEq_when_not_eq)
{
	char a[] = { "abc" };
	char b[] = { "aaa" };
	mString A(a);
	mString B(b);
	EXPECT_EQ(B != A, 1);
}

TEST(mString, can_get_count)
{
	char a[] = { "abc" };
	mString A(a);
	EXPECT_EQ(A.GetCount(), 3);
}

