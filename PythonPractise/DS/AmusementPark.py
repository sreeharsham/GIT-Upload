#!/bin/python3
# !/bin/python3

import math
import os
import random
import re
import sys


# Complete the minimumBribes function below.
def minimumBribes(q):
    bribe_val = 0
    i = 0
    act_arr = []
    bribe = 0
    for i in range(len(q)):
        act_arr.append(i + 1)
    #print(act_arr)
    actual = 0
    for j in range(len(q)):
        act_pos = j + 1
        print(q[j], act_pos, abs(q[j] - act_pos))
        if abs(q[j] - act_pos) > 2:
            # print("Too chaotic")
            # bribe_val = -1
            # break
            return ("Too chaotic")
        actual = (q[j] - act_pos)
        if actual > 0:
            bribe += actual
    print(bribe)



if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)

'''
import math
import os
import random
import re
import sys


# Complete the minimumBribes function below.
def minimumBribes(q):
    i = 0
    new_list = []
    while i < len(q):
        act_ind = i + 1
        # print(q[i], act_ind, abs(q[i] - act_ind) )
        if abs(q[i] - act_ind) > 2:
            return 'Too chaotic'
        else:
            new_list.append(abs(q[i] - act_ind))
        i += 1
    return (sum(set(new_list)))


if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
'''