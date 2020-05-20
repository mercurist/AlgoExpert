index = input()
index = int(index)

a, b = 0, 1

for c in range(index - 2):
    a, b = b, a + b

result = b if index > 0 else a
print(result)
