#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct fcfs//structure
{
    int p_id;
    int at;
    int bt;
    int wt;
    int tat;
    struct fcfs* next;
};

void create_list_processes(struct fcfs* node)//creating of all the processes
{
    int i;
    int i1 = 1;
    printf("\n Enter the id of the process in the node: ");
    scanf("%d", &node->p_id);
    printf("\n Enter the arrival time in the node : ");
    scanf("%d", &node->at);
    printf("\n Enter the burst time in the node : ");
    scanf("%d", &node->bt);
    printf("\n Enter 0 to stop or any number to continue : ");
    scanf("%d", &i);
    node->tat = 0;
    node->wt = 0;
    node->next = NULL;
    while (i != 0)
    {
        i1++;
        node->next = (struct fcfs *)malloc(sizeof(struct fcfs));
        node = node->next;
        printf("\n Enter the id of the process in the node : ");
        scanf("%d", &node->p_id);
        printf("\n Enter the arrival time in the node : ");
        scanf("%d", &node->at);
        printf("\n Enter the burst time in the node : ");
        scanf("%d", &node->bt);
        node->tat = 0;
        node->wt = 0;
        node->next = NULL;
        printf("\n Enter 0 to stop or any number to continue entering more processes : ");//DMA
        scanf("%d", &i);
    }
    printf("The total number of processes are: %d\n", i1);
}

void calculate_time(struct fcfs* node) 
{
    int ct = 0; 
    while (node != NULL) {
        if (ct > node->at)   
        {
            node->wt=(ct - node->at);//calculating the wait time
        }     
        else
        {
            node->wt=0;
        }
        ct = ct+ node->bt; //calculating completion time of each process
        node->tat = ct - node->at;//calculating the TAT
        node = node->next;
    }
}

void display(struct fcfs* node) 
{
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    while (node != NULL) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", node->p_id, node->at, node->bt, node->wt, node->tat);//printing
        node = node->next;
    }
}
void display_avg(struct fcfs* node) 
{
    int i;
    double avg_wt=0.0;
    double avg_tat=0.0;
    double tot_wt=0.0;
    double tot_tat=0.0;
    while (node != NULL)
   {
      avg_wt = avg_wt + node->wt;
      avg_tat = avg_tat + node->tat;
      i++;
      node = node->next; 
   }
   tot_wt= avg_wt/i;
   tot_tat= avg_tat/i;
   printf("The total average waiting time is: %f", tot_wt);
   printf("The total average turn around time is: %f", tot_tat);
}

int main()
{
    struct fcfs *node;
    node = (struct fcfs *)malloc(sizeof(struct fcfs));
    if (node == NULL)
    { 
        printf("\n Memory not allocated ");
        exit(0);
    }
    create_list_processes(node);
    calculate_time(node);
    display(node);
    display_avg(node);
    return 0;
}

