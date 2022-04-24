N = int(input())
sit = [([-1]*(N+2)) for _ in range(N+2)]
love_lst = [[] for _ in range(N**2+1)]

for i in range(len(sit)) :
    for j in range(len(sit[0])) :
        if i == 0 or i == N+1 :
            sit[i][j] = -10
        elif j == 0 or j == N+1 :
            sit[i][j] = -10

for t in range(N**2) :
    a, b, c, d, e = map(int, input().split())
    love_lst[a].append(b)
    love_lst[a].append(c)
    love_lst[a].append(d)
    love_lst[a].append(e)

    #if t == 0 :
       #sit[round(N/2)][round(N/2)] = a
        #continue
    
    love_count_dict = dict([])
    for i in range(1, N+1) :
        for j in range(1, N+1) :
            
            if sit[i][j] != -1 :
                continue

            count = 0
            if sit[i-1][j] in love_lst[a] :
                count += 1
            if sit[i+1][j] in love_lst[a] :
                count += 1
            if sit[i][j-1] in love_lst[a] :
                count += 1
            if sit[i][j+1] in love_lst[a] :
                count += 1
            
            love_count_dict[(i,j)] = count
    max = -1
    love_count_lst = []
    for i in love_count_dict :
        if love_count_dict[i] > max :
            max = love_count_dict[i]
    for i in love_count_dict :
        if love_count_dict[i] == max :
            love_count_lst.append(i)
    
    if len(love_count_lst) == 1 :
        sit[love_count_lst[0][0]][love_count_lst[0][1]] = a
        continue
    
    else :
        empty_count_dict = dict([])
        for i in love_count_lst :
            count = 0
            if sit[i[0]-1][i[1]] == -1 :
                count += 1
            if sit[i[0]+1][i[1]] == -1 :
                count += 1
            if sit[i[0]][i[1]-1] == -1 :
                count += 1
            if sit[i[0]][i[1]+1] == -1 :
                count += 1
            empty_count_dict[i] = count
        max = -1
        empty_count_lst = []
        for i in empty_count_dict :
            if empty_count_dict[i] > max :
                max = empty_count_dict[i]
        for i in empty_count_dict :
            if empty_count_dict[i] == max :
                empty_count_lst.append(i)
        #print(empty_count_dict)
        
        if len(empty_count_lst) == 1 :
            sit[empty_count_lst[0][0]][empty_count_lst[0][1]] = a
            continue 
        else :
            row_min = empty_count_lst[0][0]
            row_min_lst = []
            for i in empty_count_lst :
                if i[0] < row_min :
                    row_min = i[0]
            for i in empty_count_lst :
                if i[0] == row_min :
                    row_min_lst.append(i)

            if len(row_min_lst) == 1 :
                sit[row_min_lst[0][0]][row_min_lst[0][1]] = a
                continue

            else :
                col_min = row_min_lst[0][1]
                col_min_lst = []
                for i in row_min_lst :
                    if i[1] < col_min :
                        col_min = i[1]
                for i in row_min_lst :
                    if i[1] == col_min :
                        col_min_lst.append(i)
                sit[col_min_lst[0][0]][col_min_lst[0][1]] = a

satisfy_lst = []
for i in range(1, N+1) :
    for j in range(1, N+1) :
        count = 0
        k = sit[i][j]
        if sit[i+1][j] in love_lst[k] :
            count += 1
        if sit[i-1][j] in love_lst[k] :
            count += 1
        if sit[i][j+1] in love_lst[k] :
            count += 1
        if sit[i][j-1] in love_lst[k] :
            count += 1
        if count == 0 :
            satisfy_lst.append(0)
        else :
            satisfy_lst.append(10**(count-1))
#for i in range(len(sit)) :
#    for j in range(len(sit[0])) :
#        print(sit[i][j], end = '\t')
#    print('\n')
print(sum(satisfy_lst))