/**
 * CCC 2010
 * S4 - Animal Farm
 * https://dmoj.ca/problem/ccc10s4
 * 
 * Status: Completed
 * Language: C++
 * Points: 100/100
 * Submission: https://dmoj.ca/submission/4037612
 * 
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> Fence;

int edges[1001][1001][3];

int main() {
  for (int i = 0; i < 1001; i++)
    for (int j = 0; j < 1001; j++)
      for (int k = 0; k < 3; k++)
        edges[i][j][k] = -1;
  int m;
  cin >> m;
  vector<Fence> fences[m + 1];
  int maxc = 0;
  for (int p = 1; p <= m; p++) {
    int e;
    cin >> e;
    int corners[e];
    int weights[e];
    int t;
    for (int i = 0; i < e; i++) {
      cin >> t;
      corners[i] = t;
    }
    for (int i = 0; i < e; i++) {
      cin >> t;
      weights[i] = t;
    }
    for (int i = 0; i < e; i++) {
      if (corners[i] > maxc)
        maxc = corners[i];
      int a = corners[i];
      int b = corners[(i + 1) % e];
      if (a > b) {
        int t = a;
        a = b;
        b = t;
      }
      if (edges[a][b][0] != -1)
        edges[a][b][2] = p;
      else {
        edges[a][b][0] = weights[i];
        edges[a][b][1] = p;
        edges[a][b][2] = 0;
      }
    }
  }
  for (int i = 0; i <= maxc; i++)
    for (int j = 0; j <= maxc; j++) {
      int *cur = edges[i][j];
      if (cur[0] != -1) {
        fences[cur[1]].push_back({cur[0], cur[2]});
        fences[cur[2]].push_back({cur[0], cur[1]});
      }
    }
  int ans = 5000000;
  for (int i = 0; i < 2; i++) {
    int weights[m + 1];
    fill(weights, weights + m + 1, 5000);
    int determined[m + 1];
    fill(determined, determined + m + 1, false);
    priority_queue<Fence, vector<Fence>, greater<Fence>> q;
    q.push({0, 1});
    weights[1] = 0;
    determined[1] = true;
    if (i) {
      determined[0] = true;
      weights[0] = 0;
    }
    while (!q.empty()) {
      Fence cur = q.top();
      q.pop();
      int n = cur.second;
      determined[n] = true;
      for (Fence next : fences[n]) {
        int n2 = next.second;
        if (!determined[n2]) {
          if (next.first < weights[n2]) {
            weights[n2] = next.first;
            q.push(next);
          }
        }
      }
    }
    int tmp = 0;
    for (int j : weights)
      tmp += j;
    if (tmp < ans)
      ans = tmp;
  }
  cout << ans << endl;
  return 0;
}
