# starting from top-right corner

# def searchInSortedMatrix(matrix, target):
# 	if len(matrix) == 0:
# 		return [-1,-1]
# 	rows = len(matrix)
# 	columns = len(matrix[0])

# 	indices = [0, columns - 1]

# 	while indices[0] < rows and indices[1] >= 0:
# 		if target == matrix[indices[0]][indices[1]]:
# 			return indices
# 		elif target > matrix[indices[0]][indices[1]]:
# 			indices[0] += 1
# 		else :
# 			indices[1] -= 1
# 	return [-1, -1]


# starting from bottom-left corner


def searchInSortedMatrix(matrix, target):
    if len(matrix) == 0:
        return [-1, -1]
    rows = len(matrix)
    columns = len(matrix[0])

    indices = [rows - 1, 0]

    while indices[0] >= 0 and indices[1] < columns:
        if target == matrix[indices[0]][indices[1]]:
            return indices
        elif target > matrix[indices[0]][indices[1]]:
            indices[1] += 1
        else:
            indices[0] -= 1
    return [-1, -1]

