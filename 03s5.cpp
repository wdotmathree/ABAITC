/**
 * CCC 2003
 * S5 - Trucking Troubles
 * https://dmoj.ca/problem/ccc03s5
 * 
 * Status: Completed
 * Language: C++
 * Points: 100/100
 * Submission: https://dmoj.ca/submission/4036315
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Road;

int main()
{
  int c, r, d, ta, tb, tw;
  cin >> c >> r >> d;
  vector<Road> roads[c + 1];
  int destinations[d];
  for (int i = 0; i < r; i++)
  {
    cin >> ta >> tb >> tw;
    roads[ta].push_back({tw, tb});
    roads[tb].push_back({tw, ta});
  }
  for (int i = 0; i < d; i++)
  {
    cin >> ta;
    destinations[i] = ta;
  }
  int weights[c + 1];
  fill(weights, weights + c + 1, 0);
  priority_queue<Road, vector<Road>, greater<Road>> q;
  q.push({0, 1});
  weights[1] = 0;
  while (!q.empty())
  {
    Road cur = q.top();
    q.pop();
    int n = cur.second;
    for (Road next : roads[n])
    {
      int n2 = next.second;
      if (next.first > weights[n2])
      {
        weights[n2] = next.first;
        q.push(next);
      }
    }
  }
  int ans = 100000;
  for (int i = 0; i < d; i++)
    if (weights[destinations[i]] < ans)
      ans = weights[destinations[i]];
  cout << ans;
  return 0;
}
