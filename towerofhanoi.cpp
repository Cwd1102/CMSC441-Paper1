#include <iostream>
#include <chrono>
using namespace std;

// Recursive function to solve Tower of Hanoi puzzle
// It moves n disks from tower1 to tower3 using tower2 as auxiliary
void towerofhanoi(int n, char tower1, char tower3, char tower2) {

    // Base case: If only 1 disk is present
    if (n == 1) {
        cout << "Move disk 1 tower1 " << tower1 << " tower3 " << tower3 << endl;
        return;
    }
    // Move top n-1 disks from tower1 to tower2 using tower3 as auxiliary
    towerofhanoi(n - 1, tower1, tower2, tower3);
    cout << "Move disk " << n << " tower1 " << tower1 << " tower3 " << tower3 << endl;
    // Move n-1 disks from tower2 to tower3 using tower1 as auxiliary
    towerofhanoi(n - 1, tower2, tower3, tower1);
}

// Driver code
int main() {
    // Number of disks
    int input[] = {10,13,15,19,20,23,25,26};
        
        //loops through the input array
        for (int i = 0; i < 8; i++) {
            //start the clock
            auto start = chrono::steady_clock::now();
            cout << "For " << input[i] << " disks:" << endl;
            // Function call
            // A, B and C are the tower names
            towerofhanoi(input[i], 'A', 'C', 'B');
            cout << endl;
            //end the clock
            auto end = chrono::steady_clock::now();
            //calculate the time
            //chrono::duration_cast is used to convert the time into milliseconds
            float time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
            cout << "For " << input[i] << " disks: " << time << " miliseconds" << endl;
    }
    return 0;
}


