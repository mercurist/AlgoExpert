#include <vector>
#include <cassert>
using namespace std;

class LinkedList
{
public:
    int value;
    LinkedList *next;

    LinkedList(int value);
    void addMany(vector<int> values);
    vector<int> getNodesInArray();
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

vector<int> LinkedList::getNodesInArray()
{
    vector<int> nodes{};
    LinkedList *current = this;
    while (current != NULL)
    {
        nodes.push_back(current->value);
        current = current->next;
    }
    return nodes;
}

void removeKthNodeFromEnd(LinkedList *head, int k)
{
    LinkedList node = *head;
    // Write your code here.
    int count = 0;
    LinkedList *trav = head;
    while (trav != NULL)
    {
        count++;
        trav = trav->next;
    }
    int distanceFromBegin = count - k;
    trav = head;
    LinkedList *prevToCurrent = head;

    while (distanceFromBegin--)
    {
        prevToCurrent = trav;
        trav = trav->next;
    }

    // if we have to delete the first node
    if (trav == head)
    {
        // head = head->next;
        // instead of above line, do this
        head->value = head->next->value;
        head->next = head->next->next;
    }
    // if we have to delete the last node
    else if (trav->next == NULL)
    {
        prevToCurrent->next = NULL;
    }
    // if we have to delete an intermediate node
    else
    {
        prevToCurrent->next = trav->next;
    }
}

void removeKthNodeFromEndModified(LinkedList **haha, int k)
{
    LinkedList *head = *haha;
    LinkedList node = *head;
    // Write your code here.
    int count = 0;
    LinkedList *trav = head;
    while (trav != NULL)
    {
        count++;
        trav = trav->next;
    }
    int distanceFromBegin = count - k;
    trav = head;
    LinkedList *prevToCurrent = head;

    while (distanceFromBegin--)
    {
        prevToCurrent = trav;
        trav = trav->next;
    }

    // if we have to delete the first node
    if (trav == head)
    {
        // head = head->next;
        haha = &((*haha)->next);
        head = *haha;
    }
    // if we have to delete the last node
    else if (trav->next == NULL)
    {
        prevToCurrent->next = NULL;
    }
    // if we have to delete an intermediate node
    else
    {
        prevToCurrent->next = trav->next;
    }
}

int main()
{
    LinkedList test2(0);
    test2.addMany({1, 2, 3, 4, 5, 6, 7, 8, 9});
    LinkedList result2(0);
    result2.addMany({1, 2, 3, 4, 5, 6, 7, 9});
    LinkedList *head = &test2;
    // removeKthNodeFromEnd(&test2, 2);
    // assert(test2.getNodesInArray() == result2.getNodesInArray());

    // both are equivalent
    removeKthNodeFromEndModified(&head, 2);
    assert((*head).getNodesInArray() == result2.getNodesInArray());
    return 0;
}
