# def moveElementToEnd(array, toMove):
#     newArray = []
#     for num in array:
#         if num != toMove:
#             newArray.append(num)
#     n = len(array)
#     m = len(newArray)
#     auxiliaryArray = []
#     for i in range(n - m):
#         newArray.append(toMove)

#     return newArray


# def moveElementToEnd(array, toMove):
#     firstIndex = 0
#     flag = False
#     for index in range(len(array)):
#         if flag == True and array[index] != toMove:
#             swap(firstIndex, index, array)
#             firstIndex += 1
#         if array[index] == toMove and flag == False:
#             flag = True
#             firstIndex = index

#     return array


def swap(i, j, array):
    array[i], array[j] = array[j], array[i]
    for num in array:
        print(num, end=" ")
    print()


# def moveElementToEnd(array, toMove):
#     left = 0
#     right = len(array) - 1
#     while left < right:
#         while left < right and array[right] == toMove:
#             right -= 1
#         while left < right and array[left] != toMove:
#             left += 1
#         swap(left, right, array)

#     return array


def moveElementToEnd(array, toMove):
    left = 0
    right = len(array) - 1
    while left < right:
        while left < right and array[right] == toMove:
            right -= 1
        if array[left] == toMove:
            swap(left, right, array)

        left += 1

    return array


array = input().split()
for i in range(len(array)):
    array[i] = int(array[i])

toMove = input()
toMove = int(toMove)

array = moveElementToEnd(array, toMove)
