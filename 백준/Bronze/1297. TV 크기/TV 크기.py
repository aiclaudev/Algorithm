import math
a, b, c = map(int, input().split())
diag = math.sqrt(b**2 + c**2)
tmp = a / diag
print(int(tmp * b), int(tmp*c))