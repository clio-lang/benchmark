import time


def fib(n, a, b):
    if n == 0:
        return a
    elif n == 1:
        return b
    else:
        fib(n - 1, b, a+b)


minimum = 100000000

for i in range(10000):
    start = time.time()
    fib(998, 1, 0)
    end = time.time()
    minimum = min(end-start, minimum)

print(f"Took {minimum*1000*1000*1000}ns")
