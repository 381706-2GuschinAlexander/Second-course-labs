#include <gtest.h>
#include "Polynom.h"

TEST(Monom, can_create_monom)
{
  ASSERT_NO_THROW(Monom());
}

TEST(Monom, can_create_monom_with_valid_attributes)
{
  int p[] = { 3, 4, 5 };
  ASSERT_NO_THROW(Monom(3, 4.5, p));
}

TEST(Monom, can_create_monom_with_negative_powers)
{
  int p[] = { -3, -4, -5};
  ASSERT_ANY_THROW(Monom(3, 4.5, p));
}

TEST(Monom, can_create_monom_with_invalid_powers)
{
  int p[] = {3, 4};
  ASSERT_ANY_THROW(Monom(3, 4.5, p));
}

TEST(Monom, can_create_monom_with_negative_n)
{
  int p[] = { 3, 4, 5 };
  ASSERT_ANY_THROW(Monom(-3, 4.5, p));
}

TEST(Monom, can_create_monom_with_monom)
{
  int p[] = { 3, 4, 5};
  Monom A(3, 4.5, p);
  
  Monom B(A);

  bool res = true;
  if (B.GetCon() != A.GetCon())
    res = false;
  if (B.GetN() != A.GetN())
    res = false;
  for(int i = 0; i < A.GetN(); i++)
    if ((B.GetPow())[i] != 3 + i)
      res = false;

  EXPECT_EQ(res, 1);
}