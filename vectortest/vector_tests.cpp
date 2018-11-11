
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

TEST(TVector, biggest_plus_smallest)
{
	TVector<int> A(3);
	for (int i = 0; i < A.GetSize(); i++)
		A[i] = i;

	TVector<int> B(1);
	for (int i = 0; i < B.GetSize(); i++)
		B[i] = i + 10;

	ASSERT_NO_THROW(A + B);
}



TEST(TVector, biggest_plus_smallest_EQ)//unexpected error
{
	TVector<int> A(3);
	for (int i = 0; i < A.GetSize(); i++)
		A[i] = i;

	TVector<int> B(3);
	for (int j = 0; j < B.GetSize(); j++)
		B[j] = j + 10;

	TVector<int> C(3);
	C = A + B;
	EXPECT_EQ(C[1], 12);
}