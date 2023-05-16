a, b = input().split()
sum=0
for i in range(len(a)):
  for j in range(len(b)):
    sum += int(a[i])*int(b[j])
print(sum)