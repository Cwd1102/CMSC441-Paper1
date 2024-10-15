#include <iostream>
#include <chrono>
#include <vector>
#include <stack>
using namespace std;
 
char stacks[]={'S', 'A', 'D'};
vector<stack<int>> pile(3); // 3 pile for 3 stackss

void move(int a, int b){
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
    int counter = 0;
    vector<float> time;
    int input[] = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};

        for (int i = 0; i < sizeof(input)/sizeof(input[0]); i++){

            auto start = chrono::steady_clock::now();
            towerOfHanoi(input[i]);
            pile.clear();
            pile.resize(3);
            auto end = chrono::steady_clock::now();
            float timeTaken = chrono::duration_cast<chrono::milliseconds>(end - start).count();
            time.push_back(timeTaken);
        }

         for (int x : time){
            
            cout << "Time taken for " << input[counter] << " disks: " << x << " milliseconds" << endl;
            counter++;
         }

    return 0;

}