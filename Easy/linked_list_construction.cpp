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

// Node *createNewNode(int value)
// {
//     Node *temp = new Node;
//     temp->value = value;
//     temp->prev = temp->next = NULL;
//     return temp;
// }

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

    void display()
    {
        cout << '\n';
        if (head == NULL)
        {
            cout << "list is empty";
            return;
        }

        Node *traverse = head;
        while (traverse != NULL)
        {
            cout << traverse->value << " ";
            traverse = traverse->next;
        }
    }

    void setHead(Node *node)
    {
        if (head == NULL)
        {
            head = node;
            tail = node;
            return;
        }
        // if its already head
        if (node == head)
            return;

        // if its not the head, then find the node and delete it and then insert it as head
        Node *getExistingNode = containsNodeWithAddress(node);
        // if list doesnt contain the node
        if (getExistingNode == NULL)
        {
            insertBefore(head, node);
            return;
        }

        // if the nodes exists, then first delete that node and reinsert the node as head
        remove(getExistingNode);
        insertBefore(head, getExistingNode);
    }

    void setTail(Node *node)
    {
        if (tail == NULL)
        {
            head = node;
            tail = node;
            return;
        }

        if (node == tail)
            return;

        Node *getExistingNode = containsNodeWithAddress(node);
        if (getExistingNode == NULL)
        {
            insertAfter(tail, node);
            return;
        }

        remove(getExistingNode);
        insertAfter(tail, getExistingNode);
    }

    Node *containsNodeWithAddress(Node *node)
    {
        Node *traverse = head;
        while (traverse != NULL)
        {
            if (traverse == node)
                return traverse;
            traverse = traverse->next;
        }

        return traverse;
    }

    void insertBefore(Node *node, Node *nodeToInsert)
    {
        if (head == NULL)
        {
            head = nodeToInsert;
            tail = nodeToInsert;
            return;
        }
        if (node != head)
        {
            Node *previousToCurrentNode = node->prev;
            previousToCurrentNode->next = nodeToInsert;
            nodeToInsert->next = node;
            nodeToInsert->prev = previousToCurrentNode;
            node->prev = nodeToInsert;
        }

        // edge case where node is equal to head
        else
        {
            nodeToInsert->next = head;
            head->prev = nodeToInsert;
            head = nodeToInsert;
        }
    }

    void insertAfter(Node *node, Node *nodeToInsert)
    {
        if (head == NULL)
        {
            head = nodeToInsert;
            tail = nodeToInsert;
            return;
        }

        if (node != tail)
        {
            Node *nextToCurrentNode = node->next;
            node->next = nodeToInsert;
            nodeToInsert->prev = node;
            nodeToInsert->next = nextToCurrentNode;
            nextToCurrentNode->prev = nodeToInsert;
        }

        // edge case where node is equal to tail
        else
        {
            nodeToInsert->prev = tail;
            tail->next = nodeToInsert;
            tail = nodeToInsert;
        }
    }

    void insertAtPosition(int position, Node *nodeToInsert)
    {
        bool flag = false;
        int count = 1;
        Node *traverse = head;
        while (count < position)
        {
            if (traverse->next == NULL)
            {
                flag = true;
                break;
            }
            traverse = traverse->next;
            count++;
        }

        if (flag == false)
            insertBefore(traverse, nodeToInsert);
        else
            insertAfter(tail, nodeToInsert);
    }

    void remove(Node *node)
    {
        if (node == head && node == tail)
        {
            setHead(NULL);
            setTail(NULL);
            return;
        }

        if (node == head)
        {
            Node *nextToHead = node->next;
            node->next = NULL;
            nextToHead->prev = NULL;
            head = nextToHead;
            return;
        }

        if (node == tail)
        {
            Node *beforeTail = node->prev;
            node->prev = NULL;
            beforeTail->next = NULL;
            tail = beforeTail;
            return;
        }

        Node *leftToCurrentNode = node->prev;
        Node *rightToCurrentNode = node->next;

        leftToCurrentNode->next = rightToCurrentNode;
        rightToCurrentNode->prev = leftToCurrentNode;
    }

    void removeNodesWithValue(int value)
    {
        Node *traverse = head;
        while (traverse != NULL)
        {
            Node *nextToTraverse = traverse->next;
            if (traverse->value == value)
                remove(traverse);

            traverse = nextToTraverse;
        }
    }

    bool containsNodeWithValue(int value)
    {
        Node *traverse = head;
        while (traverse != NULL)
        {
            if (traverse->value == value)
                return true;

            traverse = traverse->next;
        }
        return false;
    }
};

int main()
{
    DoublyLinkedList x;
    // x.insertAfter(x.head, createNewNode(1));
    // x.insertAfter(x.tail, createNewNode(2));
    // x.insertAfter(x.tail, createNewNode(3));
    // x.insertAfter(x.tail, createNewNode(4));
    // x.insertAfter(x.tail, createNewNode(5));

    vector<Node> listOfNodes;
    for (int i = 1; i < 6; i++)
        listOfNodes.push_back(Node(i));

    x.insertAfter(x.head, &listOfNodes[0]);
    x.insertAfter(x.tail, &listOfNodes[1]);
    x.insertAfter(x.tail, &listOfNodes[2]);
    x.insertAfter(x.tail, &listOfNodes[3]);
    x.insertAfter(x.tail, &listOfNodes[4]);
    x.display();

    x.setHead(&listOfNodes[3]);

    x.display();
    Node sixth(6);
    x.setTail(&sixth);
    x.display();

    x.insertBefore(&sixth, &listOfNodes[2]);
    x.display();
    return 0;
}