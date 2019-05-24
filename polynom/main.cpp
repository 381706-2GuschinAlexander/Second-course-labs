#include <iostream>
#include "Polynom.h"

int main()
{
  Polynom pol;
  int p1[] = { 3, 4, 5 };
  Monom mon1(3, 4.5, p1);

  int p2[] = { 3, 4 };
  Monom mon2(2, 3.5, p2);

  pol += mon1;
  pol += mon2;
  std::cout <<"polynom: " << pol <<"\n";
  std::cout <<"polynom^2: " << pol * pol << "\n";
  std::cout <<"polynom^2 + polynom: " << pol * pol + pol << "\n";
  std::cout <<"2 * polynom - polynom: " << pol + pol - pol << "\n";

  return 0;
}