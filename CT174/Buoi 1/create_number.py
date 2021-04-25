import random
import os 
L = []
n = 10
os.remove("test.inp")
for i in range(n):
    L.append(random.randint(0,20))
set_number = L
print(set_number)

with open("test.inp", "a") as wf:
    wf.write(str(len(set_number)) + "\n")
    for i in set_number:
        wf.write(str(i))
        wf.write("\n")
