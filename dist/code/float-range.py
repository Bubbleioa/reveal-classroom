import random
import struct
from time import time

import matplotlib.pyplot as plt


def float_to_bin(num):
    return bin(struct.unpack('!I', struct.pack('!f', num))[0])[2:].zfill(32)

def bin_to_float(binary):
    return struct.unpack('!f',struct.pack('!I', int(binary, 2)))[0]

INT_MAX = 2 ** 31 - 1
TIMES = 2 ** 22

x = []
random.seed(time())
for i in range(TIMES):
    x.append(bin_to_float(bin(random.randint(0, INT_MAX))))

plt.figure(2)
plt.hist(x, bins = 200, log = True, histtype='barstacked')
plt.show()
# plt.show()
