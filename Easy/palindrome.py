def isPalindrome(string):
    n = len(string)
    return isPalindromeHelper(string, n)


def isPalindromeHelper(string, sizeOfString):
    if sizeOfString < 2:
        return True
    if sizeOfString == 2:
        return string[0] == string[1]
    if string[0] != string[sizeOfString - 1]:
        return False
    return isPalindromeHelper(string[1 : sizeOfString - 1], sizeOfString - 2)


string = input()
if isPalindrome(string):
    print("yahoo")
