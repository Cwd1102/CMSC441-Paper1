import time

File=open("output.txt",'w')

def TowerOfHanoi(n, tower1, tower3, tower2):
    if n == 0:
        return
    TowerOfHanoi(n-1, tower1, tower2, tower3)
    print("Move disk", n, "from rod", tower1, "to rod", tower3, "\n")
    output = "Move disk " + str(n) + " from rod " + str(tower1) + " to rod " + str(tower3) +"\n"
    TowerOfHanoi(n-1, tower2, tower3, tower1)

runtime = A[3,6,9,13,16,19,22,23]

for i in range(len(runtime)):
    start=time.time()
    TowerOfHanoi(runtime[i], 'A', 'C', 'B')
    end=time.time()
    File.write("Time took " + str(end-start) + " Seconds\n")
    print("Time took ", end-start, " Seconds :3")
File.close()