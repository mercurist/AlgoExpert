#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    vector<int> sorryNotSorry;
    if (x == 0)
        return true;
    else
    {
        while (x != 0)
        {
            sorryNotSorry.push_back(x % 10);
            x /= 10;
        }
    }

    int n = sorryNotSorry.size();
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        int j = n - 1 - i;
        if (sorryNotSorry[i] != sorryNotSorry[j])
            return false;
    }

    return true;
}

int main()
{
    int x;
    cin >> x;
    if (isPalindrome(x))
        cout << "true";
    else
        cout << "false";
    return 0;
}