def selectionSort(array):
    n = len(array)
    for i in range(n):
        current = i
        smallest = i
        for j in range(i, n):
            if array[j] < array[smallest]:
                smallest = j

        swap(current, smallest, array)
        for num in array:
            print(num, end=" ")
        print()


def swap(i, j, array):
    array[i], array[j] = array[j], array[i]


array = input().split()
for i in range(len(array)):
    array[i] = int(array[i])

selectionSort(array)
