#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node() {}

    Node(int x) : val(x), next(NULL) {}
};

Node *createNewNode(int val)
{
    Node *node = new Node();
    node->val = val;
    node->next = NULL;
    return node;
}

class List
{
public:
    Node *head;
    List()
    {
        head = NULL;
    }

    List(Node *root)
    {
        head = root;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void insertNode(int val)
    {
        Node *node = createNewNode(val);
        if (isEmpty() == true)
        {
            head = node;
            return;
        }
        else
        {
            // traverse to the end of the list
            Node *trav = head;
            while (trav->next != NULL)
                trav = trav->next;
            trav->next = node;
        }
    }

    void display()
    {
        cout << '\n';
        Node *trav = head;
        cout << "head";
        while (trav != NULL)
        {
            cout << " -> " << trav->val;
            trav = trav->next;
        }
    }

    Node *swapAlternateHelper(Node *currentNode)
    {
        if (currentNode == NULL)
            return currentNode;

        Node *nextNode = currentNode->next;
        if (nextNode == NULL)
            return currentNode;

        Node *nextToNextNode = nextNode->next;
        nextNode->next = currentNode;
        currentNode->next = swapAlternateHelper(nextToNextNode);

        return nextNode;
    }

    void swapAlternates()
    {
        head = swapAlternateHelper(head);
    }
};

Node *addTwoNumbers(Node *l1, Node *l2)
{
    int sum = 0;
    Node *l3 = NULL;
    Node **node = &l3;

    while (l1 != NULL || l2 != NULL || sum > 0)
    {
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        // allocate a new memory block and assign its address to the node variable
        (*node) = new Node(sum % 10);
        // self-explanatory
        sum /= 10;
        // change node to its next
        node = &((*node)->next);
    }

    return l3;
}

int main()
{
    List x, y;
    x.insertNode(2);
    x.insertNode(4);
    x.insertNode(3);

    y.insertNode(5);
    y.insertNode(6);
    y.insertNode(4);
    y.insertNode(4);

    x.display();
    y.display();

    Node *result = addTwoNumbers(x.head, y.head);
    List z(result);
    z.display();

    return 0;
}