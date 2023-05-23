from collections import Counter
n = int(input())
names = []
for _ in range(n):
    names.append(input())


names = [name[0] for name in names]
counter = Counter(names)

answers = ''
for key, value in counter.items():
    if value >= 5:
        answers += key
if len(answers) >= 1:
    print(''.join(sorted(answers)))
else:
    print("PREDAJA")