def smallestDifference(arrayOne, arrayTwo):
    n1 = len(arrayOne)
    n2 = len(arrayTwo)

    smallest = [arrayOne[0], arrayTwo[0]]
    for i in range(n1):
        for j in range(n2):
            if abs(arrayOne[i] - arrayTwo[j]) == 0:
                return [arrayOne[i], arrayTwo[j]]
            if abs(arrayOne[i] - arrayTwo[j]) < abs(smallest[0] - smallest[1]):
                smallest = [arrayOne[i], arrayTwo[j]]

    return smallest
