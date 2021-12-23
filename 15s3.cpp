/**
 * CCC 2015
 * S3 - Gates
 * https://dmoj.ca/problem/ccc15s3
 * 
 * Status: Not yet attempted
 * Language: C++
 * 
 */

#include <iostream>
using namespace std;

int main() {
  int g, p;
  cin >> g >> p;
  int restriction;
  bool gates[g];
  fill(gates, gates + g, false);
  for (int i = 0; i < p; i++) {
    cin >> restriction;
    int j;
    for (j = restriction; j > 0; j--) {
      if (!gates[j]) {
        gates[j] = true;
        break;
      }
    }
    if (j == 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << p;
  return 0;
}
