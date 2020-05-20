#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

stack<int> functionCallStack;
void displayStack(stack<int>, int);

void displayStack(stack<int> functionCallStack, int n)
{
    int temp;
    // int count = 0;
    stack<int> temporary;

    // modify this so the display doesnt move around much
    // for (int i = 0; i < n; i++)
    //     cout << '\n';

    while (functionCallStack.empty() == false)
    {
        // cout << "iteration " << count << '\n';
        temp = functionCallStack.top();
        cout << temp << "\n";
        temporary.push(temp);
        functionCallStack.pop();
        // count++;
    }

    while (temporary.empty() == false)
    {
        temp = temporary.top();
        temporary.pop();
        functionCallStack.push(temp);
    }
}

int getNthFib(int n)
{
    functionCallStack.push(n);
    system("CLS");
    displayStack(functionCallStack, n);
    // insert wait function here
    Sleep(700);

    // please stop at n = 43 or else you'll have to kill the terminal
    if (n == 1 || n == 2)
    {
        functionCallStack.pop();
        system("CLS");
        displayStack(functionCallStack, n);
        // insert wait function here
        Sleep(700);
        return (n - 1);
    }
    else
    {
        // insert wait function here
        Sleep(700);

        int some_value = getNthFib(n - 1) + getNthFib(n - 2);
        functionCallStack.pop();
        system("CLS");
        displayStack(functionCallStack, n);
        Sleep(700);
        return some_value;
    }
}

int getNthFibFasterHelper(int n, vector<int> &memoizer)
{
    if (memoizer[n - 1] != -1)
        return memoizer[n - 1];
    memoizer[n - 1] = getNthFibFasterHelper(n - 1, memoizer) + getNthFibFasterHelper(n - 2, memoizer);
    return memoizer[n - 1];
}

int getNthFibFaster(int n)
{
    vector<int> memoizer(n, -1);
    memoizer[0] = 0;
    memoizer[1] = 1;

    return getNthFibFasterHelper(n, memoizer);
    return 1;
}

int main()
{
    int n;
    cin >> n;
    cout << getNthFibFaster(n) << '\n';
    // cout << getNthFib(n) << '\n';
    return 0;
}