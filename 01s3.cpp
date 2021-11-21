/**
 * CCC 2001
 * S3 - Strategic Bombing
 * https://dmoj.ca/problem/ccc01s3
 * 
 * Status: Completed
 * Language: C++
 * Points: 50/50
 * Submission: https://dmoj.ca/submission/4052877
 * 
 */

#include <iostream>
using namespace std;

bool adj[26][26];
bool tmp[26][26];

bool warshall()
{
  copy(*adj, *adj + 26 * 26, *tmp);
  for (int k = 0; k < 26; k++)
  {
    for (int i = 0; i < 26; i++)
    {
      if (i == k)
        continue;
      for (int j = 0; j < 26; j++)
      {
        if (j == k)
          continue;
        if (i == 0 && j == 1)
          cout << "";
        tmp[i][j] = tmp[i][j] | (tmp[i][k] & tmp[k][j]);
      }
    }
  }
  return !(tmp[0][1] && tmp[1][0]);
}

int main()
{
  int count = 0;
  fill(*adj, *adj + 26 * 26, false);
  while (true)
  {
    char a, b;
    cin >> a >> b;
    if (a == '*')
      break;
    adj[a - 65][b - 65] = true;
    adj[b - 65][a - 65] = true;
  }
  for (int i = 0; i < 25; i++)
  {
    for (int j = i + 1; j < 26; j++)
    {
      if (adj[i][j])
      {
        adj[i][j] = false;
        if (warshall())
        {
          cout << (char)(i + 'A') << (char)(j + 'A') << endl;
          count++;
        }
        adj[i][j] = true;
      }
    }
  }
  cout << "There are " << count << " disconnecting roads." << endl;
  return 0;
}
