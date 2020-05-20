# lambda arguments : expression
x = lambda a: a + 10
print(x(5))

# lambda functions cantake any number of arguments
x = lambda a, b, c: max(a, b, c)
print(x(1, 231, 44))


def myFunction(n):
    return lambda a: a * n


myDoubler = myFunction(2)
myTripler = myFunction(3)
print(myDoubler(11))
print(myTripler(11))
