/**
 * CCC 2012
 * S3 - Absolutely Acidic
 * https://dmoj.ca/problem/ccc12s3
 * 
 * Status: Not Accepted
 * Language: C++
 * Points: 40/50
 * Submission: https://dmoj.ca/submission/4131627
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_map<short, int> numsmap;
  vector<pair<short, int>> nums;
  int n;
  int r;
  cin >> n;
  while (n--) {
    cin >> r;
    numsmap[r]++;
  }
  for (auto x : numsmap)
    nums.push_back(x);
  sort(nums.begin(), nums.end(), [](auto a, auto b) { return a.first < b.first; });
  sort(nums.begin(), nums.end(), [](auto a, auto b) { return a.second < b.second; });
  int max1 = nums[nums.size() - 1].first;
  sort(nums.begin(), nums.end(), [](auto a, auto b) { return a.first > b.first; });
  sort(nums.begin(), nums.end(), [](auto a, auto b) { return a.second < b.second; });
  int max2 = nums[nums.size() - 1].first;
  sort(nums.begin(), nums.end(), [](auto a, auto b) { return a.first > b.first; });
  sort(nums.begin(), nums.end(), [](auto a, auto b) { return a.second < b.second; });
  int min1 = nums[nums.size() - 1].first;
  sort(nums.begin(), nums.end(), [](auto a, auto b) { return a.first < b.first; });
  sort(nums.begin(), nums.end(), [](auto a, auto b) { return a.second < b.second; });
  int min2 = nums[nums.size() - 1].first;
  cout << max(abs(max1 - min1), max(abs(max1 - min2), max(abs(max2 - min1), abs(max2 - min2)))) << endl;
}
