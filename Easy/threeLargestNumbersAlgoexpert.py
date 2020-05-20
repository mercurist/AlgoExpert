# array = [7, 8, 3, 11, 43, 55]
array = [55, 7, 8, 3, 43, 11]
result = [None, None, None]


def shiftAndUpdate(result, num, index):
    for i in range(index + 1):
        if i == index:
            result[i] = num
        else:
            result[i] = result[i + 1]


def updateResult(result, num):
    if result[2] is None or num > result[2]:
        shiftAndUpdate(result, num, 2)
    elif result[1] is None or num > result[1]:
        shiftAndUpdate(result, num, 1)
    elif result[0] is None or num > result[0]:
        shiftAndUpdate(result, num, 0)


for num in array:
    updateResult(result, num)

for num in result:
    print(num, end=" ")

