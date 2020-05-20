#include <bits/stdc++.h>
using namespace std;

class LinkedList
{
public:
    int value;
    LinkedList *next;

    LinkedList(int value);
    void addMany(vector<int> values);
    LinkedList *getNthNode(int n);
};

LinkedList::LinkedList(int value)
{
    this->value = value;
    this->next = NULL;
}

void LinkedList::addMany(vector<int> values)
{
    LinkedList *current = this;
    while (current->next != NULL)
    {
        current = current->next;
    }
    for (int value : values)
    {
        current->next = new LinkedList(value);
        current = current->next;
    }
}

LinkedList *LinkedList::getNthNode(int n)
{
    int counter = 1;
    LinkedList *current = this;
    while (counter < n)
    {
        current = current->next;
        counter++;
    }
    return current;
}

LinkedList *findLoop(LinkedList *head)
{
    // Write your code here.
    unordered_map<LinkedList *, bool> table;
    LinkedList *trav = head;
    while (trav != NULL)
    {
        if (table.find(trav) == table.end())
            table[trav] = true;
        else
            return trav;
        trav = trav->next;
    }
    return NULL;
}