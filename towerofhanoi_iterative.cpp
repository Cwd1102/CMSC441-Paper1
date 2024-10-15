#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
 
char stacks[]={'S', 'A', 'D'};
vector<stack<int>> pile(3); // 3 pile for 3 stackss
 
void move(int a, int b)
{
    if (pile[b].empty() || (!pile[a].empty() && pile[a].top() < pile[b].top()))
    {
        cout << "Move disk " << pile[a].top() << " from stacks " << stacks[a] << " to stacks " << stacks[b] << "\n";
        pile[b].push(pile[a].top());
        pile[a].pop();
    }
    else
        move(b, a);
}
 
void towerOfHanoi(int n)
{
    cout << n << " disks:" << endl;
 
    int tower1 = 0, tower3 = 1, tower2 = 2;
    for (int i = n; i > 0; i--)
        pile[tower1].push(i);
 
    int total = (1 << n) - 1;
    if (n % 2 == 0)
        swap(tower3, tower2);
 
    for (int i = 1; i <= total; i++)
    {
        if (i % 3 == 0)
            move(tower3, tower2);
        else if (i % 3 == 1)
            move(tower1, tower2);
        else
            move(tower1, tower3);
    }
}

int main(){
    ofstream myfile;
    int input[] = {3,6,9,13,15,19,20,23,25,26};

    myfile.open("output.txt");

    if (myfile.is_open()) {
        cout << "File is open" << endl;
            auto start = chrono::steady_clock::now();
            towerOfHanoi(28);
            cout << endl;
            auto end = chrono::steady_clock::now();
            float time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
            myfile << time << " miliseconds" << endl;
    myfile.close();
    return 0;
    }
    else {
        cout << "File is not open" << endl;
    }

}