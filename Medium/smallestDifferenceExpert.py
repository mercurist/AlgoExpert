# def smallestDifference(arrayOne, arrayTwo):
#     arrayOne.sort()
#     arrayTwo.sort()

#     n1 = len(arrayOne)
#     n2 = len(arrayTwo)

#     smallestDifference = abs(arrayOne[0] - arrayTwo[0])
#     result = [arrayOne[0], arrayTwo[0]]

#     i, j = 0, 0
#     while i < n1 and j < n2:
#         currentDifference = abs(arrayOne[i] - arrayTwo[j])
#         if currentDifference == 0:
#             return [arrayOne[i], arrayTwo[j]]
#         elif currentDifference < smallestDifference:
#             smallestDifference = currentDifference
#             result = [arrayOne[i], arrayTwo[j]]
#         if arrayOne[i] <= arrayTwo[j]:
#             i += 1
#         else:
#             j += 1

#     return result


def smallestDifference(arrayOne, arrayTwo):
    arrayOne.sort()
    arrayTwo.sort()

    n1 = len(arrayOne)
    n2 = len(arrayTwo)

    smallestDifference = abs(arrayOne[0] - arrayTwo[0])
    result = [arrayOne[0], arrayTwo[0]]

    i, j = n1 - 1, n2 - 1
    while i >= 0 and j >= 0:
        currentDifference = abs(arrayOne[i] - arrayTwo[j])
        if currentDifference == 0:
            return [arrayOne[i], arrayTwo[j]]
        elif currentDifference < smallestDifference:
            smallestDifference = currentDifference
            result = [arrayOne[i], arrayTwo[j]]
        if arrayOne[i] <= arrayTwo[j]:
            j -= 1
        else:
            i -= 1

    return result
