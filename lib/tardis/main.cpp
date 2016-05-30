#include <iostream>
#include "my_mem.h"
#include "my.h"

int	main(void)
{
  TARDIS_Init();
  int*  a = new int;
  double* b = new double;
  *a = 42;
  *b = *a * 2;
  std::cout << *a << "," << *b << std::endl;
  return 0;
}
