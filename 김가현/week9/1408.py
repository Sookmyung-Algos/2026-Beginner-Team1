N = int(input())
lst = [list(map(int, input().split())) for _ in range(N)]
lst.sort()
lis = [1] * N

for i in range(N):
    for j in range(i):
        if lst[i][1] > lst[j][1]:
            lis[i] = max(lis[i], lis[j] + 1)

print(N - max(lis))