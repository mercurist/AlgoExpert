#include <bits/stdc++.h>
using namespace std;
#define pb push_back

void display(vector<int> s)
{
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << " ";
}

vector<int> spiralTraverse(vector<vector<int>> array)
{
    int rows = array.size();
    if (rows == 0)
        return {};
    int columns = array[0].size();
    vector<int> result;
    int no_of_levels = (rows + 1) / 2;
    for (int start_row = 0; start_row < no_of_levels; start_row++)
    {
        int left_col = start_row;
        int top_row = start_row;
        int right_col = columns - 1 - start_row;
        int bottom_row = rows - 1 - start_row;

        int cur_row = top_row, cur_col = left_col;
        for (; cur_col < right_col; cur_col++)
            result.pb(array[cur_row][cur_col]);

        for (; cur_row < bottom_row; cur_row++)
            result.pb(array[cur_row][cur_col]);

        for (; cur_col > left_col; cur_col--)
            result.pb(array[cur_row][cur_col]);

        for (; cur_row > top_row; cur_row--)
            result.pb(array[cur_row][cur_col]);
    }
    return result;
}

int main()
{
    vector<vector<int>> array = {
        {1, 2, 3, 4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9, 8, 7}};
    vector<int> res = spiralTraverse(array);
    display(res);
    return 0;
}