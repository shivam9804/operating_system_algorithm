#include<stdlib.h>
#include<stdio.h>

int underflow();

/* struct for creating list to store data */
struct linear_queue{
    int info;
    struct linear_queue *next;
}*front,*rear,*newnode,*ptr;

/* global number of process length */
int pn;

/* functionn declared  for calculation and performing queue operation*/
void cal(int a, int bt[], int qt, int at[], int sum);
int enqueue(int a);
int dequeue();

/* main function*/
void main(){
    int sum=0,atv, btv, qt, max=0;
    printf("Enter the quantum time: ");
    scanf(" %d", &qt);
    printf("Enter the number of processes: ");
    scanf(" %d", &pn);
    
    /* user defined array for arrival time and burst time */
    int at[pn], bt[pn];
    for(int i = 0; i<pn; i++){
        /* taking input for arrival time and burst time */
        printf("Enter arrival time and burst time for process%d: ",i+1); 
        scanf(" %d", &atv);
        at[i]=atv;
        scanf(" %d", &btv);
        bt[i]=btv;
        /* sum for running the first for-loop in the cal function  */
        sum+=bt[i];
    }
    /* printing the  table for intial input takne from the user */
    printf("Processes \tArrival time \tBurst time");
    for(int i = 0; i < pn; i++){
        printf("\nprocess%d \t%d \t\t%d\n",i+1,at[i],bt[i]);
    }
    /* cal() function called */
    cal(pn,bt,qt,at,sum);
}

void cal(int a, int bt[], int qt, int at[], int sum){
    int t,counter=0;    
    for(int i = 0; i < sum;){
        while(at[counter] <= i && counter < a && bt[counter] > 0){    
            enqueue(counter);
            counter++;  
        }
        if(underflow() == 1){
            t=dequeue();
        }
        if(bt[t] <= qt && bt[t] > 0){
            i+=bt[t];
            while(at[counter] <= i && counter < a && bt[counter] > 0){    
                enqueue(counter);
                counter++;  
            }
            bt[t]=0;
        }
        else if (bt[t] > qt){
            bt[t]-=qt;
            i+=qt;
            while(at[counter] <= i && counter < a && bt[counter] > 0){    
                enqueue(counter);
                counter++;  
            }
            if(bt[t] > 0){
                enqueue(t);
            }
        }
        /* printing the process number and their end time */
        
        printf("\tProcess%d", t);
        printf("\tTime Slice: %d", i);
        printf("\n");
    }
}

/* function for enqueing the number in the que */
int enqueue(int b){
    newnode=(struct linear_queue*)malloc(sizeof(struct linear_queue));
    newnode->info=b;
    if((front==NULL)&&(rear==NULL)){
        front=newnode;
        rear=newnode;
        newnode->next=NULL;
    }
    else{
        rear->next=newnode;
        newnode->next=NULL;
        rear=newnode;
    }
}
/* function for dqueing the number from the que */
int dequeue(){
    int x;
    if(front==rear){
        x = front->info;
        front=NULL;
        rear=NULL;
    }
    else{
        x = front->info;
        front=front->next;
    }
    return x;
}
/* function to check the underflow in the que*/
int underflow(){
    if((front==NULL)&&(rear==NULL)){
        return(0);
    }
    else{
        return(1);
    }
}
