#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <omp.h>

typedef unsigned long long Entero_grande;
#define ENTERO_MAS_GRANDE  ULLONG_MAX

int primo(Entero_grande n)
{
  int p, nhilos, myid;
  Entero_grande i, s;

  p = (n % 2 != 0 || n == 2);

  if (p) {
    #pragma omp parallel private(i, myid)
    {
      nhilos = omp_get_num_threads();
      myid = omp_get_thread_num();
      for (i = 3 + myid * 2; p && i <= s; i += nhilos * 2)
      if (n % i == 0) p = 0;
    }
  }

  return p;
}

int main()
{
  Entero_grande n;
  double t;
  t = omp_get_wtime();
  for (n = ENTERO_MAS_GRANDE; !primo(n); n -= 2) {
    /* NADA */
  }
  t = omp_get_wtime() -t;
  printf("El mayor primo que cabe en %lu bytes es %llu.\n",
         sizeof(Entero_grande), n);
  printf("Tiempo: %f\n", t);

  return 0;
}
