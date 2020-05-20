#include <bits/stdc++.h>
using namespace std;

void riverSizesHelper(vector<vector<int>> &matrix, int totalRows, int totalColumns, int row, int column, int &tempCount)
{
    if (row >= totalRows or row < 0)
        return;
    if (column >= totalColumns or column < 0)
        return;

    if (matrix[row][column] == 1)
    {
        // cout << "at row " << row << " at column " << column << '\n';
        // cout << "incrementing tempCount to " << tempCount + 1 << '\n';
        tempCount++;
        matrix[row][column] = 0;

        riverSizesHelper(matrix, totalRows, totalColumns, row, column + 1, tempCount);
        riverSizesHelper(matrix, totalRows, totalColumns, row + 1, column, tempCount);

        riverSizesHelper(matrix, totalRows, totalColumns, row - 1, column, tempCount);
        riverSizesHelper(matrix, totalRows, totalColumns, row, column - 1, tempCount);
    }
}

vector<int> riverSizes(vector<vector<int>> &matrix)
{
    // Write your code here.
    vector<int> result = {};
    int totalRows = matrix.size();
    int totalColumns = matrix[0].size();
    for (int i = 0; i < totalRows; i++)
        for (int j = 0; j < totalColumns; j++)
        {
            if (matrix[i][j] == 1)
            {
                int tempCount = 0;
                riverSizesHelper(matrix, totalRows, totalColumns, i, j, tempCount);
                result.push_back(tempCount);
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
    vector<vector<int>> matrix = {
        {1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1},
    };
    vector<int> result = riverSizes(matrix);
    display(result);

    return 0;
}