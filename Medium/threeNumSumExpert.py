def threeNumberSum(array, targetSum):
    array.sort()
    result = []
    size = len(array)
    for index in range(size - 2):
        currentSum = array[index]
        requiredSum = targetSum - currentSum

        leftIndex = index + 1
        rightIndex = len(array) - 1

        while leftIndex < rightIndex:
            potentialMatch = array[leftIndex] + array[rightIndex]
            if potentialMatch == requiredSum:
                result.append([array[index], array[leftIndex], array[rightIndex]])
                leftIndex += 1
                rightIndex = size - 1
            elif potentialMatch < requiredSum:
                leftIndex += 1
            else:
                rightIndex -= 1

    return result
