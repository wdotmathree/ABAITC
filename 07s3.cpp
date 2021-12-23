/**
 * CCC 2007
 * S3 - Friends
 * https://dmoj.ca/problem/ccc07s3
 * 
 * Status: Completed
 * Language: C++
 * Points: 40/40
 * Submission: https://dmoj.ca/submission/4058595
 * 
 */

#include <iostream>
#include <set>
using namespace std;

int assignments[10000];

int main() {
  int a, b;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    assignments[a] = b;
  }
  while (true) {
    cin >> a >> b;
    if (a == 0)
      break;
    int t = assignments[a];
    int count = 0;
    set<int> s;
    while (true) {
      if (s.find(t) != s.end()) {
        cout << "No" << endl;
        break;
      }
      s.insert(t);
      if (t == b) {
        cout << "Yes " << count << endl;
        break;
      }
      t = assignments[t];
      count++;
    }
  }
  return 0;
}
