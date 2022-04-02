n, m = map(int, input().split())
d = [0] * (n+1)
for iv in range(m):
    l, r, c = map(int, input().split())
    for day_of_iv in range(l, r+1):
        if c > d[day_of_iv]:
            d[day_of_iv] = c
print(sum(d))
