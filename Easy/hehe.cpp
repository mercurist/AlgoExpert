#include <iostream>
#include <conio.h>
int main()
{
    int a = 2;
    int *p = &a;
    std::cout << "print: " << a << " " << *p;
    return 0;
}