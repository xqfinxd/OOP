#!/usr/bin/env python
import commands
import os
import random
def gen_data():
    count = random.random.randint(1, 49)
    f = open('tmp.txt', mode='w')
    data = []
    for i in range(count):
        data.append(random.randint(1,2))
    data.append(0)
    f.write(' '.join(data))
    f.close()
    return data

def compare():
    m = 50
    for i in range(m):
        gen_data()
        std1, std2 = getstatusoutput('./standard < tmp.txt')
        res1, res2 = getstatusoutput('./src < tmp.txt')
        if res1 != 0:
            return False
        if int(std2) != int(res2):
            return False
    return True

 print(companre())
