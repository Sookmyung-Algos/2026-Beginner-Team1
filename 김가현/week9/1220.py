A = input(); B = input()

n = len(A); m = len(B)

prev = [0] * (m + 1)

for i in range(1, n + 1):
    curr = [0] * (m + 1)
    for j in range(1, m + 1):
        if A[i - 1] == B[j - 1]:
            curr[j] = prev[j - 1] + 1
        else:
            curr[j] = max(prev[j], curr[j - 1])
    prev = curr

print(prev[m])