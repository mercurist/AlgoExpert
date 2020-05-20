def findClosestValueInBST(tree, target):
    return findClosestValueInBSTHelper(tree, target, float("inf"))


def findClosestValueInBSTHelper(tree, target, closest):
    # helper function
    # base case
    if tree is None:
        return closest

    if abs(target - closest) > abs(target - tree.data):
        closest = tree.data

    if target > tree.data:
        return findClosestValueInBSTHelper(tree.right, target, closest)
    elif target < tree.data:
        return findClosestValueInBSTHelper(tree.left, target, closest)
    else:
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
target = int(target)
print(findClosestValueInBST(tree, target))
