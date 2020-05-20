number_of_elements = input()
target_sum = input()
array = []

number_of_elements = int(number_of_elements)
target_sum = int(target_sum)

for i in range(number_of_elements):
    temp = int(input())
    array.append(temp)


def twoNumberSum(array, target_sum):
    nums = {}
    for num in array:
        potentialMatch = target_sum - num
        if potentialMatch in nums:
            return [num, potentialMatch]
        else:
            nums[num] = True

    return []


# result = twoNumberSum(array, target_sum)
# for num in result:
#     print(num, end=" ")

"""
def bruteForceSum(array, target_sum):
    for i in range(len(array) - 1):
        for j in range(i + 1, len(array)):
            if array[i] + array[j] == target_sum:
                return [array[i], array[j]]

    return []


result = bruteForceSum(array, target_sum)
for num in result:
    print(num, end=" ")
"""


def sortingSearch(array, target_sum):
    # array = sorted(array)
    array.sort()
    left = 0
    right = len(array) - 1
    while left < right:
        current_sum = array[left] + array[right]
        if current_sum == target_sum:
            return [array[left], array[right]]
        elif current_sum > target_sum:
            right = right - 1
        else:
            left = left + 1

    return []


result = sortingSearch(array, target_sum)
for num in result:
    print(num, end=" ")
