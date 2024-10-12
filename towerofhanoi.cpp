#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;

void towerofhanoi(int n, char tower1, char tower3, char tower2) {
    if (n == 1) {
        cout << "Move disk 1 tower1 " << tower1 << " tower3 " << tower3 << endl;
        return;
    }
    towerofhanoi(n - 1, tower1, tower2, tower3);
    cout << "Move disk " << n << " tower1 " << tower1 << " tower3 " << tower3 << endl;
    towerofhanoi(n - 1, tower2, tower3, tower1);
}

int main() {
    ofstream myfile;
    int input[] = {10,13,15,19,20,23,25,26};

    myfile.open("output.txt");

    if (myfile.is_open()) {
        cout << "File is open" << endl;
        for (int i = 0; i < 8; i++) {
            auto start = chrono::steady_clock::now();
            cout << "For " << input[i] << " disks:" << endl;
            towerofhanoi(input[i], 'A', 'C', 'B');
            cout << endl;
            auto end = chrono::steady_clock::now();
            float time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
            myfile << "For " << input[i] << " disks: " << time << " miliseconds" << endl;
    }
    myfile.close();
    return 0;
    }
    else {
        cout << "File is not open" << endl;
    }
}


