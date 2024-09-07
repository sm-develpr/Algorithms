k1, k2, k3 = map(float, input().split())
n = int(input())
y = list(map(float, input().split()))
x = list(map(float, input().split()))
z = list(map(float, input().split()))
mae = 0


def pred(i, k1, k2, k3):
    return k1 * x[i] + k2 * z[i] + k3


for i in range(n):
    mae += abs(pred(i, k1, k2, k3) - y[i])
print(round(mae / n, 3))