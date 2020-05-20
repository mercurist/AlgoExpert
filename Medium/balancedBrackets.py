def balancedBrackets(string):
    openingBrackets = ["(", "{", "["]
    closingBrackets = [")", "}", "]"]

    opposite = {"{": "}", "(": ")", "[": "]"}
    n = len(string)
    stack = []
    for i in range(n):
        if string[i] in openingBrackets:
            stack.append(string[i])
        else:
            if len(stack) == 0:
                return False
            if opposite[stack[-1]] == string[i]:
                stack.pop()
            else:
                return False

    return len(stack) == 0
