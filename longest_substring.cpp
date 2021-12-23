#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_map<char, int> chars;
  int start = 0;
  int end = 0;
  string original;
  int k;
  cin >> original >> k;
  int left = 0;
  for (int right = 0; right < original.length(); right++) {
    if (chars.find(original[right]) == chars.end())
      chars[original[right]] = 1;
    else
      chars[original[right]]++;
    while (chars.size() > k) {
      if (chars[original[left]] == 1)
        chars.erase(original[left]);
      else
        chars[original[left]]--;
      left++;
    }
    if (right - left + 1 > end - start) {
      start = left;
      end = right;
    }
  }
  cout << end - start + 1 << endl;
}
