#include <gtest.h>
#include "Point.h"

TEST(Point, can_create)
{
	ASSERT_NO_THROW(Point A());
}

TEST(Point, can_create_with_attributes)
{
	Point A(12, 12);
	EXPECT_EQ(A.GetX() == 12 && A.GetY() == 12, 1);
	
}

TEST(Point, can_set_new_attributes)
{
	Point A(12, 12);
	A.SetX(1);
	A.SetY(114);
	EXPECT_EQ(A.GetX() == 1 && A.GetY() == 114, 1);
}

TEST(Point, is_eq_when_eq)
{
	Point A(13, 12);
	Point B(A);
	EXPECT_EQ(B == A, 1);
}

TEST(Point, is_not_eq_when_not_eq)
{
	Point A(13, 12);
	Point B(A);
	B.SetX(21);
	EXPECT_EQ(B != A, 1);
}

TEST(Point, is_eq_when_not_eq)
{
	Point A(13, 12);
	Point B(A);
	B.SetX(21);
	EXPECT_EQ(B == A, 0);
}

TEST(Point, is_not_eq_when_eq)
{
	Point A(13, 12);
	Point B(A);
	EXPECT_EQ(B != A, 0);
}

TEST(Point, eq)
{
	Point A(13, 12);
	Point B;
	B = A;
	EXPECT_EQ(B == A, 1);
}