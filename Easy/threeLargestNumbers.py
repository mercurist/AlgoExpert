# array = [141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]
array = [7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7]

lst = [None, None, None]

for i in range(3):
    largest = None
    for num in array:
        if type(num) is int:
            if largest is None:
                largest = num
            elif num > largest:
                largest = num

    lst[2 - i] = largest
    for j in range(len(array)):
        if array[j] is None:
            continue
        else:
            if array[j] == largest:
                array[j] = None
                break

for num in lst:
    print(num, end=" ")
