#include <stdio.h>
#include <stdlib.h>
#include "priorityqueue.h"

typedef struct node {
    int data;
    int priority;
    struct node* next;
} Node;

typedef struct pQueue {
    Node* next;
} PQueue;

PQueue* create(){                                       //grąžina rodyklę į atminties vietą, 
    PQueue*  ptr  = (PQueue*)malloc(sizeof(PQueue));    //kur lauke next bus saugoma rodyklė į elementą
    ptr -> next = NULL;                                 //su didžiasiu prioritetu

    return ptr;
}

Node* createNode(){
    Node*  ptr  = (Node*)malloc(sizeof(Node));
    ptr -> next = NULL;

    return ptr;
}

int isEmpty(PQueue* ptr){           //patikrina, ar yra rodyklė į elementą su didžiasiu prioritetu:
    return (ptr -> next) == NULL;   //nėra rodyklės => nėra elemento => tuščia eilė
}

void insert(PQueue* ptr, int d, int p){
    Node* newNode = createNode();
    newNode -> data     = d;
    newNode -> priority = p;

    if(isEmpty(ptr) == 1){
        ptr -> next = newNode;
    } else {
        Node* current_ptr = ptr -> next;
        Node* temp;
        int inserted = 0;

        while(inserted == 0){
            if((current_ptr -> priority) <= (newNode -> priority)){
                if((current_ptr -> next)!= NULL){
                    if((current_ptr -> next -> priority) <= (newNode -> priority)){
                        temp = current_ptr -> next;
                        current_ptr = temp;
                    } else {
                       newNode -> next = current_ptr -> next;
                       current_ptr -> next = newNode;
                       inserted = 1;
                    }
                } else {
                    current_ptr -> next = newNode;
                    inserted = 1;
                }
            } else {
                newNode -> next = ptr -> next;
                ptr -> next = newNode;
                inserted = 1;
            }
        }
    }
}

void pop(PQueue* ptr){
    if(isEmpty(ptr) == 1){
        printf("The queue is empty. There is nothing to remove.");
    } else {
        Node* head  = ptr -> next;
        ptr -> next = head -> next;
        free(head);
    }
}

int peek(PQueue* ptr){                      //grąžina elemento su didžiausiu prioritetu reikšmę
    return ptr -> next -> data;
}

PQueue* join(PQueue* ptr1, PQueue* ptr2){   //patikrina, kad pateiktos eilės nebūtų tuščios,
    PQueue* ptr = create();                 //prideda po vieną elementą iš pirmos eilės į naują eilę
    Node* current1 = ptr1 -> next;          //prideda po vieną elementą iš antros eilės į naują eilę
    Node* current2 = ptr2 -> next;
    Node* temp;

    if(isEmpty(ptr1) == 1 && isEmpty(ptr2) == 1){
        printf("The queues are empty. There is nothing to join.");
    } else {
        while(current1 != NULL){
            insert(ptr, current1 -> data, current1 -> priority);
            temp = current1 -> next;
            current1 = temp;
        }
        while(current2 != NULL){
            insert(ptr, current2 -> data, current2 -> priority);
            temp = current2 -> next;
            current2 = temp;
        }
    }

    return ptr;
}