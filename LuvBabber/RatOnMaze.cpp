// #include <bits/stdc++.h>
// using namespace std;

// bool isSafe(int newx, int newy, int maze[][4], int row, int col, vector<vector<bool>> &visited)
// {
//     if ((newx >= 0 && newx < row) && (newy >= 0 && newy < col) && maze[newx][newy] == 1 && visited[newx][newy] == false)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool>> &visited)
// {
//     // destination coordinates are [row-1],[col-1]
//     if (srcx == (row - 1) && srcy == (col - 1))
//     {
//         cout << output << endl;
//         return;
//     }

//     // 1 case solve and baaki recursion sambhal lega

//     // Up
//     int newx = srcx - 1;
//     int newy = srcy;
//     if (isSafe(newx, newy, maze, row, col, visited))
//     {
//         // mark visited
//         visited[newx][newy] = true;
//         // call recursion
//         output.push_back('U');
//         printAllPath(maze, row, col, newx, newy, output, visited);
//         // backtracking
//         output.pop_back();
//         visited[newx][newy] = false;
//     }

//     // Right
//     newx = srcx;
//     newy = srcy + 1;
//     if (isSafe(newx, newy, maze, row, col, visited))
//     {
//         // mark visited
//         visited[newx][newy] = true;
//         // call recursion
//         output.push_back('R');
//         printAllPath(maze, row, col, newx, newy, output, visited);
//         // backtracking
//         output.pop_back();
//         visited[newx][newy] = false;
//     }

//     // Down
//     newx = srcx + 1;
//     newy = srcy;
//     if (isSafe(newx, newy, maze, row, col, visited))
//     {
//         // mark visited
//         visited[newx][newy] = true;
//         // call recursion
//         output.push_back('D');
//         printAllPath(maze, row, col, newx, newy, output, visited);
//         // backtracking
//         output.pop_back();
//         visited[newx][newy] = false;
//     }

//     // Left
//     newx = srcx;
//     newy = srcy - 1;
//     if (isSafe(newx, newy, maze, row, col, visited))
//     {
//         // mark visited
//         visited[newx][newy] = true;
//         // call recursion
//         output.push_back('L');
//         printAllPath(maze, row, col, newx, newy, output, visited);
//         // backtracking
//         output.pop_back();
//         visited[newx][newy] = false;
//     }
// }

// int main()
// {
//     int maze[4][4] = {
//         {1, 0, 0, 0},
//         {1, 1, 0, 0},
//         {1, 1, 1, 0},
//         {1, 1, 1, 1}};
//     int row = 4;
//     int col = 4;
//     int srcx = 0;
//     int srcy = 0;
//     string output = "";

//     // create visited array
//     vector<vector<bool>> visited(row, vector<bool>(col, false));

//     if (maze[0][0] == 0)
//     {
//         // src position is closed, that means RAT cannot move
//         cout << "No Path Exist" << endl;
//     }
//     else
//     {
//         visited[srcx][srcy] = true;
//         printAllPath(maze, row, col, srcx, srcy, output, visited);
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int maze[][4], int row, int col, int newx, int newy, vector<vector<bool>> &visited)
{
    // Not off bound
    // not visited
    // path true
    if ((newx >= 0 && newx < row) && (newy >= 0 && newy < col) && (maze[newx][newy] == 1) && (visited[newx][newy] == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool>> &visited)
{
    // base condition
    if (srcx == (row - 1) && srcy == (col - 1))
    {
        cout << output << endl;
        return;
    }

    // UP
    int newx = srcx - 1;
    int newy = srcy;
    if (isSafe(maze, row, col, newx, newy, visited))
    {
        // visited = true
        visited[newx][newy] = true;
        output.push_back('U');
        printAllPath(maze, row, col, newx, newy, output, visited);

        // backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }
    // DOWN
    newx = srcx + 1;
    newy = srcy;
    if (isSafe(maze, row, col, newx, newy, visited))
    {
        // visited = true
        visited[newx][newy] = true;
        output.push_back('D');
        printAllPath(maze, row, col, newx, newy, output, visited);

        // backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }

    // LEFT
    newx = srcx;
    newy = srcy - 1;
    if (isSafe(maze, row, col, newx, newy, visited))
    {
        // visited = true
        visited[newx][newy] = true;
        output.push_back('L');
        printAllPath(maze, row, col, newx, newy, output, visited);

        // backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }

    // RIGHT
    newx = srcx;
    newy = srcy + 1;
    if (isSafe(maze, row, col, newx, newy, visited))
    {
        // visited = true
        visited[newx][newy] = true;
        output.push_back('R');
        printAllPath(maze, row, col, newx, newy, output, visited);

        // backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }
}

int main()
{
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1},
    };
    int row = 4;
    int col = 4;
    // src coordinate
    int srcx = 0;
    int srcy = 0;
    string output = "";
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    visited[srcx][srcy] = true;
    printAllPath(maze, row, col, srcx, srcy, output, visited);

    return 0;
}
