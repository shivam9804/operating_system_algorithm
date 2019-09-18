#include<stdio.h>

int cal(int x, int y, int pn[], int fs[]) {
    int pt, hit = 0, pf = 0, counter = 0;
    for (int i = 0; i < x; i++) {
        /* main loop runs for  until all the pages are done*/
        if (fs[i] == -1 && i < y) {
            /* intiallt whole array of frame cotains to -1 to signify its empty */
            fs[i] = pn[i]; /*  if the array contains -1 then replaces is with page number*/
            pt = 0; /* this points the value that has to exit once the array is full */
            pf++; /* this counts page fault */
        } else {
            counter = 0;
            for (int j = 0; j < y; j++) {
                if (fs[j] == pn[i]) {
                    printf("\n  %d , %d ", fs[j], pn[i]); /* prints the array where hits happens */
                    hit++; /* this counts the number of hits */
                } else {
                    counter++; /* counter to check loop condition */
                }
            }
            if (counter == y) {
                /* if counter is equals to y then assign the new value to f[n] index*/
                fs[pt] = pn[i];
                pt++;
                pf++;
            }
        }
        if (pt > y) {
            /* if p is greater then the frame index then p = 0 */
            printf("%d", pn[i + 1]);
            pt = 0;
        }
        printf("\n");
        for (int k = 0; k < 4; k++) {
            /* prints the frame array */
            printf("\t %d", fs[k]);
        }
        printf("\n");
    }
    printf("\nPage-fault: %d", pf); /* prints the hits and pagef-ault*/
    printf("\nHit       : %d", hit);
    printf("\n");

}

int main() {
    int x, y;
    printf("Enter the number of page: "); /*asks user the number of the pages */
    scanf("%d", & x);
    int pn[x];
    printf("Enter the page number: "); /* asks user the page number */
    for (int i = 0; i < x; i++) {
        scanf("\n%d", & pn[i]);
    }
    printf("Enter the frame size: "); /* asks the frame size */
    scanf("%d", & y);
    int fs[y];
    for (int j = 0; j < y; j++) {
        fs[j] = -1;
    }
    cal(x, y, pn, fs); /* sends the variable and array for furhter function */
    return 0;
}