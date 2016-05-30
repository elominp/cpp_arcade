#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "class.h"

typedef struct	Int
{
  int		nb;
  char*		(*__str__)(struct Int*);
} Int;

CLASS(Int)
{
  FUNC(char*, __str__, Int* self)
      {
        printf("%d\n", self->nb);
        return "42";
      }
  END_FUNC(__str__)

  void __init__(Int* self)
  {
    self->nb = 42;
  }

  /* Macro defined code */
  __init__(obj);
  return (obj);
}
END_CLASS

int	main(void)
{
  Int* rep = NEW(Int);
  rep->nb = 45;
  Int* rep2 = NEW(Int);
  STR(rep);
  (void)rep2;
  STR(rep2);
  return 0;
}
