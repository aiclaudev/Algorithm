a = input()
a = a[::-1]
sum = 0
for i in range(len(a)):
    tmp = a[i]
    if tmp == 'A':
        tmp = 10
    elif tmp == 'B':
        tmp = 11
    elif tmp == 'C':
        tmp = 12
    elif tmp == 'D':
        tmp = 13
    elif tmp == 'E':
        tmp = 14
    elif tmp == 'F':
        tmp = 15
    else :
        tmp = int(tmp)
    sum += (16**i) * tmp
print(sum)