def bubbleSort(array):
    isSorted = False
    counter = 0
    while not isSorted:
        isSorted = True
        for i in range(len(array) - 1 - counter):
            if array[i] > array[i + 1]:
                swap(i, i + 1, array)
                isSorted = False

        counter = counter + 1

    return array


def swap(i, j, array):
    array[i], array[j] = array[j], array[i]


def bubbleSortAgain(array):
    # Write your code here.
    n = len(array)
    for i in range(n):
        swapped = False
        for j in range(n - 1 - i):
            if array[j] > array[j + 1]:
                temp = array[j + 1]
                array[j + 1] = array[j]
                array[j] = temp
                swapped = True

        if swapped == False:
            break
    return array

