#include "loops.h"
#include "functions.h"
#include "switch.h"
#include <stdio.h>
#include <stdlib.h>

int mul(int a)
{
  return a * 2;
}

int main(void)
{
  char* tab[4] = {"Hello", "World", "Nested", "Functions"};
  int a = 40;
  int titi[5] = {0, 1, 2, 3, 4};
  int *toto;

  FOR_EACH(tab, 4, LAMBDAC(void, (char* str), { printf("%s\n", str); }));
  printf("%d\n", ({a + 2;}));
  toto = FOR_YIELD(titi, 5, LAMBDAC(int, (int nb), { return (nb * 2); }));
  FOR_EACH(toto, 5, LAMBDAC(void, (int nb), { printf("%d\n", nb); }));
  free(toto);
  SWITCH(a)
    CASE(40)
      printf("a == 40\n");
    CASE(42)
      printf("fail\n");
    RANGE_CASE(40, 50)
      printf("range case work\n");
    CUSTOM_CASE(== 40)
      {
	printf("custom case work\n");
	BREAK;
      }
    DEFAULT
      printf("fail\n");
  END_SWITCH
  return 0;
}
