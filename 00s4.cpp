/**
 * CCC 2000
 * S4 - Golf
 * https://dmoj.ca/problem/ccc00s4
 * 
 * Status: Completed
 * Language: C++
 * Points: 60/60
 * Submission: https://dmoj.ca/submission/4187840
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  short dist, nc, minc = 0x7fff;
  cin >> dist >> nc;
  short clubs[nc], strokes[dist + 1];
  fill(strokes, strokes + dist + 1, 0);
  for (short i = 0; i < nc; i++) {
    cin >> clubs[i];
    strokes[clubs[i]] = 1;
    if (clubs[i] < minc)
      minc = clubs[i];
  }
  for (short i = 1; i <= dist; i++) {
    if (strokes[i] != 0)
      continue;
    if (i < minc)
      strokes[i] = -1;
    short min = 0x7fff;
    for (short j = 0; j < nc; j++) {
      if (i < clubs[j])
        continue;
      if (strokes[i - clubs[j]] != -1 && strokes[i - clubs[j]] < min)
        min = strokes[i - clubs[j]];
    }
    if (min == 0x7fff)
      strokes[i] = -1;
    else
      strokes[i] = min + 1;
  }
  if (strokes[dist] == -1)
    printf("Roberta acknowledges defeat.");
  else
    printf("Roberta wins in %hi strokes.", strokes[dist]);
  return 0;
}
