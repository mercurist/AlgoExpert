def levenshteinDistance(str1, str2):
    matrix = [[0] * (len(str2) + 1)] * (len(str1) + 1)

    display(matrix, str1, str2)

    for i in range(len(str1) + 1):
        for j in range(len(str2) + 1):
            if i == 0:
                matrix[i][j] = "X"
                display(matrix, str1, str2)
            elif j == 0:
                matrix[i][j] = i
                display(matrix, str1, str2)
            else:
                if str1[i - 1] == str2[j - 1]:
                    temp = 0
                else:
                    temp = 1
                matrix[i][j] = min(
                    matrix[i][j - 1] + 1,
                    matrix[i - 1][j] + 1,
                    matrix[i - 1][j - 1] + temp,
                )
                display(matrix, str1, str2)
    return matrix[len(str1)][len(str2)]


def display(matrix, str1, str2):
    print()
    for i in range(len(str1) + 1):
        for j in range(len(str2) + 1):
            print(matrix[i][j], end=" \n"[j == len(str2)])


str1 = input()
str2 = input()

print(levenshteinDistance(str1, str2))
