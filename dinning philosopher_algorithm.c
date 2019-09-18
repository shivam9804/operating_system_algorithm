/* Shivam Singh AU17B1017
Assignmnet 4
Philosopher Dinning Problem */

#include<stdio.h>
#include<stdlib.h>

int main(){
    int p[]={0,0,0,0,0};        /* philosopher array */
    int f[]={0,0,0,0,0};        /* fork array */
    int i,m=5,phil=0;           /* variable for loop counter */

    while(phil < 5){            /* loop running until it is all philosopher complete eating */
        for(i = 0; i < m; i++){
            if(p[i] != 1){      /* checking the which philosopher is finished eating */
                if(i+4 < m){    
                    if(f[i] != 1 && f[i+4] != 1){/* checking whether the forks are available or not */
                        p[i] = 1;                /* assigning philosopher a id after the finish eating */   
                        f[i] = 1;                /* assigning fork a id to understand that they are in use  */   
                        f[i+4] = 1;
                        printf("\nPhilosopher%d is eating",i);
                        phil++;                  /* counting the number of philosopher */ 
                    }
                }
                else if(i+4 >= m){
                    if(f[i-1] == 0 && f[i] == 0){
                        p[i] = 1;
                        f[i] = 1;
                        f[i-1] = 1;
                        printf("\nPhilosopher%d is eating",i);
                        phil++;
                    }
                }
            }
        }
        for (int k = 0; k < m; k++){        /* assigning the fork to 0 to signify that the resurces are avilable now and can be aquired by the other philosopher */
            f[k]=0;
        }
    }   
    return 0;
}