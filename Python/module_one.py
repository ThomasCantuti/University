def f(x, y = 10):
    return x + y

def g(x):
    return x**3

if __name__ == "__main__":
    print(f(2))
    print(f(g(2)))
