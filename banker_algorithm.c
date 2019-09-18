/* Shivam Singh(AU17B1017) 
Algorithm name: Banker Algorithm*/


#include<stdio.h>

int work(int *need, int *available, int *allocate, int n, int m){
    int counter = 0;
    int process = 0;
    while (process < n){
      for (int i = 0; i < n; i++){
        if(*((need+i*m)) != -1){                       /* to check if the process is already executed or not */               
            for (int j = 0; j < m; j++){
                if(*((need+i*m)+j) <= *((available+j))){ /* for comapring every value of need and available array */
                    counter++;                            /* to keep track of if all the value are small */
                }
            }
            if(counter == m){                              /* if the counter is equal to process  then print */   
                printf("->p%d",i);
                process++;                                /* to keep runnig the loop until every execution is done */  
                for(int k = 0; k < m; k++){
                    *((available+k))+=*((allocate+i*m)+k); /* leaving the resouces after utilising */
                }
                *((need+i*m)) = -1;                         /* tag given to the process after execution */
            }
          counter = 0;                                      /* to refresh counter everytime it comes out of the loop */            
          }
      }
    }
    printf("\n");
}

int main(){
    int n,m;
    printf("Enter the number of processes: ");
    scanf(" %d", &n);
    printf("How many types of resources are there? ");
    scanf("%d", &m);
    int allocate[n][m];
    int max[n][m];
    int available[m];
    int need[n][m];

    for (int i = 0; i < n; i++){
        printf("Enter the allocation value taken by process p%d: ", i);
        for (int j = 0; j < m; j++){
            scanf("%d", &allocate[i][j]);
        }
    }
    for (int i = 0; i < n; i++){
        printf("Enter the max value taken by process p%d: ", i);
        for (int j = 0; j < m; j++){
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the available resources: \n");
    for(int i = 0; i < m; i++){
        scanf("%d", &available[i]);
    }
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            need[i][j] = max[i][j] - allocate[i][j];
        }
    }
    printf("\n");
    work((int *)need,(int *)available,(int *)allocate,n,m);
    return 0;
}