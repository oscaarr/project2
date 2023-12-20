
#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe grid
void displayGrid(const vector<vector<char>>& grid) {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check for a winning condition
bool checkWin(const vector<vector<char>>& grid, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) {
        return true;
    }
    if (grid[2][0] == player && grid[1][1] == player && grid[0][2] == player) {
        return true;
    }

    return false;
}

int main() {
    vector<vector<char>> grid(3, vector<char>(3, ' '));  // Initialize grid with empty spaces
    char currentPlayer = 'X';
    int row, col;

    // Game loop
    while (true) {
        // Display the grid
        displayGrid(grid);

        // Get player's move
        cout << "Player " << currentPlayer << ", enter your move (row column): ";
        cin >> row >> col;

        // Update the grid
        grid[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(grid, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}
    // Display the final grid