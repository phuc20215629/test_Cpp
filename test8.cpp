#include <iostream>
#include <vector>

// Size of the Sudoku grid
const int SIZE = 9;

// Function to check if a value is valid in a given cell
bool isValid(std::vector<std::vector<int>>& grid, int row, int col, int num) {
    // Check if the number already exists in the same row or column
    for (int i = 0; i < SIZE; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if the number already exists in the same 3x3 subgrid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve Sudoku using backtracking
int solveSudoku(std::vector<std::vector<int>>& grid) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            // Find an empty cell
            if (grid[row][col] == 0) {
                // Try each possible number from 1 to 9
                for (int num = 1; num <= 9; ++num) {
                    if (isValid(grid, row, col, num)) {
                        // Fill the cell with the valid number
                        grid[row][col] = num;

                        // Recursively solve the Sudoku
                        if (solveSudoku(grid)) {
                            return 1;  // Return if a solution is found
                        }

                        // Backtrack and try the next number
                        grid[row][col] = 0;
                    }
                }

                return 0;  // No valid number found, backtrack
            }
        }
    }

    return 1;  // All cells are filled, a solution is found
}

// Function to count the number of Sudoku solutions
int countSudokuSolutions(std::vector<std::vector<int>>& grid) {
    int count = 0;
    solveSudoku(grid);  // Solve the Sudoku

    // Count the number of solutions
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (grid[row][col] == 0) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    std::vector<std::vector<int>> grid(SIZE, std::vector<int>(SIZE));

    // Input the Sudoku grid from the user (0 represents empty cells)
    std::cout << "Enter the Sudoku grid (9x9):\n";
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            std::cin >> grid[row][col];
        }
    }

    // Count the number of Sudoku solutions
    int solutions = countSudokuSolutions(grid);

    std::cout << "Number of Sudoku solutions: " << solutions << std::endl;

    return 0;
}