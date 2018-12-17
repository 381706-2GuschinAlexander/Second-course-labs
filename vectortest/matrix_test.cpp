#include "Matrix.h"
#include <gtest.h>

TEST(Matrix, can_create_matrix_with_positive_n)
{
	ASSERT_NO_THROW(Matrix<int> A(3));
}

TEST(Matrix, can_create_matrix_with_negative_n)
{
	ASSERT_ANY_THROW(Matrix<int> A(-3));
}

TEST(Matrix, can_get_value_in_range)
{
	Matrix<int> A(3);
	A[0][2] = 10;
	A[2][0] = 5;
	EXPECT_EQ(A[0][2] - A[2][0], 5);
}

TEST(Matrix, can_get_value_out_of_range)
{
	Matrix<int> A(3);
	ASSERT_ANY_THROW(A[0][3]);
}

TEST(Matrix, can_create_matrix_with_matrix)
{
	Matrix<int> B(3);
	B[0][0] = 12;
	Matrix<int> A(B);
	EXPECT_EQ(B[0][0],A[0][0]);
}

TEST(Matrix, can_create_matrix_with_double_vectors)
{
	TVector <TVector<int>> A(1);
	TVector<int> C(1);
	A[0] = C;
	A[0][0] = 1;
	Matrix<int> B(A);
	EXPECT_EQ(B[0][0] , 1);
}

TEST(Matrix, can_create_matrix_with_invalid_double_vectors)
{
	TVector <TVector<int>> A(2);
	TVector<int> C(2);
	A[0] = C;
	A[1] = C;

	ASSERT_ANY_THROW(Matrix<int> B(A));
}

TEST(Matrix, matrix_eq_with_diff_lenght)
{
	Matrix<int> A(2);
	Matrix<int> B(3);

	EXPECT_EQ(A == B, false);
}

TEST(Matrix, matrix_eq_with_diff_matrix)
{
	Matrix<int> A(1);
	A[0][0] = 1;
	Matrix<int> B(1);
	B[0][0] = 2;

	EXPECT_EQ(A == B, false);
}

TEST(Matrix, matrix_eq_with_same_matrix)
{
	Matrix<int> A(1);
	A[0][0] = 2;
	Matrix<int> B(1);
	B[0][0] = 2;
	EXPECT_EQ(A == B, true);
}


TEST(Matrix, can_eq_matrix)
{
	Matrix<int> C(1);
	C[0][0] = 1;
	
	Matrix<int> B(3);
	B = C;

	EXPECT_EQ(B[0][0], 1);
}

TEST(Matrix, plus_with_invalid_matrix)
{
	Matrix<int> A(3);
	Matrix<int> B(2);

	ASSERT_ANY_THROW(A + B);
}

TEST(Matrix, plus_with_matrix)
{
	Matrix<int> A(1);
	Matrix<int> B(1);

	A[0][0] = 4;
	B[0][0] = 3;
	A = A + B;
	EXPECT_EQ(A[0][0], 7);
}

TEST(Matrix, minus_with_invalid_matrix)
{
	Matrix<int> A(3);
	Matrix<int> B(2);

	ASSERT_ANY_THROW(A - B);
}

TEST(Matrix, minus_with_matrix)
{
	Matrix<int> A(1);
	Matrix<int> B(1);

	A[0][0] = 4;
	B[0][0] = 3;
	A = A - B;
	EXPECT_EQ(A[0][0], 1);
}

TEST(Matrix, multiply_with_invalid_matrix)
{
	Matrix<int> A(2);
	Matrix<int> B(1);

	ASSERT_ANY_THROW(A * B);
}

TEST(Matrix, multiply_with_matrix)
{
	Matrix<int> A(3);
	Matrix<int> B(3);
	Matrix<int> C(3);
	Matrix<int> D(3);
	for(int i = 0; i < 3; i++)
	  for (int j = 0; j < 3 - i; j++)
		{
			A[i][j] = B[i][j] = 1;
			C[i][j] = 3 - i - j;
			D[i][j] = 0;
		}
  D = A * B;
  bool d = (D == C ? 1 : 0);
  EXPECT_EQ(d, 1);
}