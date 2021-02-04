import os

cnt = 1

def make_case(minn, maxn, mink, maxk, maxp, Q, casetype):
    global cnt
    cmd = "python3 gen/gen.py %d %d %d %d %d %d %d %d > %d.in" % \
          (minn, maxn, mink, maxk, maxp, Q, casetype, cnt, cnt)
    print(cmd)
    os.system(cmd)
    cnt += 1

# Min case
make_case(2, 2, 2, 2, 1000, 0, 0)

# Curry with bigger bounds
for _ in range(10):
    make_case(3, 3, 2, 2, 1000000000, 0, 0)

# 1 garbage uniform case
make_case(990, 1000, 15, 100, 379, 0, 2)

# lowk with K = 2
for _ in range(20):
    make_case(99990, 100000, 2, 2, 1000000000, 0, 1)

# lowk with N <= 1000 and maxp 1000
for _ in range(10):
    make_case(990, 1000, 3, 10, 1000, 0, 1)

# highk with N <= 1000 and maxp 1000
for _ in range(10):
    make_case(990, 1000, 100, 1000, 1000, 0, 0)

# lowk with maxp 100000
for _ in range(10):
    make_case(99990, 100000, 3, 10, 100000, 0, 1)

# highk with maxp 100000
for _ in range(10):
    make_case(99990, 100000, 10000, 100000, 100000, 0, 0)

# lowk
for _ in range(5):
    make_case(99990, 100000, 3, 10, 1000000000, 0, 1)

# highk
for _ in range(5):
    make_case(99990, 100000, 10000, 100000, 1000000000, 0, 0)

# lowk with queries with maxp 100000
for _ in range(10):
    make_case(99990, 100000, 3, 10, 100000, 100000, 1)

# highk with queries with maxp 100000
for _ in range(10):
    make_case(99990, 100000, 10000, 100000, 100000, 100000, 0)

# lowk with queries
for _ in range(5):
    make_case(99990, 100000, 3, 10, 1000000000, 100000, 1)

# highk with queries
for _ in range(5):
    make_case(99990, 100000, 10000, 100000, 1000000000, 100000, 0)
