#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    // Write your code here.
    vector<int> result;
    const int number_of_elements = array.size();

    /* 	this solution takes O(n^2) time
	for (int i = 0; i < number_of_elements - 1; i++)
	{
		for (int j = i + 1; j < number_of_elements; j++)
		{
			if ((array[i] + array[j]) == targetSum)
			{
				result.push_back(array[i]);
				result.push_back(array[j]);
			}
		}
	}
*/

    // unordered_map<int, int> counts;
    // for (int i = 0; i < number_of_elements; i++)
    // {
    //     counts[array[i]]++;
    // }
    /*
    cout << "displaying map\n";
    unordered_map<int, int>::iterator itr = counts.begin();
    while (itr != counts.end())
    {
        cout << itr->first << " " << itr->second << '\n';
        itr++;
    }
*/
    /*
    for (int i = 0; i < number_of_elements; i++)
    {
        int current_value = array[i];
        int remainder_needed = targetSum - current_value;
        cout << endl;
        if (current_value != remainder_needed)
        {
            if (counts[remainder_needed] > 0)
            {
                return vector<int>{current_value, remainder_needed};
            }
        }

        if (current_value == remainder_needed)
        {
            if (counts[current_value] > 1)
            {
                return vector<int>{current_value, current_value};
            }
        }
    }
    */

    return {};
}

vector<int> twoNumberSumTwo(vector<int> &array, int targetSum)
{
    int n = array.size();
    // O(n log n)
    sort(array.begin(), array.end());
    int left = 0;
    int right = n - 1;
    // O ( log n)
    while (left < right)
    {
        int current_sum = array[left] + array[right];
        if (current_sum == targetSum)
            return vector<int>{array[left], array[right]};
        else if (current_sum > targetSum)
            right--;
        else
            left++;
    }

    return {};
}

void display(const vector<int> &result)
{
    cout << '\n';
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}

int main()
{
    int number_of_elements, targetSum;
    cin >> number_of_elements >> targetSum;

    vector<int> array(number_of_elements);
    for (int i = 0; i < number_of_elements; i++)
        cin >> array[i];

    vector<int> result = twoNumberSumTwo(array, targetSum);
    display(result);

    return EXIT_SUCCESS;
}
