def riverSizes(matrix):
    rows = len(matrix)
    columns = len(matrix[0])

    count = []
    for i in range(rows):
        for j in range(columns):
            if matrix[i][j] == 1:
                tempSize = 0
                riverSizesHelper(matrix, rows, columns, i, j, tempSize, count, 0)
                print()
    return count


def riverSizesHelper(
    matrix, rows, columns, currentRow, currentColumn, tempSize, count, depth
):
    # validating that the co-ordinates of the current element falls within array bounds
    if currentRow >= rows or currentRow < 0:
        return
    if currentColumn >= columns or currentColumn < 0:
        return

    # is the current Element a part of the river
    if (
        matrix[currentRow][currentColumn] == 1
        or matrix[currentRow][currentColumn] == -1
    ):
        print("incrementing tempSize to", str(tempSize + 1))
        if matrix[currentRow][currentColumn] == 1:
            tempSize += 1
            matrix[currentRow][currentColumn] == -1
        matrix[currentRow][currentColumn] = 0
        flag1 = riverSizesHelper(
            matrix,
            rows,
            columns,
            currentRow,
            currentColumn + 1,
            tempSize,
            count,
            depth + 1,
        )
        flag2 = riverSizesHelper(
            matrix,
            rows,
            columns,
            currentRow + 1,
            currentColumn,
            tempSize,
            count,
            depth + 1,
        )

        flag3 = riverSizesHelper(
            matrix,
            rows,
            columns,
            currentRow - 1,
            currentColumn,
            tempSize,
            count,
            depth + 1,
        )
        flag4 = riverSizesHelper(
            matrix,
            rows,
            columns,
            currentRow,
            currentColumn - 1,
            tempSize,
            count,
            depth + 1,
        )


# matrix = [
#     [1, 0, 0, 1, 0],
#     [1, 0, 1, 0, 0],
#     [0, 0, 1, 0, 1],
#     [1, 0, 1, 0, 1],
#     [1, 0, 1, 1, 0],
# ]

matrix = [
    [1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0],
    [1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0],
    [0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1],
    [1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0],
    [1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1],
]

# rows = print(len(matrix))
# columns = print(len(matrix[0]))
print(riverSizes(matrix))
