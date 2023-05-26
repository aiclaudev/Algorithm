r, c = map(int, input().split())
map = []
for i in range(r):
    map.append(input())
sequence = []
answer = {'1':0, '2':0, '3':0, '4':0, '5':0, '6':0, '7':0, '8':0, '9':0}
for i in range(r):
    team = 0
    for j in range(c):
        if map[i][j].isdigit():
            team = map[i][j]
            sequence.append(team)
            break
    
    if team != 0:
        tmp = map[i][::-1]
        val = tmp.find(team)
        answer[team] = val

tmp = sorted(list(answer.values()))
tmp = list(set(tmp))

final = []
for key, val in answer.items():
    final.append(tmp.index(val)+1)
#print(final)
for i in final:
    print(i)

    