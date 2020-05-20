# def threeNumberSum(array, targetSum):
#     final_list = []
#     array = sorted(array)
#     n = len(array)
#     for i in range(n):
#         for j in range(i + 1, n):
#             for k in range(j + 1, n):
#                 if array[i] + array[j] + array[k] == targetSum:
#                     temp_list = [array[i], array[j], array[k]]
#                     final_list.append(temp_list)

#     return final_list

# The following code suffers from duplicacy
def threeNumberSum(array, targetSum):
    resultList = []
    hashMap = dict()
    for num in array:
        hashMap[num] = True
    n = len(array)
    for i in range(n):
        hashMap[array[i]] = False

        for j in range(i + 1, n):
            hashMap[array[j]] = False
            currentSum = array[i] + array[j]
            requiredSum = targetSum - currentSum
            if requiredSum not in hashMap or hashMap[requiredSum] == False:
                continue
            resultList.append([array[i], array[j], requiredSum])
            hashMap[array[j]] = True

        hash[array[i]] = True

    return resultList
