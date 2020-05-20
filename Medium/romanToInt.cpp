#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> conversionTable = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}, {'\0', 0}};

    int totalSum = 0;
    int lengthOfString = s.size();
    char previousCharacter = s[lengthOfString - 1];
    totalSum += conversionTable[previousCharacter];
    for (int index = lengthOfString - 2; index >= 0; index--)
    {
        if (s[index] == 'I')
        {
            if (previousCharacter != 'V' && previousCharacter != 'X')
                totalSum += conversionTable[s[index]];
            else
                totalSum -= conversionTable[s[index]];
        }

        else if (s[index] == 'X')
        {
            if (previousCharacter != 'L' && previousCharacter != 'C')
                totalSum += conversionTable[s[index]];
            else
                totalSum -= conversionTable[s[index]];
        }

        else if (s[index] == 'C')
        {
            if (previousCharacter != 'D' && previousCharacter != 'M')
                totalSum += conversionTable[s[index]];
            else
                totalSum -= conversionTable[s[index]];
        }

        else
        {
            totalSum += conversionTable[s[index]];
        }

        previousCharacter = s[index];
    }

    return totalSum;
}

int main()
{
    string x;
    cin >> x;
    cout << romanToInt(x) << '\n';
    return 0;
}