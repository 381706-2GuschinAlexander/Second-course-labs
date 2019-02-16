#include "Matrix.h"
#include <gtest.h>

TMatrix<int> A1(100);
TMatrix<int> A2(200);
TMatrix<int> A3(300);
TMatrix<int> A4(400);
TMatrix<int> A5(500);

TEST(TMatrix, 100)
{ 
  ASSERT_NO_THROW(A1 * A1);
}

TEST(TMatrix, 200)
{
  ASSERT_NO_THROW(A2 * A2);
}

TEST(TMatrix, 300)
{
  ASSERT_NO_THROW(A3 * A3);
}

TEST(TMatrix, 400)
{
  ASSERT_NO_THROW(A4 * A4);
}

TEST(TMatrix, 500)
{
  ASSERT_NO_THROW(A5 * A5);
}