/*
Name: Pranav Shailesh Landge
Class: SY-A
Roll_no: 41
Subject: Data Structures
Assignment-05-Knight’s tour: The problem is to move the knight, beginning from any
given square on the chessboard, in such a manner that it travels
successively to all 64 squares, touching each square once and only once.
It is convenient to represent a solution by placing the numbers 1,2, ...,64 in
the squares of the chessboard indicating the order in which the squares are
reached. Note that it is not required that the knight be able to reach the
initial position by one more move; if this is possible the knight's tour is
called re-entrant. One of the more ingenious methods for solving the
problem of the knight's tour is that given by J. C. Warnsdorff in 1823. His
rule is that the knight must always be moved to one of the squares from
which there are the fewest exits to squares not already traversed. Write a
C++ program to implement Warnsdorff's rule and show it graphically.
*/

#include <bits/stdc++.h>
using namespace std;

int board[50][50];
int N;

int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isValid(int r, int c) {
    return (r >= 0 && c >= 0 && r < N && c < N && board[r][c] == -1);
}

bool solve(int r, int c, int move) {

    board[r][c] = move;

    if (move == N*N - 1)
        return true;

    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (isValid(nr, nc)) {
            if (solve(nr, nc, move + 1))
                return true;
        }
    }

    board[r][c] = -1;
    return false;
}

int main() {
    cout << "Enter N: ";
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;

    if (solve(0, 0, 0)) {
        cout << "VALID Knight's Tour\n\n";

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "INVALID Knight's Tour\n";
    }

    return 0;
}