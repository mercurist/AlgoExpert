def binarySearch(array, target):
    return binarySearchHelper(array, target, 0, len(array) - 1)


def binarySearchHelper(array, target, left, right):
    if left > right:
        return -1
    mid = int((left + right) / 2)
    if array[mid] == target:
        return mid
    elif array[mid] > target:
        return binarySearchHelper(array, target, left, mid - 1)
    else:
        return binarySearchHelper(array, target, mid + 1, right)
