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