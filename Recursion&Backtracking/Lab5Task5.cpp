/*
Imagine you are given a grid representing a maze, where “0”s represent obstacles(red
highlighted) or walls, and “1”s represent open paths or empty cells. You have two arrays at
your disposal: an empty Solution array and a maze represented by the following grid:

Your task is to guide a lion through a maze from the starting point at (0, 0) to reach a piece of
meat located at the destination point (4, 4). The lion is not allowed to move diagonally and can
only move through open paths (represented by '1's) while avoiding obstacles (represented by
'0's). Please provide a C++ code that uses a backtracking algorithm to navigate the maze
and move the lion to the meat. Additionally, display the contents of the Solution
array after the lion has reached the meat.
*/
#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1);
}

bool RatinMaze(int **arr, int x, int y, int n, int **solarr) {
    if (x == n - 1 && y == n - 1) {
        solarr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n)) {
        solarr[x][y] = 1;

        if (RatinMaze(arr, x + 1, y, n, solarr)) {//down
            return true;
        }

        if (RatinMaze(arr, x, y + 1, n, solarr)) {//right
            return true;
        }
        solarr[x][y] = 0;
    }

    return false;
}

int main() {
    int n = 5;

    int mazeArray[5][5] = {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };

    
    int **maze = new int *[n];
    for (int i = 0; i < n; i++) {
        maze[i] = new int[n];
        for (int j = 0; j < n; j++) {
            maze[i][j] = mazeArray[i][j];  
        }
    }

    int **solArr = new int *[n];
    for (int i = 0; i < n; i++) {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            solArr[i][j] = 0;
        }
    }

    if (RatinMaze(maze, 0, 0, n, solArr)) {
        cout << "Solution path:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found!" << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] maze[i];
        delete[] solArr[i];
    }
    delete[] maze;
    delete[] solArr;

    return 0;
}
