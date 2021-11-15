/**
 * CCC 1997
 * S2 - Nasty Numbers
 * https://dmoj.ca/problem/ccc97s2
 * 
 * Status: Completed
 * Language: C
 * Points: 100/100
 * Submission: https://dmoj.ca/submission/4036330
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int divisors(int in, int **out)
{
  int tmp = 0;
  *out = calloc(in, sizeof in);
  int i = 1;
  do
  {
    if (in % i == 0)
    {
      (*out)[tmp] = i;
      (*out)[tmp + 1] = in / i;
      tmp += 2;
    }
    i++;
  } while (i < (*out)[tmp - 1]);
  *out = realloc(*out, tmp * sizeof in);
  return tmp;
}

int main()
{
  int n;
  scanf("%i", &n);
  for (int i = 0; i < n; i++)
  {
    int num;
    int *d;
    scanf("%i", &num);
    int len = divisors(num, &d);
    int nasty = 0;
    for (int j = 0; j < len && !nasty; j += 2)
    {
      for (int k = 0; k < len && !nasty; k += 2)
        if (d[j + 1] - d[j] == d[k] + d[k + 1])
          nasty = 1;
    }
    if (nasty)
      printf("%i is nasty\n", num);
    else
      printf("%i is not nasty\n", num);
  }
  return 0;
}
