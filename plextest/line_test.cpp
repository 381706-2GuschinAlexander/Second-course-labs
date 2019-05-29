#include <gtest.h>
#include "Line.h"

TEST(Line, can_create)
{
	ASSERT_NO_THROW(Line A);
}

TEST(Line, can_create_with_attribites)
{
	Line A(12,12,12,12);
	EXPECT_EQ(A.GetA() == A.GetB(), 1);
}

TEST(Line, can_set)
{
	Line A(12, 213, 1, 12);
	A.SetX1(11);
	A.SetY1(11);
	A.SetX2(11);
	A.SetY2(11);
	EXPECT_EQ(A.GetA() == A.GetB(), 1);
}

TEST(Line, can_get)
{
	Line A(12, 213, 12, 12);
	
	EXPECT_EQ(A.GetX1() == A.GetX2(), 1);
	EXPECT_EQ(A.GetY1() != A.GetY2(), 1);
}

TEST(Line, eq)
{
	Line A(12, 213, 12, 12);
	Line B(A);
	
	EXPECT_EQ(A == B, 1);
}

TEST(Line, is_eq_when_eq)
{
	Line A(12, 213, 12, 12);
	Line B(A);

	EXPECT_EQ(A == B, 1);
}

TEST(Line, is_eq_when_not_eq)
{
	Line A(12, 213, 12, 12);
	Line B(A);
	B.SetY1(1222);

	EXPECT_EQ(A == B, 0);
}

TEST(Line, is_not_eq_when_eq)
{
	Line A(12, 213, 12, 12);
	Line B(A);

	EXPECT_EQ(A != B, 0);
}

TEST(Line, is_not_eq_when_not_eq)
{
	Line A(12, 213, 12, 12);
	Line B(A);
	B.SetY1(1222);

	EXPECT_EQ(A != B, 1);
}