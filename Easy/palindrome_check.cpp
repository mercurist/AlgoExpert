#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    // Write your code here.
    string str2 = "";
    for (int i = str.size() - 1; i >= 0; i--)
    {
        str2.push_back(str[i]);
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != str2[i])
            return false;
    }
    // int n = str.size();
    // for (int i = 0; i < ((n+1)/2); i++)
    // {
    // 	if (str[i]!= str[n-1-i])
    // 			return false;
    // }
    return true;
}

int main()
{
    string in;
    cin >> in;
    if (isPalindrome(in))
        cout << "yay";
    else
        cout << "nah";

    return 0;
}