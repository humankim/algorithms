#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN (100)

int N;
//linear queue
int que[MAXN * 50];
int wp, rp;
void push(int d) { que[wp++] = d; }
int front() { return que[rp]; }
int back() { return que[wp - 1]; }
void pop() { rp++; }
int empty() { return wp == rp; }

void InputData()
{
    scanf("%d", &N);
}
void Solve()
{
    wp = rp = 0;
    for (int i = 1; i <= N; i++)
    {
        push(i);
    }
    for (int i = 0; i < N - 1; i++)
    {
        int cnt = back() / 2; //가장 밑에 있는 카드의 /2
        for (int k = 0; k < cnt; k++)
        {
            push(front());
            pop();
        }
        printf("%d ", front());
        pop();
    }
    printf("%d\n", front());
    pop();
}

int main(void)
{
    InputData();
    Solve();
    return 0;
}
