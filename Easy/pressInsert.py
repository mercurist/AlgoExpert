def insertionSort(array):
    n = len(array)
    for i in range(1, n):
        j = i - 1
        while array[j] > array[j + 1] and j >= 0:
            swap(j, j + 1, array)
            j = j - 1
        for num in array:
            print(num, end=" ")
        print()


def swap(i, j, array):
    array[i], array[j] = array[j], array[i]


array = input().split()
for i in range(0, len(array)):
    array[i] = int(array[i])
print(type(array))
print(type(array[0]))
insertionSort(array)
