/**
 * CCC 1996
 * S3 - Pattern Generator
 * https://dmoj.ca/problem/ccc96s3
 * 
 * Status: Completed
 * Language: C++
 * Points: 5/5
 * Submission: https://dmoj.ca/submission/4128946
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> generate(int n, int k) {
  vector<string> ans;
  if (k == 0) {
    string s = "";
    for (int i = 0; i < n; i++)
      s.push_back('0');
    ans.push_back(s);
    return ans;
  }
  if (n == k) {
    string s = "";
    for (int i = 0; i < n; i++)
      s.push_back('1');
    ans.push_back(s);
    return ans;
  }
  auto pre = generate(n - 1, k - 1);
  for (string s : pre) {
    s = "1" + s;
    ans.push_back(s);
  }
  pre = generate(n - 1, k);
  for (string s : pre) {
    s = "0" + s;
    ans.push_back(s);
  }
  return ans;
}

int main() {
  int t, n, k;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> k;
    cout << "The bit patterns are\n";
    auto v = generate(n, k);
    for (auto s : v) {
      cout << s << "\n";
    }
    cout << "\n";
  }
}
