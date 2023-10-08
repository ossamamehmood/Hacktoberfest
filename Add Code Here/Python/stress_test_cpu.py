import os
import sys

CPU_CORES=8
while True:
    for j in range(CPU_CORES):
        parent = os.fork()
        if not parent:
            n = 0
            for i in range(10000):
                n += 1
            sys.exit(0)
    for j in range(CPU_CORES):
        os.wait()
