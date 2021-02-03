import sys
import random

minn, maxn, maxl, maxw, maxh, counter = list(map(int, sys.argv[1:]))

random.seed(counter * 17 + 998244353)

N = random.randint(minn, maxn)
print(N)
for i in range(N):
    l = random.randint(1, maxl)
    w = random.randint(1, maxw)
    h = random.randint(1, maxh)
    print(l, w, h)
