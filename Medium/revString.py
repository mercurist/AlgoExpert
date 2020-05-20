def reverseString(string):
    reverseStringHelper(string, len(string) - 1)


def reverseStringHelper(string, index):
    if index == 0:
        print(string[index], end="")
        return

    print(string[index], end="")
    reverseStringHelper(string, index - 1)


string = input()
reverseString(string)
