
#include "TVector.h"
#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_lenght)
{
	ASSERT_NO_THROW(TVector<int> A(3));
}

TEST(TVector, cannot_create_vector_with_unpositive_lenght)
{
	ASSERT_ANY_THROW(TVector<int> A(-3));
}

TEST(TVector, cannot_get_value_out_of_range)
{
	TVector<int> A(1);
	A[0] = 1;
	ASSERT_ANY_THROW(A[1]);
}

TEST(TVector, can_get_value_in_range)
{
	TVector<int> A(1);
	A[0] = 1;
	EXPECT_EQ(A[0] , 1);
}

TEST(TVector, plus)
{
	TVector<int> A(3);
	for (int i = 0; i < A.GetSize(); i++)
		A[i] = i;

	TVector<int> B(3);
	for (int i = 0; i < B.GetSize(); i++)
		B[i] = i + 10;

	EXPECT_EQ((A + B)[1], 12);
}

TEST(TVector, plus_expect_throw) 
{
	TVector<int> A(1), B(3);

	ASSERT_ANY_THROW( A + B);
}

TEST(TVector, minus)
{
	TVector<int> A(3);
	for (int i = 0; i < A.GetSize(); i++)
		A[i] = i;

	TVector<int> B(3);
	for (int i = 0; i < B.GetSize(); i++)
		B[i] = i + 10;

	EXPECT_EQ((B - A)[1], 10);
}

TEST(TVector, minus_expect_throw) 
{
	TVector<int> A(1), B(3);

	ASSERT_ANY_THROW(A - B);
}

TEST(TVector, multiplication)
{
	TVector<int> A(3);
	for (int i = 0; i < A.GetSize(); i++)
		A[i] = i;

	TVector<int> B(3);
	for (int i = 0; i < B.GetSize(); i++)
		B[i] = i + 10;

	EXPECT_EQ((B * A)[2], 24);
}

TEST(TVector, multiplication_expect_throw)
{
	TVector<int> A(1), B(3);

	ASSERT_ANY_THROW(A * B);
}
