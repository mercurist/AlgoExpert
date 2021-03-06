#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value);
};

Node ::Node(int value)
{
    this->value = value;
    prev = NULL;
    next = NULL;
}

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // O(N) time || O(1) space
    bool containsNodeWithValue(int value)
    {
        Node *node = head;
        while (node != NULL && node->value != value)
            node = node->next;
        return node != NULL;
    }

    void removeNodeBindings(Node *node)
    {
        if (node->prev != NULL)
            node->prev->next = node->next;
        if (node->next != NULL)
            node->next->prev = node->prev;

        node->prev = NULL;
        node->next = NULL;
    }

    // O(1) space || O(1) time
    void remove(Node *node)
    {
        if (node == head)
            head = head->next;
        if (node == tail)
            tail = tail->prev;
        removeNodeBindings(node);
    }

    // O(N) time || O(1) space
    void removeNodesWithValue(int value)
    {
        Node *node = head;
        while (node != NULL)
        {
            Node *nodeToRemove = node;
            node = node->next;
            if (nodeToRemove->value == value)
                remove(nodeToRemove);
        }
    }

    // O(1) time || O(1) space
    void insertBefore(Node *node, Node *nodeToInsert)
    {
        // IF the list contains only one element and nodeToInsert is that element
        // adding the same element to itself will cause infinite loops
        if (nodeToInsert == head && nodeToInsert == tail)
            return;

        remove(nodeToInsert);
        nodeToInsert->next = node;
        nodeToInsert->prev = node->prev;

        if (node->prev == NULL)
            head = nodeToInsert;
        else
            node->prev->next = nodeToInsert;
        node->prev = nodeToInsert;
    }

    // O(1) time || O(1) space
    void insertAfter(Node *node, Node *nodeToInsert)
    {
        if (nodeToInsert == head && nodeToInsert == tail)
            return;

        remove(nodeToInsert);
        nodeToInsert->prev = node;
        nodeToInsert->next = node->next;

        if (node->next == NULL)
            tail = nodeToInsert;
        else
            node->next->prev = nodeToInsert;
        node->next = nodeToInsert;
    }

    // O(1) time || O(1) space
    void setHead(Node *node)
    {
        if (head == NULL)
        {
            head = node;
            tail = node;
            return;
        }

        insertBefore(head, node);
    }

    // O(1) time || O(1) space
    void setTail(Node *node)
    {
        if (tail == NULL)
        {
            head = node;
            tail = node;
            return;
        }

        insertAfter(tail, node);
    }

    // O(p) time || O(1) space
    void insertAtPosition(int position, Node *nodeToInsert)
    {
        if (position == 1)
        {
            setHead(nodeToInsert);
            return;
        }

        Node *node = head;
        int currentPosition = 1;
        while (node != NULL && currentPosition++ != position)
            node = node->next;

        if (node != NULL)
            insertBefore(node, nodeToInsert);
        else
            setTail(nodeToInsert);
    }
};

int main()
{
    return 0;
}