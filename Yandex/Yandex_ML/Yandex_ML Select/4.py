def max_eaten(n, k):
    if k == 0:
        return n
    elif k > n:
        return 0
    else:
        res = 0
        while (n > k):
            sut = n // (k + 1)
            res += sut
            n -= sut * k
        return res


n, k = map(int, input().split())
print(max_eaten(n, k))
