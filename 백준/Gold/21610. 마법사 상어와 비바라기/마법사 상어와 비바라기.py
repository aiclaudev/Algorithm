from collections import deque 

N, M = map(int, input().split())
table = [[0]*(N+2) for _ in range(N+2)]

for i in range(1, N+1) :
    a = list(map(int, input().split()))
    table[i][1:N+1] = a[:]

move = deque()
for _ in range(M) :
    a = list(map(int, input().split()))
    move.append(a)

cloud_lst = deque()
cloud_lst.append([N,1])
cloud_lst.append([N,2])
cloud_lst.append([N-1,1])
cloud_lst.append([N-1,2])


ovx = [0, 0, -1, -1, -1, 0, 1, 1, 1]
ovy = [0, -1, -1, 0, 1, 1, 1, 0, -1]
for m in move :
    isvisited = [[False]*(N+2) for _ in range(N+2)]
    for i in range(len(cloud_lst)) :
        for j in range(m[1]) :
            
            cloud_lst[i][0] += ovx[m[0]]
            cloud_lst[i][1] += ovy[m[0]]
            
            if cloud_lst[i][0] == 0 :
                cloud_lst[i][0] = N
            elif cloud_lst[i][0] == N+1 :
                cloud_lst[i][0] = 1
            
            if cloud_lst[i][1] == 0 :
                cloud_lst[i][1] = N
            elif cloud_lst[i][1] == N+1 :
                cloud_lst[i][1] = 1

    for i in cloud_lst :
        table[i[0]][i[1]] += 1
    
    tmp_lst = cloud_lst.copy()
    cloud_lst.clear()

    for i in tmp_lst :
        count = 0
        r, c = i[0], i[1]

        tmp = [[r-1, c-1], [r-1, c+1], [r+1, c-1], [r+1, c+1]]
        remove_lst = deque()
        for j in range(len(tmp)) :
            if (tmp[j][0] in range(1, N+1)) or (tmp[j][1] in range(1, N+1)) :
                remove_lst.append(tmp[j])

        for k in remove_lst :
            if table[k[0]][k[1]] != 0 :
                count += 1
        
        table[r][c] += count

    for i in tmp_lst :
        isvisited[i[0]][i[1]] = True

    for i in range(1, N+1) :
        for j in range(1, N+1) :
            if table[i][j] >= 2 and not isvisited[i][j] :
                cloud_lst.append([i, j])
                table[i][j] -= 2
                
sum = 0
for i in range(1,N+1) :
    for j in range(1,N+1) :
        sum += table[i][j]
print(sum)






