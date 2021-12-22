/**
 * CCC 2021
 * S3 - Lunch Concert
 * https://dmoj.ca/problem/ccc21s3
 * 
 * Status: Not yet attempted
 * Language: C++
 * 
 */

#include <iostream>
#include <unordered_map>
using namespace std;

void getsum(int32_t c, int32_t n, int32_t friends[], unordered_map<int32_t, int32_t> rates, unordered_map<int32_t, int32_t> hearing, uint64_t *result)
{
  *result = 0;
  for (int i = 0; i < n; i++)
  {
    int64_t f = friends[i];
    f = (abs(c - f) - hearing[f]) * rates[f];
    if (f > 0)
      *result += f;
  }
}

int main()
{
  unordered_map<int32_t, int32_t> rates;
  unordered_map<int32_t, int32_t> hearing;
  int32_t n, p, w, d;
  int32_t min = 0x7fffffff;
  int32_t max = 0;
  cin >> n;
  int32_t friends[n];
  for (int32_t i = 0; i < n; i++)
  {
    cin >> p >> w >> d;
    friends[i] = p;
    rates[p] = w;
    hearing[p] = d;
    min = p < min ? p : min;
    max = p > max ? p : max;
  }
  // uint64_t minsum = 0xffffffffffffffff;
  // uint64_t suma, sumb, sumc;
  // while (min <= max)
  // {
  //   int32_t mid = (min / 2) + (max / 2); // (min + max) / 2 may cause overflow
  //   getsum(mid - 1, n, friends, rates, hearing, &suma);
  //   getsum(mid + 1, n, friends, rates, hearing, &sumb);
  //   if (suma < sumb)
  //     max = mid - 1;
  //   else if (sumb < suma)
  //     min = mid + 1;
  //   else
  //   {
  //     getsum(mid, n, friends, rates, hearing, &sumc);
  //     minsum = sumc;
  //     break;
  //   }
  //   minsum = std::min(minsum, std::min(suma, sumb));
  // }
  // cout << minsum << endl;

  int32_t mid;
  uint64_t suma, sumb;
  while (min < max)
  {
    mid = (min / 2) + (max / 2);
    getsum(mid, n, friends, rates, hearing, &suma);
    getsum(mid + 1, n, friends, rates, hearing, &sumb);
    if (sumb > suma)
      max = mid;
    else if (suma > sumb)
      min = mid;
  }
  cout << suma << endl;

  // uint8_t direction = 1;
  // uint64_t sum, prevsum;
  // int32_t i = (min / 2) + (max / 2); // (min + max) / 2 may cause overflow
  // getsum(i - 1, n, friends, rates, hearing, &prevsum);
  // getsum(i, n, friends, rates, hearing, &sum);
  // if (sum < prevsum)
  //   direction = 1;
  // else
  //   direction = -1;
  // do
  // {
  //   i += direction;
  //   prevsum = sum;
  //   getsum(i, n, friends, rates, hearing, &sum);
  // } while (sum < prevsum);
  // cout << prevsum << endl;
}
