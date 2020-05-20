# This is the class of the input root. Do not edit it.
class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def branchSums(root):
    array = []
    branchSumsHelper(root, array, 0)
    return array


def branchSumsHelper(root, array, current_Sum):
    if root is None:
        return
    current_Sum += root.value
    if root.left is None and root.right is None:
        array.append(current_Sum)
        return
    branchSumsHelper(root.left, array, current_Sum)
    branchSumsHelper(root.right, array, current_Sum)
