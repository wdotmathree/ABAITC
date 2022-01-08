#include <bits/stdc++.h>
using namespace std;

short dist, nc, minc = 0x7fff;
short *clubs;

short recurse(short d) {
  string a;
  if (d < 0)
    return -1;
  if (d == 0)
    return 0;
  for (short i = 0; i < nc; i++) {
    if (d == clubs[i])
      return 1;
  }
  short min = 0x7fff;
  for (short i = 0; i < nc; i++) {
    short t = recurse(d - clubs[i]);
    if (t == -1)
      continue;
    if (t < min)
      min = t;
  }
  return min + 1;
}

int main() {
  cin >> dist >> nc;
  clubs = (short *)calloc(nc, sizeof(short));
  for (short i = 0; i < nc; i++) {
    cin >> clubs[i];
    if (clubs[i] < minc)
      minc = clubs[i];
  }
  short ans = recurse(dist);
  if (ans == -1)
    cout << "Roberta acknowledges defeat.";
  else
    printf("Roberta wins in %hi strokes.", ans);
  return 0;
}