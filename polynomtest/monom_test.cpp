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

TEST(Monom, throw_when_create_monom_with_negative_powers)
{
  int p[] = { -3, -4, -5};
  ASSERT_ANY_THROW(Monom(3, 4.5, p));
}

TEST(Monom, throw_when_create_monom_with_negative_n)
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

TEST(Monom, can_get_n)
{
  int p[] = { 3, 4, 5 };
  Monom A(3, 4.5, p);

  bool res = true;
  if (A.GetN() != 3)
    res = false;

  EXPECT_EQ(res, 1);
}

TEST(Monom, can_get_const)
{
  int p[] = { 3, 4, 5 };
  Monom A(3, 4.5, p);

  bool res = true;
  if (A.GetCon() != 4.5)
    res = false;

  EXPECT_EQ(res, 1);
}

TEST(Monom, can_get_powers)
{
  int p[] = { 3, 4, 5 };
  Monom A(3, 4.5, p);

  bool res = true;
  for (int i = 0; i < A.GetN(); i++)
    if ((A.GetPow())[i] != 3 + i)
      res = false;

  EXPECT_EQ(res, 1);
}

TEST(Monom, can_set_const)
{
  int p[] = { 3, 4, 5 };
  Monom A(3, 4.5, p);

  A.SetCon(-3.5);

  bool res = true;
  if (A.GetCon() != -3.5)
    res = false;

  EXPECT_EQ(res, 1);
}

TEST(Monom, can_set_powers)
{
  int p[] = { 3, 4, 5 };
  int pPlus[] = { 4, 5, 6 };
  Monom A(3, 4.5, p);

  A.SetPow(pPlus);

  bool res = true;
  for (int i = 0; i < A.GetN(); i++)
    if ((A.GetPow())[i] != 4 + i)
      res = false;

  EXPECT_EQ(res, 1);
}


TEST(Monom, can_set_small_n)
{
  int p[] = { 3, 4, 5 };
  Monom A(3, 4.5, p);

  A.SetN(2);

  bool res = true;
  for (int i = 0; i < A.GetN(); i++)
    if ((A.GetPow())[i] != 3 + i)
      res = false;

  EXPECT_EQ(res, 1);
}

TEST(Monom, can_set_big_n)
{
  int p[] = { 3, 4, 5 };
  Monom A(3, 4.5, p);

  A.SetN(10);

  bool res = true;
  for (int i = 0; i < 3; i++)
    if ((A.GetPow())[i] != 3 + i)
      res = false;

  for (int i = 3; i < A.GetN(); i++)
    if ((A.GetPow())[i] != 0)
      res = false;

  EXPECT_EQ(res, 1);
}

TEST(Monom, throw_when_set_negative_n)
{
  int p[] = { 3, 4, 5 };
  Monom A(3, 4.5, p);

  ASSERT_ANY_THROW(A.SetN(-1));
}

TEST(Monom, can_eq)
{
  int p[] = { 3, 4, 5 };
  int sec[] = {3};
  Monom A(3, 4.5, p);

  Monom B(1, 1, sec);
  B = A;

  bool res = true;
  if (B.GetCon() != A.GetCon())
    res = false;
  if (B.GetN() != A.GetN())
    res = false;
  for (int i = 0; i < A.GetN(); i++)
    if ((B.GetPow())[i] != 3 + i)
      res = false;

  EXPECT_EQ(res, 1);
}


TEST(Monom, eq_when_not_eq)
{
  int p[] = { 3, 4, 5 };
  int sec[] = { 3 };
  Monom A(3, 4.5, p);
  Monom B(1, 1, sec);

  EXPECT_EQ(A == B, 0);
}

TEST(Monom, eq_when_eq)
{
  int p[] = { 3, 4, 5 };
  int sec[] = { 3, 4, 5 };
  Monom A(3, 4.5, p);
  Monom B(3, 4.5, sec);

  EXPECT_EQ(A == B, 1);
}

TEST(Monom, comparison_B_when_first_bigger_then_second)
{
  int p[] = { 3, 4, 5 };
  int sec[] = { 3, 4, 5 };
  Monom A(3, 4.5, p);
  Monom B(3, 3.5, sec);

  EXPECT_EQ(A > B, 1);
}

TEST(Monom, comparison_B_when_first_smaller_then_second)
{
  int p[] = { 3, 4, 5 };
  int sec[] = { 3, 4, 5 };
  Monom A(3, 2.5, p);
  Monom B(3, 3.5, sec);

  EXPECT_EQ(A > B, 0);
}

TEST(Monom, comparison_S_when_first_bigger_then_second)
{
  int p[] = { 3, 4, 5 };
  int sec[] = { 3, 4, 5 };
  Monom A(3, 4.5, p);
  Monom B(3, 3.5, sec);

  EXPECT_EQ(A < B, 0);
}

TEST(Monom, comparison_S_when_first_smaller_then_second)
{
  int p[] = { 3, 4, 5 };
  int sec[] = { 3, 4, 5 };
  Monom A(3, 2.5, p);
  Monom B(3, 3.5, sec);

  EXPECT_EQ(A < B, 1);
}

TEST(Monom, throw_when_comparison_with_different_powers)
{
  int p[] = { 3, 4, 5 };
  int sec[] = { 3, 5 };
  Monom A(3, 4.5, p);
  Monom B(2, 3.5, sec);

  ASSERT_ANY_THROW(A < B);
}