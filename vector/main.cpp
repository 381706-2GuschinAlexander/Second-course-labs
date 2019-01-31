#include "Matrix.h"
#include <iostream>


int main()
{
  TMatrix<double> A(3), B(3);
  std::cout << "Enter first Matrix\n";
  std::cin >> A;
  std::cout << "\nEnter second Matrix\n";
  std::cin >> B;
  std::cout << TMatrix<double>(A * B);
  return 0;
}