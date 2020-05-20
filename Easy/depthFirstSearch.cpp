#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string name;
    vector<Node *> children;

    Node(string str)
    {
        name = str;
    }

    Node *addChild(string name)
    {
        Node *newChild = new Node(name);
        children.push_back(newChild);
        return this;
    }

    /*
    void depthFirstSearchHelper(vector<string> *array, stack<Node *> &dfsStack)
    {
        Node *topOfStack = dfsStack.top();
        (*array).push_back(topOfStack->name);

        for (int i = 0; i < topOfStack->children.size(); i++)
        {
            dfsStack.push(topOfStack->children[i]);
            depthFirstSearchHelper(array, dfsStack);
        }
        dfsStack.pop();
    }

    vector<string> depthFirstSearch(vector<string> *array)
    {
        stack<Node *> dfsStack;
        dfsStack.push(this);
        depthFirstSearchHelper(array, dfsStack);

        return *array;
    }
*/
    vector<string> depthFirstSearch(vector<string> *array)
    {
        array->push_back(this->name);
        for (int i = 0; i < this->children.size(); i++)
            children[i]->depthFirstSearch(array);
        return *array;
    }
};

int main()
{
    Node root("A");
    root.addChild("B");
    root.addChild("C");
    root.addChild("D");

    root.children[0]->addChild("E");
    root.children[0]->addChild("F");

    vector<string> array;
    array = root.depthFirstSearch(&array);
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    return 0;
}
