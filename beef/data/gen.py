"""

Subtask 1

N = 3, M = 2, a_i = 1
20x random a_i = 1

Subtask 2

10x random M = N-1

Subtask 3

10x random a_i = 5

Subtask 4

3x State explosion breaker N = 200
20x random N = 200

Subtask 5

3x State explosion breaker N = 1e5
10x random N = 1e5
"""
import random, os
Cases=[[]]

def addcase(n,m, s,t, name):
    Cases.append([n,m,s,t,random.randint(0,10**4)])

def subtask1():
    for i in range(2):
        addcase(3,2,1,1,"sub1-{}".format(i))
    for i in range(18):
        addcase(10**5, 2*10**5, 1, (i%4)+1,"sub1-{}".format(i+2))

def subtask2():
    for i in range(10):
        addcase(10**5, 10**5-1, 2, 4,"sub2-{}".format(i)) #tree and edges only

def subtask3():
    for i in range(10):
        addcase(10**5, 2*10**5, 3, (i%4)+1,"sub3-{}".format(i))

def subtask4():
    for i in range(20):
        addcase(200, random.randint(199, 5000), 4, (i%4)+1,"sub4-{}".format(i))

def subtask5():
    for i in range(20):
        addcase(10**5, 2*10**5, 5, (i%4)+1,"sub5-{}".format(i))

subtask1()
subtask2()
subtask3()
subtask4()
subtask5()

def make_cases():
    os.system("g++ tkgen_actual.cpp -O2 -o tkgen")
    for i in Cases:
        l = open("tmp.txt","w")
        l.write("{} {} {} {} {}".format(i[0],i[1],i[2],i[3],i[4]))
        l.close()
        os.system("./tkgen <{} >{}".format(i[5]+".in", i[5]+".out"))

        

make_cases()


