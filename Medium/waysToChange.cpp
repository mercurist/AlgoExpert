#include <bits/stdc++.h>
using namespace std;

void waysToChangeHelper(vector<int> denoms, int n, int &count, int currentSum, int index)
{
    if (currentSum == n)
    {
        // cout << "COUNT INCREMENTED" << '\n';
        count++;
        return;
    }
    else if (currentSum > n)
    {
        return;
    }
    for (int i = index; i < denoms.size(); i++)
    {
        currentSum += denoms[i];
        // cout << "recursive sub-call with currentSum = " << currentSum << '\n';
        waysToChangeHelper(denoms, n, count, currentSum, i);
        currentSum -= denoms[i];
    }
}

// int numberOfWaysToMakeChange(int n, vector<int> denoms)
// {
//     // Write your code here.
//     int count = 0;
//     waysToChangeHelper(denoms, n, count, 0, 0);
//     return count;
// }

int numberOfWaysToMakeChange(int n, vector<int> denoms)
{
    // dynamic programming
    vector<int> ways(n + 1, 0);
    ways[0] = 1;

    for (int i = 0; i < denoms.size(); i++)
    {
        cout << denoms[i] << '\n';
        for (int j = 0; j < n + 1; j++)
        {
            if (j < denoms[i])
                continue;
            ways[j] += ways[j - denoms[i]];
        }
    }

    return ways[n];
}

int main()
{
    vector<int> vector1{2, 3, 4, 7};
    vector<int> vector2{5};
    vector<int> vector3{2, 4};
    vector<int> vector4{1, 5};
    vector<int> vector5{1, 5, 10, 25};
    vector<int> vector6{1, 5, 10, 25};
    vector<int> vector7{1, 5, 10, 25};
    vector<int> vector8{1, 5, 10, 25};
    vector<int> vector9{2, 3, 7};
    vector<int> vector10{2, 3, 4, 7};

    cout << numberOfWaysToMakeChange(6, vector4) << endl;
    return 0;
}
