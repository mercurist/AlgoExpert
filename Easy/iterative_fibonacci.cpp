#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    int first_num = 0;
    int second_num = 1;
    while (count < n - 2)
    {
        int temp = second_num;
        second_num += first_num;
        first_num = temp;
        count++;
    }
    if (n == 1)
        cout << first_num << '\n';
    else
        cout << second_num << '\n';
    return 0;
}