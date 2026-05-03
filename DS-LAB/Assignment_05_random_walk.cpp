/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: Data Structures
Assignment-05-Random walk: A (drunken) cockroach is placed on a given square in the
middle of a tile floor in a rectangular room of size n x m tiles. The bug
wanders (possibly in search of an aspirin) randomly from tile to tile
throughout the room. Assuming that it may move from his present tile to
any of the eight tiles surrounding it (unless it is against a wall) with equal
probability, how long will it take him to touch every tile on the floor at
least once?
Write a C++ program to graphically show a random walk of a (drunken)
cockroach and find the no of moves made.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  int n, m;
  cout << "Enter rows and columns: ";
  cin >> n >> m;

  int grid[50][50] = {0};
  int visited = 1;

  int total = n * m;

  int r = n / 2;
  int c = m / 2;

  grid[r][c] = 1;

  int moves = 0;

  int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

  srand(time(0));

  while (visited < total)
  {

    int dir = rand() % 8;

    int nr = r + dr[dir];
    int nc = c + dc[dir];

    if (nr >= 0 && nr < n && nc >= 0 && nc < m)
    {
      r = nr;
      c = nc;

      if (grid[r][c] == 0)
      {
        visited++;
        grid[r][c] = visited;
      }

      moves++;

      cout << "\nMove " << moves << ":\n";
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          if (grid[i][j] == 0)
            cout << ".\t";
          else
            cout << grid[i][j] << "\t";
        }
        cout << endl;
      }
    }
  }

  cout << "\nAll tiles visited!\n";
  cout << "Total moves: " << moves << endl;

  return 0;
}