color = {'black' : 0, 
         'brown' : 1,
         'red' : 2,
         'orange' : 3,
         'yellow' : 4,
         'green' : 5,
         'blue' : 6,
         'violet' : 7,
         'grey' : 8,
         'white' : 9}

tmp = ''
for _ in range(3):
    a = input()
    tmp += str(color[a])

answer = int(tmp[:2]) * (10**int(tmp[2]))
print(answer)