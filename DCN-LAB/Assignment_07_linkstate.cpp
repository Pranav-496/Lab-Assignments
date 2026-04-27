/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: DCN
Assignment-07-Write a program to implement link state /Distance vector routing protocol
to find suitable path for transmission.
*/

#include <bits/stdc++.h>
using namespace std;

int findMinDistance(vector<int> &dist, vector<bool> &visited, int n)
{
  int minVal = INT_MAX, minIndex = -1;

  for (int i = 0; i < n; i++)
  {
    if (!visited[i] && dist[i] <= minVal)
    {
      minVal = dist[i];
      minIndex = i;
    }
  }
  return minIndex;
}

void printDistanceVector(vector<int> &dist, int iteration)
{
  cout << "Distance vector after iteration " << iteration << ": ";
  for (int d : dist)
  {
    if (d == INT_MAX)
      cout << "INF ";
    else
      cout << d << " ";
  }
  cout << "\n\n";
}

void DijkstraAlgo(vector<vector<pair<int, int>>> &adj, int n, int src)
{
  vector<int> dist(n, INT_MAX);
  vector<bool> visited(n, false);

  dist[src] = 0;

  for (int i = 0; i < n - 1; i++)
  {
    int u = findMinDistance(dist, visited, n);
    if (u == -1)
      break;

    visited[u] = true;

    for (auto edge : adj[u])
    {
      int v = edge.first;
      int wt = edge.second;

      if (!visited[v] && dist[u] != INT_MAX && dist[u] + wt < dist[v])
      {
        dist[v] = dist[u] + wt;
      }
    }

    printDistanceVector(dist, i + 1);
  }

  cout << "Final shortest distances from source " << src << " are:\n";
  for (int i = 0; i < n; i++)
  {
    cout << i << ": " << dist[i] << endl;
  }
}

int main()
{
  int n = 5;
  int src = 0;

  vector<vector<pair<int, int>>> adj(n);

  adj[0].push_back({1, 10});
  adj[0].push_back({4, 5});

  adj[1].push_back({2, 1});
  adj[1].push_back({4, 2});

  adj[2].push_back({3, 4});

  adj[3].push_back({0, 7});
  adj[3].push_back({2, 6});

  adj[4].push_back({1, 3});
  adj[4].push_back({2, 9});
  adj[4].push_back({3, 2});

  DijkstraAlgo(adj, n, src);

  return 0;
}

/*
Testcase:
Distance vector after iteration 1: 0 10 INF INF 5

Distance vector after iteration 2: 0 8 14 7 5

Distance vector after iteration 3: 0 8 13 7 5

Distance vector after iteration 4: 0 8 9 7 5

Final shortest distances from source 0 are:
0: 0
1: 8
2: 9
3: 7
4: 5
*/