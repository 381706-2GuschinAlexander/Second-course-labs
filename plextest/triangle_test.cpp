#include <gtest.h>
#include "Triangle.h"

TEST(Triangle, can_create)
{
	ASSERT_NO_THROW(Triangle a);
}

TEST(Triangle, can_create_with_attribute)
{
	Point a(12, 21);
	Point b(122, 11);
	Point c(155, 211);
	ASSERT_NO_THROW(Triangle A(a, b ,c));
}

TEST(Triangle, can_get_len)
{
	Point a(0, 0);
	Point b(100, 100);
	Point c(200, 200);
	Triangle A(a, b, c);
	EXPECT_EQ(A.LenAB() == A.LenBC(), 1);
}

TEST(Triangle, can_set)
{
	Point a(0, 0);
	Point b(100, 100);
	Point c(200, 200);
	Triangle A(a, b, c);
	A.SetA(12, 11);
	EXPECT_EQ(A.GetX1() == 12 && A.GetY1() == 11, 1);
}