#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN ((int)1e4)
int N;
int cmd[MAXN + 10];
int data[MAXN + 10];
int que[MAXN + 10];
int wp, rp;

int top = -1;
int empty()
{
    return wp == rp;
}
int size()
{
    return wp - rp;
}
void Push(int d)
{
    que[wp++] = d;
}
int front()
{
    return que[rp];
}
int back()
{
    return que[wp - 1];
}
void Pop()
{
    rp++;
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
        switch (cmd[i])
        {
        case 0:
            if (empty())
                printf("E\n");
            else
            {
                printf("%d\n", front());
                Pop();
            }
            break;
        case 1:
            Push(data[i]);
            break;
        case 2:
            printf("%d\n", size());
            break;
        }
    }
}

int main()
{
    InputData();
    Solve();
    return 0;
}