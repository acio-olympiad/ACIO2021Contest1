import random
import sys
import math

minn, maxn, mink, maxk, maxp, Q, casetype, casenum = [int(x) for x in sys.argv[1:]]
# Case type 0: completely random
# Case type 1: exponential decay
# Case type 2: uniform

random.seed(casenum * 37 + 1000000007)
N = random.randint(minn, maxn)
K = random.randint(mink, maxk)

# Good for big K
def completely_random():
    res = []
    for _ in range(N):
        res.append(random.randint(0, maxp))
    return res

# Good for small K
def exponential_decay():
    res = []
    res.append(maxp)
    for _ in range(N-1):
        if res[-1] > min(10, maxp):
            res.append(math.ceil(res[-1] * (0.2 + random.random() * 0.4)))
        else:
            res.append(random.randint(0, min(10, maxp)))
    return res

# Obligatory
def uniform():
    res = []
    for _ in range(N):
        res.append(maxp)
    return res

pc = []
if casetype == 0:
    pc = completely_random()
elif casetype == 1:
    pc = exponential_decay()
else:
    pc = uniform()

qu = []

for _ in range(Q):
    qu.append((random.randint(0, maxp), random.randint(1, N)))

print(N, K, Q)

assert len(pc) == N
random.shuffle(pc)

print(" ".join(map(str, pc)))
for a, b in qu:
    print(a, b)
