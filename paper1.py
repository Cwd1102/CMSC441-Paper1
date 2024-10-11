import time

File=open("output.txt",'w')

def TowerOfHanoi(n, tower1, tower3, tower2):
    if n == 0:
        return
    TowerOfHanoi(n-1, tower1, tower2, tower3)
    print("Move disk", n, "from rod", tower1, "to rod", tower3, "\n")
    output = "Move disk " + str(n) + " from rod " + str(tower1) + " to rod " + str(tower3) +"\n"
    TowerOfHanoi(n-1, tower2, tower3, tower1)

for i in range(1, 22):
    start=time.time()
    TowerOfHanoi(i, 'A', 'C', 'B')
    end=time.time()
    File.write("Time took " + str(end-start) + " Seconds\n")
    print("Time took ", end-start, " Seconds :3")
File.close()