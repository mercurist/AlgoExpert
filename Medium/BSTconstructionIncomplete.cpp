#include <vector>
using namespace std;

class BST
{
public:
    int val;
    BST *left;
    BST *right;

    BST(int val)
    {
        val = val;
        left = NULL;
        right = NULL;
    }

    BST &insert(int val)
    {
        // Write your code here.
        // if the tree is Empty
        if (this == NULL)
        {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }

        // if the tree is non-Empty, find a suitable location to add the current node
        else
        {
            if (val >= this->val)
                this->right->insert(val);
            else if (val < this->val)
                this->left->insert(val);
        }
        return *this;
    }

    bool contains(int val)
    {
        // Write your code here.
        BST *node = this;
        while (node != NULL)
        {
            if (val == node->val)
                return true;
            else if (val > node->val)
                node = node->right;
            else
                node = node->left;
        }

        return false;
    }

    BST &Remove(int val)
    {
        // Write your code here.
        BST *node = this;
        if (val == node->val)
        {
            if (node->right == NULL)
            {
                node = node->left;
            }
            else
            {
                // find the number just greater than 10
                BST *rightParent = node->right;
                BST *leftChild = rightParent->left;

                if (leftChild == NULL)
                {
                    // swap node with rightParent
                    rightParent->left = node->left;
                }
                // while (leftChild->left != NULL)
                // {
                //     rightParent = leftChild;
                //     leftChild = leftChild->left;
                // }
                // now leftChild is NULL
                // so swap node with rightParent
            }
        }

        return *this;
    }
};
