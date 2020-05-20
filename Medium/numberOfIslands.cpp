#include <bits/stdc++.h>
using namespace std;

void riverSizesHelper(vector<vector<char>> &matrix, int totalRows, int totalColumns, int row, int column)
{
    if (row >= totalRows or row < 0)
        return;
    if (column >= totalColumns or column < 0)
        return;

    if (matrix[row][column] == '1')
    {
        matrix[row][column] = '0';

        riverSizesHelper(matrix, totalRows, totalColumns, row, column + 1);
        riverSizesHelper(matrix, totalRows, totalColumns, row + 1, column);

        riverSizesHelper(matrix, totalRows, totalColumns, row - 1, column);
        riverSizesHelper(matrix, totalRows, totalColumns, row, column - 1);
    }
}

int riverSizes(vector<vector<char>> grid)
{
    // Write your code here.
    int result = 0;
    int totalRows = grid.size();
    int totalColumns = grid[0].size();
    for (int i = 0; i < totalRows; i++)
        for (int j = 0; j < totalColumns; j++)
        {
            if (grid[i][j] == '1')
            {
                riverSizesHelper(grid, totalRows, totalColumns, i, j);
                result += 1;
            }
        }

    return result;
}

void display(vector<int> hector)
{
    for (int i = 0; i < hector.size(); i++)
        cout << hector[i] << " ";
    cout << '\n';
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '1'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '1'},
        {'0', '0', '0', '1', '1'}};

    cout << riverSizes(grid) << '\n';
    return 0;
}