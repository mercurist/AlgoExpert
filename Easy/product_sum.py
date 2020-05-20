def productSumHelper(lst, depth=1):
    result = 0
    for num in lst:
        if type(num) == int:
            result = result + (num)
        elif type(num) == list:
            result = result + (productSumHelper(num, depth + 1))

    return result * depth


# lst = [3, 4, 5, [6, 7]]
lst = [[[[[5]]]]]
print(productSumHelper(lst))
