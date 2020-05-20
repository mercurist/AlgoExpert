string = input()

# reversed_string = ""

# for i in reversed(range(len(string))):
#     reversed_string += string[i]

# print(string == reversed_string)

reverse_chars = []
for i in reversed(range(len(string))):
    reverse_chars.append(string[i])

print(string == "".join(reverse_chars))

