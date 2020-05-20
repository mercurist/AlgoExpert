def findClosestValueInBST(tree, target):
    return findClosestValueInBSTHelper(tree, target, float("inf"))


def findClosestValueInBSTHelper(tree, target, closest):
    # helper function

    current_Node = tree
    while current_Node is not None:
        if abs(target - closest) > abs(target - current_Node.data):
            closest = current_Node.data

        if target > current_Node.data:
            current_Node = current_Node.right
        elif target < current_Node.data:
            current_Node = current_Node.left
        else:
            break

    return closest


class BST(object):
    def __init__(self, value):
        self.left = None
        self.right = None
        self.data = value


tree = BST(5)
tree.left = BST(3)
tree.right = BST(11)
tree.left.left = BST(2)
tree.left.right = BST(4)
tree.right.left = BST(8)
tree.right.right = BST(14)


target = input()
try:
    target = int(target)
    print(findClosestValueInBST(tree, target))
except:
    print("invalid input")

