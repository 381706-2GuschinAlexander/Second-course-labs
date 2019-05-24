#include <iostream>
#include "StackList.h"

int main()
{
  
  
  int nextStep = 1;
  std::cout << "\n";
  TStackList<int> A;

  while (nextStep)
  {
    std::cout << "Put - 1; Get - 2, Exit - 0\n";
    std::cout << "Your choice: ";
    std::cin >> nextStep;
    if (nextStep == 1)
    {
      int tmp;
      std::cin >> tmp;
      A.Put(tmp);
    }
    if (nextStep == 2)
    {
      std::cout << A.Get() << "\n";
    }
  }
  return 0;
}