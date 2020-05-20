#include <bits/stdc++.h>
using namespace std;

string caesarCypherEncryptor(string str, int key)
{
    // Write your code here.
    int n = str.size();
    key %= 26;
    for (int i = 0; i < n; i++)
    {
        int result = int(str[i]) + key;
        if (result <= 122)
        {
            str[i] = char(result);
        }
        else
        {
            str[i] = char(96 + result % 122);
        }
        // while (result > 122)
        // {
        //     result += 96 - 122;
        // }
    }
    return str;
}

int main()
{
    string x;
    int key;
    cin >> x >> key;
    cout << caesarCypherEncryptor(x, key);
    return 0;
}