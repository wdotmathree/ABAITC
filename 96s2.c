/**
 * CCC 1996
 * S2 - Divisibility by 11
 * https://dmoj.ca/problem/ccc96s2
 * 
 * Status: Compilation Error
 * Reason: Used external library "The GNU Multiple Precision Arithmetic Library" https://gmplib.org/
 * Language: C
 * Points: 50/50 (self tested)
 * Submission: https://dmoj.ca/submission/4036202
 * 
 */

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, r;
  scanf("%i", &n);
  char *s = malloc(51);
  mpz_t a, b;
  mpz_init(a);
  mpz_init(b);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    mpz_set_str(a, s, 10);
    while (mpz_cmp_ui(a, 11) > 0) {
      r = mpz_fdiv_q_ui(b, a, 10);
      mpz_sub_ui(a, b, r);
      printf("%s\n", mpz_get_str(NULL, 10, a));
    }
    if (mpz_cmp_ui(a, 11))
      printf("The number %s is not divisible by 11.\n", s);
    else
      printf("The number %s is divisible by 11.\n", s);
    if (i != n)
      printf("\n");
  }
  return 0;
}
