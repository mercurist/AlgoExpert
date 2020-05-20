#include <bits/stdc++.h>
#include <cmath>
#include <float.h>
using namespace std;

class BST
{
public:
    int value;
    BST *left;
    BST *right;
};

BST *createNewNode(int value)
{
    BST *newNode = new BST;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder_traversal(BST *root)
{
    // base case
    if (root == NULL)
        return;

    // recursive case
    inorder_traversal(root->left);
    cout << root->value << " ";
    inorder_traversal(root->right);
}

void brute_force_traversal(BST *root, int element, tuple<int, int, bool> &target)
{
    if (root == NULL)
        return;

    brute_force_traversal(root->left, element, target);
    if (get<2>(target) == false or (abs(root->value - element) < get<0>(target)))
    {
        get<0>(target) = abs(root->value - element);
        get<1>(target) = root->value;
        get<2>(target) = true;
    }

    brute_force_traversal(root->right, element, target);
}

void perhaps_an_optimisation(BST *root, int element, int &minimum, int &actualElement, bool never = false)
{
    if (root == NULL)
        return;

    if (never == false)
    {
        minimum = abs(root->value - element);
        actualElement = root->value;
        // cout << "minimum set to " << minimum << '\n';
        never = true;
    }

    if (element == root->value)
    {
        minimum = 0;
        actualElement = root->value;
        return;
    }
    else if (element > root->value)
    {
        // cout << "calling right subroutine" << '\n';
        if ((element - root->value) < minimum)
        {
            minimum = element - root->value;
            actualElement = root->value;
        }
        perhaps_an_optimisation(root->right, element, minimum, actualElement, never);
    }

    else
    {
        // cout << "calling left subroutine" << '\n';
        if ((root->value - element) < minimum)
        {
            actualElement = root->value;
            minimum = root->value - element;
        }
        perhaps_an_optimisation(root->left, element, minimum, actualElement, never);
    }
}

int algo_expert_first(BST *root, int target, double closest)
{
    if (abs(target - closest) > abs(target - root->value))
        closest = root->value;

    if (target > root->value && root->right != NULL)
        return algo_expert_first(root->right, target, closest);
    else if (target < root->value && root->left != NULL)
        return algo_expert_first(root->left, target, closest);
    else
        return int(closest);
}

int algo_expert_second(BST *root, int target, double closest)
{
    BST *current_node = root;
    while (current_node != NULL)
    {
        if (abs(target - closest) > abs(target - current_node->value))
            closest = current_node->value;

        if (target > current_node->value)
            current_node = current_node->right;
        else if (target < current_node->value)
            current_node = current_node->left;
        else
            break;
    }

    return closest;
}

int main()
{
    // construction of binary search tree
    BST *root = createNewNode(5);
    root->left = createNewNode(3);
    root->left->left = createNewNode(2);
    root->left->right = createNewNode(4);
    root->right = createNewNode(11);
    root->right->left = createNewNode(8);
    root->right->right = createNewNode(14);

    inorder_traversal(root);

    int element;
    cin >> element;
    /*
    tuple<int, int, bool> target = make_tuple(0, 0, false);
    brute_force_traversal(root, element, target);
    cout << get<1>(target);
    */

    // int minimum, actualElement;
    // perhaps_an_optimisation(root, element, minimum, actualElement);

    // cout << "minimum " << minimum << "\n"
    //      << "nearest element " << actualElement;

    // cout << algo_expert_first(root, element, DBL_MAX);

    cout << algo_expert_second(root, element, DBL_MAX);

    return 0;
}
