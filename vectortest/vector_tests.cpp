#include "TVector.h"
#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_lenght)
{
	ASSERT_NO_THROW(TVector<int> A(3, 0));
}

TEST(TVector, throws_when_create_vector_with_unpositive_lenght)
{
	ASSERT_ANY_THROW(TVector<int> A(-3, 0));
}

TEST(TVector, throws_when_get_value_out_of_range)
{
	TVector<int> A(1, 0);
	A[0] = 1;
	ASSERT_ANY_THROW(A[1]);
}

TEST(TVector, can_get_value_in_range)
{
	TVector<int> A(1, 0);
	A[0] = 1;
	EXPECT_EQ(A[0] , 1);
}

TEST(TVector, plus)
{
	TVector<int> A(3, 0);
	for (int i = 0; i < A.GetSize(); i++)
		A[i] = i;

	TVector<int> B(3, 0);
	for (int i = 0; i < B.GetSize(); i++)
		B[i] = i + 10;

	EXPECT_EQ((A + B)[1], 12);
}

TEST(TVector, plus_const) 
{
	TVector<int> A(3, 0);
	for (int i = 0; i < A.GetSize(); i++)
		A[i] = i;
	int k = 5;
	EXPECT_EQ((A + k)[1], 6);
}


TEST(TVector, throws_when_plus_expect_throw)
{
	TVector<int> A(1, 0), B(3, 0);

	ASSERT_ANY_THROW(A + B);
}


TEST(TVector, minus)
{
	TVector<int> A(3, 0);
	for (int i = 0; i < A.GetSize(); i++)
		A[i] = i;

	TVector<int> B(3, 0);
	for (int i = 0; i < B.GetSize(); i++)
		B[i] = i + 10;

	EXPECT_EQ((B - A)[1], 10);
}

TEST(TVector, minus_const)
{
	TVector<int> A(3, 0);
	for (int i = 0; i < A.GetSize(); i++)
		A[i] = i;

	int k = 1;

	EXPECT_EQ((A - k)[1], 0);
}

TEST(TVector, throws_when_minus_expect_throw)
{
	TVector<int> A(1, 0), B(3, 0);

	ASSERT_ANY_THROW(A - B);
}

TEST(TVector, multiplication)
{
	TVector<int> A(3, 0);
	for (int i = 0; i < A.GetSize(); i++)
		A[i] = i;

	TVector<int> B(3, 0);
	for (int i = 0; i < B.GetSize(); i++)
		B[i] = i + 10;

	EXPECT_EQ((B * A)[2], 24);
}

TEST(TVector, multiplication_const)
{
	TVector<int> A(3, 0);
	for (int i = 0; i < A.GetSize(); i++)
		A[i] = i;

	int k = 2;

	EXPECT_EQ((A * k)[2], 4);
}


TEST(TVector, throws_when_multiplication_expect_throw)
{
	TVector<int> A(1, 0), B(3, 0);

	ASSERT_ANY_THROW(A * B);
}

TEST(TVector, vector_equality_if_eq)
{
	TVector<int> A(2, 0), B(2, 0);
	
	A[0] = 1;
	A[1] = 2;
	B[0] = 1;
	B[1] = 2;

	EXPECT_EQ(A == B, true);
}

TEST(TVector, vector_equality_if_uneq)
{
	TVector<int> A(2, 0), B(2, 0);

	A[0] = 1;
	A[1] = 2;
	B[0] = 1;
	B[1] = 3;

	EXPECT_EQ(A == B, false);
}

TEST(TVector, vector_equality_if_diff_size)
{
	TVector<int> A(1, 0), B(2, 0);

	EXPECT_EQ(A == B, false);
}

TEST(TVector, get_size)
{
	TVector<int> A(100, 0);
	EXPECT_EQ(A.GetSize(), 100);
}