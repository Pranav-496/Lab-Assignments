#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int board[N][N];

// Possible moves for a knight
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Check if (x, y) is inside the board and not visited
bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Count number of onward moves from position (x, y)
int countOnwardMoves(int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny))
            count++;
    }
    return count;
}

// Warnsdorff's heuristic: choose next move with minimum onward moves
bool nextMove(int &x, int &y) {
    int min_deg_idx = -1, min_deg = 9, c, nx, ny;

    // Store all valid next moves with their onward degrees
    vector<pair<int, pair<int, int>>> candidates; // {degree, {nx, ny}}

    for (int i = 0; i < 8; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (isValid(nx, ny)) {
            c = countOnwardMoves(nx, ny);
            candidates.push_back({c, {nx, ny}});
        }
    }

    if (candidates.empty()) return false;

    // Sort by number of onward moves (degree)
    sort(candidates.begin(), candidates.end(), [](auto &a, auto &b) {
        return a.first < b.first;
    });

    // Choose the candidate with minimum degree
    x = candidates[0].second.first;
    y = candidates[0].second.second;

    return true;
}

bool knightTour(int sx, int sy) {
    // Initialize board with -1 (not visited)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;

    // Start from first position
    int x = sx, y = sy;
    board[x][y] = 0; // First move

    // Make moves from 1 to 63
    for (int movei = 1; movei < N * N; movei++) {
        if (!nextMove(x, y)) {
            return false; // no further moves, tour failed
        }
        board[x][y] = movei;
    }
    return true;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(2) << board[i][j] + 1 << " ";
        }
        cout << "\n";
    }
}

int main() {
    int start_x, start_y;
    cout << "Enter starting position (row and column: 0-7): ";
    cin >> start_x >> start_y;

    if (start_x < 0 || start_x >= N || start_y < 0 || start_y >= N) {
        cout << "Invalid starting position!\n";
        return 1;
    }

    if (knightTour(start_x, start_y)) {
        cout << "Knight's Tour found:\n";
        printBoard();
    } else {
        cout << "No Knight's Tour found from this starting position.\n";
    }

    return 0;
}