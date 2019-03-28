#include <iostream>
#include "List.h"
#include <time.h> 


int main()
{
/*
  List<double> B, C, D;
  for (int i = 0; i < 1000000; i++)
    B.InsFirst(1.0);
  for (int i = 0; i < 2000000; i++)
    C.InsFirst(1.0);
  for (int i = 0; i < 3000000; i++)
    D.InsFirst(1.0);

  float fTimeStart = clock()/(float)CLOCKS_PER_SEC;
  B.InsCustom(1.12, 1000000 - 1);
  float fTimeStop = clock()/ (float)CLOCKS_PER_SEC;
  std::cout << "time: " << fTimeStop - fTimeStart << "\n";

  fTimeStart = clock() / (float)CLOCKS_PER_SEC;
  C.InsCustom(1.12, 2000000 - 1);
  fTimeStop = clock() / (float)CLOCKS_PER_SEC;
  std::cout << "time: " << fTimeStop - fTimeStart << "\n";

  fTimeStart = clock() / (float)CLOCKS_PER_SEC;
  D.InsCustom(1.12, 3000000 - 1);
  fTimeStop = clock() / (float)CLOCKS_PER_SEC;
  std::cout << "time: " << fTimeStop - fTimeStart << "\n";
*/
  List<double> A;
  std::cout << "Insert on first pos 1.1\n";
  A.InsFirst(1.1);
  std::cout << "Insert on last pos 2.2\n";
  A.InsLast(2.2);
  std::cout << "Insert on 1 pos 1.15\n";
  A.InsCustom(1.15, 1);

  std::cout << "length: " << A.GetLen() << "\n";
  for (int i = 0; i < A.GetLen(); i++)
    std::cout << i<<" pos: " << A.GetValue(i) << "\n";

  std::cout << "delete pos 1\n";
  A.DelCustom(1);

  std::cout << "length: " << A.GetLen() << "\n";
  for (int i = 0; i < A.GetLen(); i++)
    std::cout << i << " pos: " << A.GetValue(i) << "\n";

  return 0;
}