#include <iostream>
#include "Queue.h"

int main()
{
  int nextStep = 1;
  int size = -1;
  std::cout << "Enter size:";
  std::cin >> size;
  std::cout << "\n";
  TQueue<int> A(size);

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