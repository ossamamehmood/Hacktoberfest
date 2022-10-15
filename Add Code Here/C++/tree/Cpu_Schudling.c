//CPU Scheduling algorithms
//FCFS
//SJF
//ROund Robin
//Priority

#include <stdio.h>
#define max 10
struct process
{
    int pid;      //process id
    int bt;       //burst time
    int tt;       //turnaround time
    int wt;       //waiting time
    int priority; //priority
    int rt;       //remaining time
} p[max], q[max], tem;
int n, temp[max], tempq, c = 0, pos;
float avgw = 0, avgt = 0;
void display(struct process p[])
{
    int i;
    printf("\nProcess\t Burst time\t Turnaround time\t Waiting time");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t %d\t\t%d\t\t\t%d", p[i].pid, p[i].bt, p[i].tt, p[i].wt);
    }
    printf("\nAverage waiting time %f", avgw);
    printf("\nAverage Turnaround time %f", avgt);
}
void fcfs(struct process p[])
{
    avgw = 0, avgt = 0;
    int i;
    p[0].wt = 0;
    for (i = 0; i < n; i++)
    {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tt = p[i].wt + p[i].bt;
        avgw = avgw + p[i].wt;
        avgt = avgt + p[i].tt;
    }
    avgw = avgw / n;
    avgt = avgt / n;
    display(p);
}
void sjf()
{
    int i, j;
    for (i = 0; i < n; i++)
        q[i] = p[i];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (q[j].bt > q[j + 1].bt)
            {
                tem = q[j];
                q[j] = q[j + 1];
                q[j + 1] = tem;
            }
        }
    }

    fcfs(q);
}
void rr()
{
    avgw = 0, avgt = 0;
    int i, qt, ready[100];
    int front = 0, rear = n - 1;
    int time = 0;
    printf("Enter the time quantum : ");
    scanf("%d", &qt);
    for (i = 0; i < n; i++)
        ready[i] = i;
    printf("\nSequence: ");
    while (front == 0 || front <= rear)
    {
        if (p[ready[front]].rt > qt)
        {
            p[ready[front]].rt = p[ready[front]].rt - qt;
            ready[++rear] = ready[front];
            printf(" %d--", p[ready[front]].pid);
            front++;
            time += qt;
        }
        else
        {
            printf(" %d--", p[ready[front]].pid);
            time += p[ready[front]].rt;
            p[ready[front]].tt = time;
            p[ready[front]].rt = 0;
            ++front;
        }
    }
    printf("End");
    for (i = 0; i < n; i++)
    {
        p[i].wt = p[i].tt - p[i].bt;
        avgw = avgw + p[i].wt;
        avgt = avgt + p[i].tt;
    }
    avgw = avgw / n;
    avgt = avgt / n;
    display(p);
}

void pnp()
{
    int i, j;
    for (i = 0; i < n; i++)
        q[i] = p[i];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {

            if (q[j].priority > q[j + 1].priority)
            {
                tem = q[j];
                q[j] = q[j + 1];
                q[j + 1] = tem;
            }
        }
    }
    fcfs(q);
}
void main()
{
    int ch, ans, i = 0, j;
    char cho;
    printf("\n Enter number of process: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("\n Enter burst time of process %d= ", i + 1);
        scanf("%d", &p[i].bt);
        printf("\n Enter priority of process %d= ", i + 1);
        scanf("%d", &p[i].priority);
        p[i].rt = p[i].bt;
    }
    do
    {
        printf("\t\tMENU\n 1)FCFS \n 2)SJF \n 3)Round Robin \n 4)Priority \n Enter your choice : ");
        scanf("%d", &ch);
        if (ch == 1)
            fcfs(p);
        else if (ch == 2)
            sjf();
        else if (ch == 3)
            rr();
        else if (ch == 4)
            pnp();
        else
            printf("\nEnter a valid option");
        printf("\nDo you want to continue? ");
        scanf("%s", &cho);
    } while (cho == 'y' || cho == 'Y');
}
