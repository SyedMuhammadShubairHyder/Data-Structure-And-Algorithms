/*
Imagine a 4x4 grid where a person is on a mission to collect as many flags as possible. Each
cell of the grid represents a potential location for placing a flag. However, there are constraints:
i. Only one flag can be placed in each row or column.
ii. Additionally, no two flags can ever be placed on the same diagonal (i.e., no two flags
can threaten each other diagonally).
iii. Your goal is to design a backtracking algorithm in C++ to help this person maximize
the number of flags collected while adhering to these constraints. After implementing
the algorithm, provide the code and report the maximum number of flags that can be
placed on the 4x4 grid.
*/
#include <iostream>

using namespace std;

const int GRID_SIZE = 4;

bool isSafe(int flags[], int row, int col) {
    for (int prevRow = 0; prevRow < row; prevRow++) {
        int prevCol = flags[prevRow];
        
        if (prevCol == col) {
            return false;
        }
        
        if (abs(prevRow - row) == abs(prevCol - col)) {
            return false;
        }
    }
    return true;
}

bool placeFlags(int flags[], int row) {
    if (row == GRID_SIZE) {
        return true;
    }

    for (int col = 0; col < GRID_SIZE; col++) {
        if (isSafe(flags, row, col)) {
            flags[row] = col;

            if (placeFlags(flags, row + 1)) {
                return true;
            }

            flags[row] = -1;
        }
    }

    return false;
}

int main() {
    
    int flags[GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++) {
        flags[i] = -1;
    }
    
    if (placeFlags(flags, 0)) {
        cout << "Maximum number of flags that can be placed on the 4x4 grid: " << GRID_SIZE << endl;
        cout << "Flag positions (row, column): " << endl;
        for (int row = 0; row < GRID_SIZE; row++) {
            cout << "(" << row << ", " << flags[row] << ")" << endl;
        }
    } else {
        cout << "No solution exists to place flags on the grid." << endl;
    }

    return 0;
}