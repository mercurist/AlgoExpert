#include <stack>
#include <string>
#include <iostream>
using namespace std;

char switchMeBaby(char ch)
{
	if (ch == '(')
		return ')';
	if (ch == '{')
		return '}';
	if (ch == '[')
		return ']';
}

bool balancedBrackets(string str)
{
	// Write your code here.
	stack<char> table;
	int n = str.size();
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			table.push(str[i]);
		else
		{
			if (table.empty() == true)
				return false;

			char topOfStack = table.top();
			if ((str[i]) == switchMeBaby(topOfStack))
			{
				table.pop();
			}
			else
			{
				return false;
			}
		}
	}

	return (table.empty() == true);
}
