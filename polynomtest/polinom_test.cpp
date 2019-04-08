#include <gtest.h>
#include "Polynom.h"

TEST(Polynom, can_create_polynom)
{
  ASSERT_NO_THROW(Polynom A);
}

TEST(Polynom, can_add_diff_monoms_in_polynom)
{
  int p[] = { 3, 4, 5 };
  Monom B(3, 4.5, p);
  int p1[] = {4, 5};
  Monom C(2, -12, p1);

  Polynom A1, A2;

  A1.InsLast(B);
  A1.InsLast(C);

  A2 += B;
  A2 += C;

  bool flag = 1;
  if (A1.GetLen() != A2.GetLen())
    flag = 0;
  for (int i = 0; i < A1.GetLen() && flag; i++)
   if(A1.GetValue(i) != A2.GetValue(i)) 
     flag = 0;

  EXPECT_EQ(flag, 1);
}

TEST(Polynom, can_add_same_monoms_in_polynom)
{
  int p[] = { 3, 4, 5 };
  Monom B(3, 4.5, p);
  int sec[] = { 3, 4, 5 };
  Monom D(3, 9, p);


  Polynom A1, A2;

  A1.InsLast(D);

  A2 += B;
  A2 += B;

  bool flag = 1;
  if (A1.GetLen() != A2.GetLen())
    flag = 0;
  for (int i = 0; i < A1.GetLen() && flag; i++)
    if (A1.GetValue(i) != A2.GetValue(i))
      flag = 0;

  EXPECT_EQ(flag, 1);
}

TEST(Polynom, can_add_opositive_monom_in_polynom)
{
  int p[] = { 3, 4, 5 };
  Monom B(3, 4.5, p);
  

  Polynom A;


  A += B;
  B.SetCon(-4.5);
  A += B;

  EXPECT_EQ(A.GetLen(), 0);
}

TEST(Polynom, can_create_polinom_with_another_polinom)
{
  int p[] = { 3, 4, 5 };
  Monom B(3, 4.5, p);

  Polynom A1;
  A1 += B;
  Polynom A2(A1);

  bool flag = 1;
  if (A1.GetLen() != A2.GetLen())
    flag = 0;
  for (int i = 0; i < A1.GetLen() && flag; i++)
    if (A1.GetValue(i) != A2.GetValue(i))
      flag = 0;

  EXPECT_EQ(flag, 1);
}

TEST(Polynom, can_create_polinom_with_correct_list)
{
  int p[] = { 3, 4, 5 };
  Monom B(3, 4.5, p);

  List<Monom> A1;
  A1.InsLast(B);
  Polynom A2(A1);

  bool flag = 1;
  if (A1.GetLen() != A2.GetLen())
    flag = 0;
  for (int i = 0; i < A1.GetLen() && flag; i++)
    if (A1.GetValue(i) != A2.GetValue(i))
      flag = 0;

  EXPECT_EQ(flag, 1);
}

TEST(Polynom, can_create_polinom_with_incorrect_list)
{
  int p[] = { 3, 4, 5 };
  Monom B(3, 4.5, p);

  List<Monom> A1;
  A1.InsLast(B);
  A1.InsLast(B);
  
  Polynom A2(A1), A3;
  A3 += B;
  A3 += B;

  bool flag = 1;
  if (A3.GetLen() != A2.GetLen())
    flag = 0;
  for (int i = 0; i < A3.GetLen() && flag; i++)
    if (A3.GetValue(i) != A2.GetValue(i))
      flag = 0;

  EXPECT_EQ(flag, 1);
}


TEST(Polynom, can_get_monom_from_polynom)
{
  int p[] = { 3, 4, 5 };
  Monom B(3, 4.5, p);

  Polynom A;

  A += B;
  bool flag = (A.GetValue(0) == A[0] ? 1 : 0);
  EXPECT_EQ(flag, 1);
}

TEST(Polynom, can_plus_with_polynom)
{
  int p[] = { 3, 4, 5 };
  int p2[] = {3, 4};
  Monom B(3, 4.5, p);
  Monom C(2, 7.5, p2);

  Polynom Pol1, Pol2;

  Pol1 += B;

  Pol2 += C;
  Pol2 += B;

  Polynom Pol3(Pol1 + Pol2);
  
  bool flag = 1;
  if (Pol3.GetLen() != 2)
    flag = 0;
  if (Pol3[0] != B + B)
    flag = 0;
  if (Pol3[1] != C)
    flag = 0;

  EXPECT_EQ(flag, 1);
}

TEST(Polynom, can_minus_with_polynom)
{
  int p[] = { 3, 4, 5 };
  int p2[] = { 3, 4 };
  Monom B(3, 4.5, p);
  Monom C(2, 7.5, p2);

  Polynom Pol1, Pol2;

  Pol1 += B;

  Pol2 += C;
  Pol2 += B;

  Polynom Pol3(Pol1 - Pol2);

  bool flag = 1;
  if (Pol3.GetLen() != 1)
    flag = 0;
  C.SetCon(-7.5);
  if (Pol3[0] != C)
    flag = 0;

  EXPECT_EQ(flag, 1);
}
