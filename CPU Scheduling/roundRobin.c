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
    RR(arrivalqueue(),2);

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

void RR(jobptr j[], int q)
{
    int timeleft[3];
    for (int i = 0, i < 4, i++)
    {
        timeleft[i] = j[i]->btime;
        enqueue(i);
    }

    while (timeleft[0] != 0 || timeleft[1] != 0 || timeleft[2] != 0)
    {
        int currentjob = peek();
        printf("Job %d started\n", currentjob);
        if (timeleft[currentjob] <= q)
        {
            sleep(timeleft[currentjob]);
            timeleft[currentjob] = 0;
            dequeue();
            printf("Job %d is done\n", currentjob);
        }
        else
        {
            timeleft[currentjob] -= q;
            sleep(q);
            dequeue();
            enqueue(job[currentjob]);
            printf("Job %d stoppef\n", currentjob);
        }
    }
}