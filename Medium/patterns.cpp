#include <bits/stdc++.h>
using namespace std;

int result = 0;

void patternsHelper(vector<vector<int>> &matrix, int totalRows, int totalColumns, int row, int column, int depth)
{
    if (row < 0 || row >= totalRows)
        return;
    if (column < 0 || column >= totalColumns)
        return;

    if (matrix[row][column] == 1)
    {
        if (depth >= 3)
            cout << "incrementing result to " << ++result << '\n';

        // for every sub-call, we cannot access the same node again
        matrix[row][column] = 0;

        // check for immediate links
        // straight-up gangsta
        patternsHelper(matrix, totalRows, totalColumns, row, column + 1, depth + 1);
        patternsHelper(matrix, totalRows, totalColumns, row, column - 1, depth + 1);
        patternsHelper(matrix, totalRows, totalColumns, row + 1, column, depth + 1);
        patternsHelper(matrix, totalRows, totalColumns, row - 1, column, depth + 1);

        // dragon valley
        patternsHelper(matrix, totalRows, totalColumns, row + 1, column + 1, depth + 1);
        patternsHelper(matrix, totalRows, totalColumns, row - 1, column - 1, depth + 1);
        patternsHelper(matrix, totalRows, totalColumns, row + 1, column - 1, depth + 1);
        patternsHelper(matrix, totalRows, totalColumns, row - 1, column + 1, depth + 1);

        // crooked one-two links
        patternsHelper(matrix, totalRows, totalColumns, row - 2, column + 1, depth + 1);
        patternsHelper(matrix, totalRows, totalColumns, row - 2, column - 1, depth + 1);
        patternsHelper(matrix, totalRows, totalColumns, row - 1, column + 2, depth + 1);
        patternsHelper(matrix, totalRows, totalColumns, row - 1, column - 2, depth + 1);

        patternsHelper(matrix, totalRows, totalColumns, row + 1, column + 2, depth + 1);
        patternsHelper(matrix, totalRows, totalColumns, row + 1, column - 2, depth + 1);
        patternsHelper(matrix, totalRows, totalColumns, row + 2, column + 1, depth + 1);
        patternsHelper(matrix, totalRows, totalColumns, row + 2, column - 1, depth + 1);

        // straight-up bhopping links
        if (matrix[row][column + 1] == 0)
            patternsHelper(matrix, totalRows, totalColumns, row, column + 2, depth + 1);
        if (matrix[row][column - 1] == 0)
            patternsHelper(matrix, totalRows, totalColumns, row, column - 2, depth + 1);
        if (matrix[row + 1][column] == 0)
            patternsHelper(matrix, totalRows, totalColumns, row + 2, column, depth + 1);
        if (matrix[row - 1][column] == 0)
            patternsHelper(matrix, totalRows, totalColumns, row - 2, column, depth + 1);

        if (matrix[row + 1][column + 1] == 0)
            patternsHelper(matrix, totalRows, totalColumns, row + 2, column + 2, depth + 1);
        if (matrix[row - 1][column - 1] == 0)
            patternsHelper(matrix, totalRows, totalColumns, row - 2, column - 2, depth + 1);
        if (matrix[row + 1][column - 1] == 0)
            patternsHelper(matrix, totalRows, totalColumns, row + 2, column - 2, depth + 1);
        if (matrix[row - 1][column + 1] == 0)
            patternsHelper(matrix, totalRows, totalColumns, row - 2, column + 2, depth + 1);

        // after each of these sub-call, make this node accessible again
        matrix[row][column] = 1;
    }
}

void patternsHelperPrime(vector<vector<int>> matrix, int totalRows, int totalColumns, int row, int column, int depth)
{
    patternsHelper(matrix, totalRows, totalColumns, row, column, 0);
}

int patterns(vector<vector<int>> matrix)
{

    int totalRows = matrix.size();
    int totalColumns = matrix[0].size();

    for (int i = 0; i < totalRows; i++)
        for (int j = 0; j < totalColumns; j++)
        {
            patternsHelperPrime(matrix, totalRows, totalColumns, i, j, 0);
        }

    return result;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};

    cout << patterns(matrix) << '\n';
    return 0;
}