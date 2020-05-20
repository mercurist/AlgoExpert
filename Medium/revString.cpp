#include <string>
#include <iostream>
using namespace std;

void reverseString(const char *str)
{
    if (*str == '\0')
        return;
    reverseString(str + 1);
    cout << *str;
}

int main()
{
    char stuff[100] = "new york";
    reverseString(stuff);
    return 0;
}