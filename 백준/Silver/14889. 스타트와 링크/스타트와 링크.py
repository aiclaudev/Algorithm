from itertools import combinations
N = int(input())
table = [[] for _ in range(N+1)]
for i in range(len(table)) :
    if i == 0 :
        for j in range(N+1) :
            table[i].append(0)
    else :
        table[i].append(0)

for i in range(1, N+1) :
    lst = list(map(int, input().split()))
    for j in lst :
        table[i].append(j)

items = list(range(1, N+1))
comb = list(combinations(items, N//2))

def diff(lst) :
    lst2 = []
    for i in range(1, N+1) :
        if i not in lst :
            lst2.append(i)
    a = 0
    b = 0
    for i in range(len(lst)) :
        for j in range(len(lst)) :
            a += table[lst[i]][lst[j]]
            b += table[lst2[i]][lst2[j]]
    return abs(a-b)

result = []
for i in range(len(comb)) :
    start = list(comb[i])
    result.append(diff(start))

print(min(result))
    

            