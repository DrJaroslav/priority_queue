#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

typedef struct node Node;

typedef struct pQueue PQueue;

PQueue* create();                           //sukurti tuščią prioritetinę eilę 

int     isFull();                           //nustatyti, ar eilė pilna: 1 = true, 0 = false

int     isEmpty(PQueue* ptr);               //nustatyti, ar eilė tuščia: 1 = true, 0 = false

void    insert(PQueue* ptr, int d, int p);  //įdėti naują elementą

void    pop(PQueue* ptr);                   //išmesti elementą su didžiausiu prioritetu 

int     peek(PQueue* ptr);                  //grąžinti elemento su aukščiausiu prioritetu reikšmę

PQueue* join(PQueue* ptr1, PQueue* ptr2);   //sujungti dvi prioritetines eiles į vieną

#endif //PRIORITYQUEUE_H