#include <iostream>
#include "ArrList.h"

int main()
{
  ArrList<double> A(3);
  std::cout << "Insert on first pos 1.1\n";
  A.InsFirst(1.1);
  std::cout << "Insert on last pos 2.2\n";
  A.InsLast(2.2);
  std::cout << "Insert on 1 pos 1.15\n";
  A.InsFirst(1.15);

  std::cout << "length: " << A.GetLen() << "\n";

  std::cout << "0 pos: " << A.GetFirst() << "\n";
  std::cout << "length: " << A.GetLen() << "\n";
  
  std::cout << "1 pos: " << A.GetFirst() << "\n";
  std::cout << "length: " << A.GetLen() << "\n";

  std::cout << "1 pos: " << A.GetFirst() << "\n";
  std::cout << "length: " << A.GetLen() << "\n";
  return 0;
}