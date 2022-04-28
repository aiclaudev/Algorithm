N = int(input())
table = [[0]*(N+1) for _ in range(N+1)]
T = [0]
P = [0]
for _ in range(N) :
    t, p = map(int, input().split())
    T.append(t)
    P.append(p)

for i in range(1, N+1) :
    t = T[i]
    for j in range(1, N+1) :
        
        if i == j :
            continue
        if j < i + t :
            continue 
        if j + T[j] <= N+1 :
            table[i][j] = P[j]
"""
for i in range(1, len(table)) :
    for j in range(1, len(table[0])) :
        print(table[i][j], end = '\t')
    print('\n')
"""

def rec(table, n) :
    idx = []
    
    for k in range(1, N+1) :
        if table[n][k] != 0 :
            idx.append(k)
    if len(idx) == 0 :
        return 0
    
    sum = []

    for i in idx :
        sum.append(rec(table, i) + table[n][i])

    return max(sum)

result = []
for i in range(1, N+1) :
    if T[i] + i > N+1 :
        a = 0
    else :
        a = P[i]
    result.append(rec(table, i) + a)

print(max(result))
#result = []
#for i in range(1, 7) :
    
        
        
    





    
    