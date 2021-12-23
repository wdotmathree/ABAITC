/**
 * CCC 2020
 * S3 - Searching for Strings
 * https://dmoj.ca/problem/ccc20s3
 * 
 * Status: Not yet attempted
 * Language: C++
 * 
 */

#include <iostream>
#include <unordered_set>
using namespace std;

inline bool checkarrs(int *arra, int *arrb) {
  for (int i = 0; i < 26; i++)
    if (arra[i] != arrb[i])
      return false;
  return true;
}

long long hash(string str, int start, int end) {
  long long value = 0;
  long long pow = 0;
  for (int i = start; i < end; i++) {
  }
}

long long hash(string str, int start, int end) {
  long long h = (h * p + ord) % m;
  power = (power * p) % m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string needle;
  string haystack;
  cin >> needle >> haystack;
  int counts[26];
  int ncounts[26];
  fill(counts, counts + 26, 0);
  fill(ncounts, ncounts + 26, 0);
  unordered_set<string> p;
  int lenhn = haystack.length();
  lenhn -= needle.length();
  for (char n : needle)
    ncounts[n - 'a']++;
  for (int i = 0; i < needle.length(); i++)
    counts[haystack[i] - 'a']++;
  if (checkarrs(ncounts, counts))
    p.insert(haystack.substr(0, needle.length()));
  for (int i = 1; i <= lenhn; i++) {
    counts[haystack[i - 1] - 'a']--;
    counts[haystack[i + needle.length() - 1] - 'a']++;
    if (checkarrs(ncounts, counts))
      p.insert(haystack.substr(i, needle.length()));
  }
  cout << p.size() << endl;
  return 0;
}
