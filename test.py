#!/usr/bin/env python
import commands
import os
import urllib
import random
import ssl
ssl._create_default_https_context = ssl._create_unverified_context
def download():
    url_src = 'https://s3-us-west-2.amazonaws.com/blanknoweb.com/src.cpp'
    url_std = 'https://s3-us-west-2.amazonaws.com/blanknoweb.com/std.cpp'
    urllib.urlretrieve(url_src, '/home/src.cpp')
    urllib.urlretrieve(url_std, '/home/std.cpp')

def compiles():
    std1, std2 = commands.getstatusoutput('g++ /home/std.cpp -o /home/std -std=c++11')
    src1, src2 = commands.getstatusoutput('g++ /home/src.cpp -o /home/src -std=c++11')
    if int(src1) != 0:
        return False
    else:
        return True

def gen_data():
    count = random.randint(1, 49)
    f = open('tmp.txt', mode='w')
    data = []
    for i in range(count):
        data.append(random.randint(1,2))
    data.append(0)
    f.write(' '.join(map(str,data)))
    f.close()
    return data

def compare():
    m = 50
    for i in range(m):
        gen_data()
        std1, std2 = commands.getstatusoutput('/home/std < tmp.txt')
        res1, res2 = commands.getstatusoutput('/home/src < tmp.txt')
        if int(res1) != 0:
            return False
        if int(std2) != int(res2):
            return False
    return True

download()
if compiles():
    print(compare())
else:
    print('compile error')
