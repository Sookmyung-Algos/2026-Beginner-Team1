N = int(input())
lst = []
for _ in range(N):
    A, B = map(int, input().split())
    if A > B:
        lst.append((A, B))
    else:
        lst.append((B, A))
lst.sort()

lis = [1] * N
for i in range(N):
    for j in range(i):
        if lst[i][0] >= lst[j][0] and lst[i][1] >= lst[j][1]:
            lis[i] = max(lis[i], lis[j] + 1)

print(max(lis))