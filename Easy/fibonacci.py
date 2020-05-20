index = input()
index = int(index)


def fibonacci(n):
    if (n == 1) or (n == 2):
        return n - 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


print(fibonacci(index))


def fibonacciFaster(n, memoize={1: 0, 2: 1}):
    if n in memoize:
        return memoize[n]
    else:
        memoize[n] = fibonacciFaster(n - 1) + fibonacciFaster(n - 2)
        return memoize[n]


index = input()
index = int(index)
print(fibonacciFaster(index))
