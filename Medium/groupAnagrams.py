def groupAnagrams(words):
    sortedWords = ["".join(sorted(w)) for w in words]
    indices = [i for i in range(len(words))]
    indices.sort(key=lambda x: sortedWords[x])

    result = []
    currentAnagramGroup = []
    currentAnagram = sortedWords[indices[0]]

    for i in range(len(indices)):
        currentSortedWord = sortedWords[indices[i]]

        if currentSortedWord == currentAnagram:
            currentAnagramGroup.append(words[indices[i]])
        else:
            currentAnagram = currentSortedWord
            result.append(currentAnagramGroup)
            currentAnagramGroup = []
            currentAnagramGroup.append(words[indices[i]])

    result.append(currentAnagramGroup)
    return result


words = input().split()
print(groupAnagrams(words))
