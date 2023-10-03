#include<bits/stdc++.h>
using namespace std;

const int SIZE = 9;

bool isValid(vector<vector<int>> a, int row, int col, int num) {
    for(int i = 0; i < 9; i++) {
        if(a[row][i] == num || a[i][col] == num) return false;
    }

    int rs = (row / 3) * 3;
    int cs = (col / 3) * 3;
    for(int i = rs; i < rs + 3; i++) {
        for(int j = cs; j < cs + 3; j++) {
            if(a[i][j] == num) return false;
        }
    }
    return true;
}

int countSudokuSolutions(vector<vector<int>>& a) {
    int count = 0;
    int row = -1;
    int col = -1;

    // Find the next empty cell
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (a[i][j] == 0) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) {
            break;
        }
    }

    // If no empty cell is found, the Sudoku is solved
    if (row == -1) {
        return 1;
    }

    // Try filling the empty cell with numbers from 1 to 9
    for (int num = 1; num <= 9; ++num) {
        if (isValid(a, row, col, num)) {
            a[row][col] = num;

            // Recursively solve the updated grid
            count += countSudokuSolutions(a);

            // Reset the cell for backtracking
            a[row][col] = 0;
        }
    }

    return count;
}

int main() {
    vector<vector<int>> a(SIZE, vector<int>(SIZE));
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            cin >> a[row][col];
        }
    }

    int solutions = countSudokuSolutions(a);

    cout  << solutions << endl;

    return 0;
}