#include <stdio.h>

struct job
{
    int id;
    struct job *next;
    int artime;
    int btime;
    int priority;
} typedef struct job jode;
typedef jode *jobptr;
Nodeptr head = NULL;
Nodeptr tail = NULL;

int main()
{
    SJF(arrivalqueue());

    return 0;
}

void enqueue(jobptr j)
{
    if (head == NULL)
        head = j;
    tail = j;
}
else
{
    tail->next = j;
    tail = node;
}
}

void dequeue()
{
    if (head != NULL)
    {
        jobptr temp = head;
        head = temp->next;
        temp->next = NULL;
    }
}

int peek()
{
    if (front != NULL)
        return front->id;
    else
        exit(EXIT_FAILURE);
}

jobptr[] arrivalqueue()
{
    int id[] = {0, 1, 2};
    int artime[] = {0, 0, 0};
    int bursttime[] = {24, 3, 3};
    int priority[] = {1, 1, 1};

    jobptr j1;
    j1 = malloc(sizeof(job));
    strcpy(j1->artime, 0);
    strcpy(j1->id, 0);
    strcpy(j1->priority, 1);
    strcpy(j1->btime, 24);

    jobptr j2;
    j2 = malloc(sizeof(job));
    strcpy(j2->artime, 0);
    strcpy(j2->id, 1);
    strcpy(j2->priority, 1);
    strcpy(j2->btime, 3);

    jobptr j3;
    j3 = malloc(sizeof(job));
    strcpy(j3->artime, 0);
    strcpy(j3->id, 2);
    strcpy(j3->priority, 1);
    strcpy(j3->btime, 3);

    q[] = { j1,
            j2,
            j3 }

    return q[];
}

void SJF(jobptr j[])
{
    int b0 = j[0]->btime;
    int b1 = j[1]->btime;
    int b2 = j[2]->btime;

    if (b0 <= b1 && b0 <= b2)
    {
        if (b1 <= b2)
        {
            enqueue(j[0]);
            enqueue(j[1]);
            enqueue(j[2]);
        }
        else
        {
            enqueue(j[0]);
            enqueue(j[1]);
            enqueue(j[2]);
        }
    }
    else if (b1 <= b0 && b1 <= b2)
    {
        if (b0 <= b2)
        {
            enqueue(j[1]);
            enqueue(j[0]);
            enqueue(j[2]);
        }
        else
        {
            enqueue(j[1]);
            enqueue(j[2]);
            enqueue(j[0]);
        }
    }
    else
    {
        if (b0 <= b1)
        {
            enqueue(j[2]);
            enqueue(j[0]);
            enqueue(j[1]);
        }
        else
        {
            enqueue(j[2]);
            enqueue(j[1]);
            enqueue(j[0]);
        }
    }

    int wait[3];
    int turnaround[3];
    int currenttime = 0;

    for (int i = 0; i < 4; i++)
    {
        int currentjob = peek();
        int btime = j[currentjob]->btime;
        printf("Job %d started\n", currentjob);
        sleep(btime);
        wait[currentjob] = currenttime;
        currenttime += btime
        dequeue();
        printf("Job %d is done\n", currentjob);
        turnaround[currentjob] = btime + wait[currentjob];
    }

    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (int i = 0, i < 4, i++)
    {
        printf("%d\twait[%d]\tturnaround[%d]\n", i, i, i)
    }
}

