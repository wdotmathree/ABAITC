/**
 * CCC 1998
 * S2 - Cross Number Puzzle
 * https://dmoj.ca/problem/ccc98s2
 * 
 * Status: Completed
 * Language: C
 * Points: 10/10
 * Submission: https://dmoj.ca/submission/4031623
 * 
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void divisors(int in, int **out, int *len) {
  int tmp = 1;
  *out = calloc(in, sizeof in);
  (*out)[0] = 1;
  int i = 2;
  do {
    if (in % i == 0) {
      (*out)[tmp] = i;
      (*out)[tmp + 1] = in / i;
      tmp += 2;
    }
    i++;
  } while (i < (*out)[tmp - 1]);
  *out = realloc(*out, tmp * sizeof in);
  *len = tmp;
}

int main() {
  for (int i = 1000; i < 10000; i++) {
    int *d;
    int len;
    divisors(i, &d, &len);
    int sum = 0;
    for (int j = 0; j < len; j++)
      sum += d[j];
    if (sum == i)
      printf("%i ", i);
  }
  printf("\n");
  for (int i = 100; i < 1000; i++) {
    int a, b, c;
    a = i / 100 % 10;
    b = i / 10 % 10;
    c = i / 1 % 10;
    if (pow(a, 3) + pow(b, 3) + pow(c, 3) == i)
      printf("%i ", i);
  }
  printf("\n");
  return 0;
}
