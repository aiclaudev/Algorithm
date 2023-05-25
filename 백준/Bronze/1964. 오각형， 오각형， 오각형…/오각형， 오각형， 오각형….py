a = int(input())
def func(n):
    cnt = 1
    sum = 0
    while(cnt <= n) :
        val = 3*cnt+1
        sum += val
        cnt += 1
    return sum + 1
print(func(a)%45678)
