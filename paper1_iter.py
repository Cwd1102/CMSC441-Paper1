import time

def tower_of_hanoi_iterative(n):
    # A, B, C are the names of the rods
    A, B, C = [], [], []

    # Initialize source rod A with disks (1 being the smallest disk on top)
    for disk in range(n, 0, -1):
        A.append(disk)

    # If number of disks is even, swap the destination (C) and auxiliary (B)
    if n % 2 == 0:
        B, C = C, B

    # Total number of moves required
    total_moves = 2 ** n - 1

    # Function to print the current move
    def print_move(from_rod, to_rod, disk):
        print(f"Move disk {disk} from {from_rod} to {to_rod}")

    # Function to move disk from one rod to another
    def move_between_rods(rod1, rod2, name1, name2):
        if not rod1:
            disk = rod2.pop()
            rod1.append(disk)
            print_move(name2, name1, disk)
        elif not rod2:
            disk = rod1.pop()
            rod2.append(disk)
            print_move(name1, name2, disk)
        elif rod1[-1] < rod2[-1]:
            disk = rod1.pop()
            rod2.append(disk)
            print_move(name1, name2, disk)
        else:
            disk = rod2.pop()
            rod1.append(disk)
            print_move(name2, name1, disk)

    # Loop through each move
    for move in range(1, total_moves + 1):
        if move % 3 == 1:
            move_between_rods(A, C, 'A', 'C')
        elif move % 3 == 2:
            move_between_rods(A, B, 'A', 'B')
        elif move % 3 == 0:
            move_between_rods(B, C, 'B', 'C')


if __name__ == "__main__":
    File=open("output.txt",'w')
    for i in range(1, 22):
        start=time.time()
        num_disks = i
        print(f"Solving Tower of Hanoi for {num_disks} disks:")
        tower_of_hanoi_iterative(num_disks)
        end=time.time()
        print("Time took ", end-start, " Seconds :3")
        File.write("Time took " + str(end-start) + " Seconds :3\n")
    File.close()