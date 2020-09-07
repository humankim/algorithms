#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN ((int)1e4)
int N;
int cmd[MAXN + 10];
int data[MAXN + 10];
int stack[MAXN + 10];
int sp;

int top = -1;
int empty()
{
    return sp == 0;
}
int size()
{
    return sp;
}
void Push(int d)
{
    stack[++sp] = d;
}
int Top()
{
    return stack[sp];
}
void Pop()
{
    sp--;
}
void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &cmd[i]); //cin >> cmd[i];
        if (cmd[i] == 1)
            cin >> data[i];
    }
}
void Solve()
{
    for (int i = 0; i < N; i++)
    {
        if (cmd[i] == 1)
        {
            Push(data[i]);
        }
        else if (cmd[i] == 0)
        {
            if (empty())
                printf("E\n");
            else
            {
                printf("%d\n", Top());
                Pop();
            }
        }
        else if (cmd[i] == 2)
        {
            printf("%d\n", size());
        }
    }
}

int main()
{
    InputData();
    Solve();
    return 0;
}