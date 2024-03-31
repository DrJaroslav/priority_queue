#include <stdio.h>
#include "priorityqueue.h"

int main(){

    PQueue* pq1 = create();
    insert(pq1, 8, 3);
    insert(pq1, 5, 1);
    insert(pq1, 7, 2);

    PQueue* pq2 = create();
    insert(pq2, 3, 1);
    insert(pq2, 9, 5);
    insert(pq2, 2, 4);

    PQueue* pq3 = join(pq1, pq2);

    while(!isEmpty(pq1)){
        printf("%d ", peek(pq1));
        pop(pq1);
    } printf("\n");

    while(!isEmpty(pq2)){
        printf("%d ", peek(pq2));
        pop(pq2);
    } printf("\n");

    while(!isEmpty(pq3)){
        printf("%d ", peek(pq3));
        pop(pq3);
    } printf("\n");

    return 0;
}