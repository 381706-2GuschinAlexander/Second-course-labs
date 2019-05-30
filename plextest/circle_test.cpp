#include <gtest.h>
#include "Circle.h"

TEST(Circle, can_create)
{
	ASSERT_NO_THROW(Circle A);
}

TEST(Circle, can_create_with_attributes)
{
	Point A(12, 21);
	ASSERT_NO_THROW(Circle B(A, 21));
}

TEST(Circle, can_set)
{
	Point A(12, 21);
	Circle C(A, 21);
	C.SetC(12, 12);
	EXPECT_EQ(C.GetX() == C.GetY(), 1);
}