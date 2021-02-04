import os

case = 1
hun = 100000
bil = 1000000000

def gen_case(minn, maxn, maxl, maxw, maxh):
    global case
    cmd = "python3 gen/gen.py %d %d %d %d %d %d > %d.in" % (minn, maxn, maxl, maxw, maxh, case, case)
    print(cmd)
    os.system(cmd)
    case += 1

# Subtask 1
gen_case(hun, hun, 1, 1, 1)
for _ in range(10):
    gen_case(1, hun, hun, 1, bil)

# Subtask 2
for _ in range(50):
    gen_case(6, 8, bil, bil, bil)

# Subtask 3
for _ in range(10):
    gen_case(290, 300, bil, 5, bil)
for _ in range(20):
    gen_case(290, 300, bil, bil, bil)

# Subtask 4
for _ in range(2):
    gen_case(1990, 2000, bil, 5, bil)
for _ in range(10):
    gen_case(1990, 2000, bil, bil, bil)

# Subtask 5
gen_case(99990, hun, bil, 5, bil)
for _ in range(5):
    gen_case(99990, hun, bil, bil, bil)
